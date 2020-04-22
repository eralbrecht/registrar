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
