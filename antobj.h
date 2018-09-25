#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

#ifndef ANTOBJ_H
#define ANTOBJ_H

class Ant{
	public:
		//Default Constructor
		Ant();

		//Overload Constructor
		Ant(int, int, vector<int>);

		//Destructor
		~Ant();

		//Accessor Functions
		int getId();
			//getId = gets Id of ant
			// @return int - Id of ant
		int getType();
			//getType - gets Type of ant
			// @return int - Type
			// Types are converted into integers:
			//	 1: unlaiden alive, 2: laiden alive, 3: dead...
		int getDirection();
		vector<int> getLocation();

		void setId(int);
			//setId - sets Id of the ant
		void setType(int);
			//setType - sets type of ant
		void setDirection(int);
		void setLocation(vector<int>);

		void printType();
		void printId();
		void printDirection();
		void printLocation();
		void printAntInfo();

		static void printAllInfo();

		//Mutator Functions
		void changeType(int);

		void changeDirection(int);

		void changeLocation(vector<int>);

	private:
		//Member variables
		int Id;
		int Type;
		int Direction;
		vector<int> Location;

		//static int Age;
		static int totalAnts;
};

#endif