//Registrar Simulation
//Rose Albrecht ealbrecht@chapman.edu #2300456 (section 1)
//Jordan Farmer jfarmer@chapman.edu #2289033 (section 2)
#include <iostream>
#include "student.h"

using namespace std;

//constructor
Student::Student(int arrivalTime, int helpTime)
{
	arrival = arrivalTime;
	help = helpTime;
}

int Student::getHelp()
{
	return help;
}

int Student::getArrival()
{
	return arrival;
}
//make a variable that is the length of time they waited for help
