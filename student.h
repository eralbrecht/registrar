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
