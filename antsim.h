#include <cstdlib>
#include <iostream>
#include <ctime>

#include <string>
#include <cmath>
#include <iomanip>
#include <vector>

#include "antobj.h"


#ifndef ANTSIM_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define ANTSIM_H

using namespace std;


int** generateMatrix(int, int);

void printMatrix(int**, int, int);

void saveMatrix(string, int**, int, int);

void populateMatrix(int**, int, int, int*, int);

void prepAntFile(string);

void saveAnts(string, Ant*, int, int);



#endif