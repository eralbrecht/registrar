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

	int lineCount = 0;
	string currString;
	//we will iterate through the file, in waves of information, to create windows, and students
	//initialize nexted variables
	int currClock = 0;
	int currStudentCount =0;
	int helpClock = 0;
	int windowCount = 0;
	while (getline(inFile, currString))
	{
		//getline(inFile, currString);
		if (lineCount == 0)
		{
			windowCount = stoi(currString);
			//call the window thing to create the windows, maybe have a while statment embeded in here that will make the correct number of objects?
			lineCount += 1;
			while (windowCount !=0)
			{
				Window *myWindow = new Window();
				windowCount -=1;
				//push to a list of windows but idk how
			}
		}
		if (lineCount == 1)
		{
			//first line in wave will tell us what time they show up
			lineCount += 1;
			currClock = stoi(currString);
		}
		if (lineCount == 2)
		{
			//this will tell us how big the student wave is
			lineCount += 1;
			currStudentCount = stoi(currString);
		}
		if (lineCount ==3)
		{
			helpClock = stoi(currString);
			//this will tell us how long the student will need help for and add them to the list
			Student *myStudent = new Student(currClock, helpClock);

			//maybe we use totalStudentCount
			totalStudentCount += 1;
			//how to push student to the queue
			if (currStudentCount == 1)//this was the last student in the wave and its over and we will start a new wave
			{
				lineCount = 1;
			}
			currStudentCount -= 1;
		}
	}

	//call simulation function
}
