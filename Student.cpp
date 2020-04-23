//Registrar Simulation
//Rose Albrecht ealbrecht@chapman.edu #2300456 (section 1)
//Jordan Farmer jfarmer@chapman.edu #2289033 (section 2)
#include <iostream>
#include "Student.h"

using namespace std;

//constructor
Student::Student(int arrivalTime, int helpTime)
{
	arrival = arrivalTime;
	help = helpTime;
	timeWaited = 0;
}

int Student::getHelp()
{
	return help;
}

int Student::getArrival()
{
	return arrival;
}

void Student::setTimeWaited(int deltaTime)
{
	timeWaited = deltaTime;
}

int Student::getTimeWaited()
{
	return timeWaited;
}
