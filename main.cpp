#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>

#include <string>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

#include "antsim.h"
#include "antobj.h"

void saveMatrix(string filename, int** matrix, int rows, int cols) {

	ofstream myfile;
	myfile.open (filename, ios::out | ios::app | ios::binary);

	cout << "Saving to file: " << filename << endl;

	// Push matrix contents to file in comma separated format
	for (int i=0; i<rows; ++i) {
		for (int j=0; j<cols; ++j) {
			if (j<cols-1) {
				myfile << matrix[i][j] <<", ";
			} else {
				myfile << matrix[i][j];
			}
		}
		myfile << "\n";
	}
	myfile << "\n";

	myfile.close();
}

int main() {

	int nsteps = 300;

	// 1) Define matrix
	int m_rows = 100, m_cols = 100;
	cout << "Defined matrix: " << m_rows << "x" << m_cols << endl;

	// 2) Generate Ants
	int nants = 100;
	vector<int> locAll = {40,60};
	Ant antarr[nants];
	cout << "Generated ants: " << nants << endl;
	for (int i=0; i<nants; ++i) {
		antarr[i].setType(1);
		antarr[i].setLocation(locAll);
	}
	cout << endl;
	for (int i=0; i<nants; ++i) {
		antarr[i].printAntInfo();
	}
	cout << endl;

	// 3) Generate initial empty matrix
	int** matrix = generateMatrix(m_rows, m_cols);
	int array[m_rows*m_cols] = {};
	populateMatrix(matrix, m_rows, m_cols, array, m_rows*m_cols);

	// 4) Populate inital matrix with ants
	for (int i=0; i<nants; ++i) {
		vector<int> loc (2,0);
		for (int j=0; j<2; ++j) {
			loc[j] = antarr[i].getLocation()[j];
		}
		++matrix[loc[0]][loc[1]];
	}
	cout << "Initial matrix: " << endl;
	printMatrix(matrix, m_rows, m_cols);

	// Save initial matrix to file
	string filename = "testsavefile.txt";
	ofstream myfile;
	myfile.open(filename, ios::out | ios::trunc);
	myfile.close();
	saveMatrix(filename, matrix, m_rows, m_cols);

	// 4) Iterate over time steps
	// random seed
	srand(time(NULL));
	for (int t=0; t<nsteps; ++t) {

		// Generate matrix
		int** newMatrix = generateMatrix(m_rows, m_cols);
		int newArray[m_rows*m_cols] = {};
		populateMatrix(newMatrix, m_rows, m_cols, newArray, m_rows*m_cols);

		// Time step the ants
		for (int i=0; i<nants; ++i) {
			vector<int> loc (2,0);
			for (int j=0; j<2; ++j) {
				loc[j] = antarr[i].getLocation()[j];
			}

			antarr[i].changeDirection(rand()%5);

			int direction = antarr[i].getDirection();
			if (direction==0) { 
				// Stay still for direction 0.
			} else if (direction==1) {
				++loc[1];
			} else if (direction==2) {
				++loc[0];
			} else if (direction==3) {
				--loc[1];
			} else if (direction==4) {
				--loc[0];
			}

			// Prevent steps from going outside matrix
			// 	If asked to go outside, the ant doesn't move
			if (loc[0]==-1) {
				loc[0]=0;
			} else if (loc[0]==m_rows) {
				loc[0]=m_rows-1;
			}
			if (loc[1]==-1) {
				loc[1]=0;
			} else if (loc[1]==m_cols) {
				loc[1]=m_cols-1;
			}

			antarr[i].setLocation(loc);
		}

		// Populate new matrix
		for (int i=0; i<nants; ++i) {
			int loc[] = {};
			for (int j=0; j<2; ++j) {
				loc[j] = antarr[i].getLocation()[j];
			}
			++newMatrix[loc[0]][loc[1]];
		}

		cout << "Steps taken: " << t+1 << endl;
		//printMatrix(newMatrix, m_rows, m_cols);

		saveMatrix(filename, newMatrix, m_rows, m_cols);

		// Replace matrix with new matrix

	}


	/*
	cout << endl;
	cout << "Create ant, Adam:" << endl;
	int TypeA = 1, DirectionA = 1, locA[] = {1,1};
	Ant Adam(TypeA, DirectionA, locA);

	cout << endl;
	cout << "Create ant, Ben:" << endl;
	int TypeB = 1, locB[] = {2,2};
	Ant Ben;
	Ben.setType(TypeB);
	Ben.setLocation(locB);

	Ant::printAllInfo();

	cout << endl << "Adam info: " << endl;
	Adam.printAntInfo();

	cout << endl << "Ben info: " << endl;
	Ben.printAntInfo();
	*/

	/*for (int i=0; i<nants; ++i) {
		antarr[i].printAntInfo();
	}*/

	return 0;
}


/*
int main() {
	
	Bank::printBankInfo();

	cout << "Ant created called Adam" << endl;
	Ant Adam(1, 500);

	cout << "Ant created called Sarah" << endl;
	Bank Sarah;
	Sarah.setAccountNumber(2);
	Sarah.setBalance(1000);
	Sarah.setName("Sarah");

	cout << "Sarah withdrew 250" << endl;
	Sarah.withdraw(250);

	return 0;
}*/