#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>

#include "antobj.h"

using namespace std;


//Static Member Variables
int Ant::totalAnts = 0;


Ant::Ant(){
	totalAnts++;

	Id = totalAnts;
	Type = 1;
	Direction = 5;
	cout << "Output" << endl;
	for (int i=0; i<2; ++i) {
		Location.push_back(0);
	}
}

Ant::Ant(int newType, int newDirection, vector<int> newLocation){
	totalAnts++;

	Id = totalAnts;
	Type = newType;
	Direction = newDirection;
	for (int i=0; i<2; ++i) {
		Location.push_back(newLocation[i]);
	}
}

Ant::~Ant() {
	totalAnts--;
}

int Ant::getId() {
	return Id;
}

int Ant::getType() {
	return Type;
}

int Ant::getDirection() {
	return Direction;
}

vector<int> Ant::getLocation() {
	return Location;
}

void Ant::setId(int newId) {
	Id = newId;
}

void Ant::setType(int newType) {
	Type = newType;
}

void Ant::setLocation(vector<int> newLocation) {
	for (int i=0; i<2; ++i) {
		Location[i] = newLocation[i];
	}
}

void Ant::changeDirection(int newDirection) {
	Direction = newDirection;
}

void Ant::changeType(int newType) {
	Type = newType;
}

void Ant::changeLocation(vector<int> newLocation) {
	for (int i=0; i<2; ++i) {
		Location[i] = newLocation[i];
	}
}


void Ant::printId() {
	cout << "Ant Id: " << Id << endl;
}
void Ant::printType() {
	cout << "Ant type: " << Type << endl;
}
void Ant::printDirection() {
	cout << "Direction: " << Direction << endl;
}
void Ant::printLocation() {
	cout << "Location: ";
	for (int i=0; i<2; ++i) {
		cout << Location[i] << " ";
	}
	cout << endl;
}
void Ant::printAntInfo() {
	printId();
	printType();
	printDirection();
	printLocation();
}


void Ant::printAllInfo() {
	cout << endl << "Ant number: " << totalAnts << endl;
}