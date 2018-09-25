#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>

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