#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <fstream>

#include "antsim.h"

int** generateMatrix (int rows, int cols) {
	// Initialise a matrix with no values set
	int** temp = new int*[rows];
	for (int i=0; i<rows; ++i) {
		temp[i] = new int[cols];
	}
	return temp;
}

void printMatrix (int** matrix, int rows, int cols) {
	// Print matrix contents in cout
	for (int i=0; i<rows; ++i) {
		for (int j=0; j<cols; ++j) {
			cout << matrix[i][j] <<" ";
		}
		cout << endl;
	}
}

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

void populateMatrix (int** matrix, int rows, int cols, int* src, int src_size) {
	// Set values of matrix from 1D array
	if(rows*cols != src_size) {
		cout << "Matrix size != source size";
		exit(-1);
	}

	int pos = 0;
	for (int i=0; i<rows; ++i) {
		for (int j=0; j<cols; ++j) {
			int val = pos++;
			matrix[i][j] = src[val];
		}
	}
}