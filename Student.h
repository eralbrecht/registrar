//Registrar Simulation
//Rose Albrecht ealbrecht@chapman.edu #2300456 (section 1)
//Jordan Farmer jfarmer@chapman.edu #2289033 (section 2)
#include <iostream>

using namespace std;

class Student
{
	public:
		Student(int arrivalTime, int helpTime); //Constructor
		~Student(); //Destructor
		int getArrival();
		int getHelp();

		int arrival;
		int help;
};
