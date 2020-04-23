//Registrar Simulation
//Rose Albrecht ealbrecht@chapman.edu #2300456 (section 1)
//Jordan Farmer jfarmer@chapman.edu #2289033 (section 2)
#include <iostream>
#include <fstream>
#include "Queue.h"
#include "Student.h"
#include "Window.h"


using namespace std;

int main(int argc, char** argv)
{

	string simulationFile;
	int totalStudentCount = 0;
	//Student newStudent; i think we make instances of this later and dont need it up here
	//loads in file

	//This whole chunk is to make sure the user provided a file, and checks if the file exists

	ifstream inFile;
	if (argc > 1)
	{
		string inputFile = argv[1];
		cout << "File name is: " << inputFile << endl;
		simulationFile = inputFile;

		inFile.open(simulationFile);

		if(!inFile)
		{
			cout << "This file does not exist in the directory. Pleas try again." << endl;
			exit(1);
		}
	}
	else
	{
		cout << "You must give a file name as your command line argument when running this program, try again." << endl;
		exit(1);
	}

	//If we reach this point, the file exists and the simulation can be started

	

	//call simulation function
	//call math function
}
