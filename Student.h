//Registrar Simulation
//Rose Albrecht ealbrecht@chapman.edu #2300456 (section 1)
//Jordan Farmer jfarmer@chapman.edu #2289033 (section 2)
#ifndef STUDENT
#define STUDENT

#include <iostream>

using namespace std;

class Student
{
	public:
		Student();
		Student(int arrivalTime, int helpTime); //Constructor
		~Student(); //Destructor
		int getArrival();
		int getHelp();
		void setTimeWaited(int deltaTime);
		int getTimeWaited();
		void print();
	private:
		int arrival;
		int help;
		int timeWaited;
};

#endif
