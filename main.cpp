//Registrar Simulation
//Rose Albrecht ealbrecht@chapman.edu #2300456 (section 1)
//Jordan Farmer jfarmer@chapman.edu #2289033 (section 2)
#include <iostream>
#include "Queue.h"
#include "Student.h"
#include "Window.h"
using namespace std;
int main(int argc, char** argv)
{

	string analysisString;
	int totalStudentCount = 0;
	//Student newStudent; i think we make instances of this later and dont need it up here
	//loads in file
	while (analysisString.length() == 0)
	{
		if (argc > 1)
		{
			string inputFile = argv[1];
			cout << "file name is: " << inputFile << endl;
			analysisString = inputFile;
		}
		else
		{
			cout << "you must give a file name as your command line argument when calling this function, try again" << endl;
		}
	}
	int lineCount = 0;
	string currString;
	//we will iterate through the file, in waves of information, to create windows, and students
	while (getLine(analysisString, currString))
	{
		if (lineCount == 0)
		{
			int windowCount = currString(int);
			//call the window thing to create the windows, maybe have a while statment embeded in here that will make the correct number of objects?
			lineCount += 1;
		}
		if (lineCount == 1)
		{
			//first line in wave will tell us what time they show up
			lineCount += 1;
			int currClock = currString(int);
		}
		if (lineCount == 2)
		{
			//this will tell us how big the student wave is
			lineCount += 1;
			int currStudentCount = currString(int);
		}
		if (lineCount ==3)
		{
			int helpClock = currString(int);
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
	while (windowCount !=0)
	{
		Window *myWindow = new Window();
		windowCount -+1;
		//push to a list of windows but idk how
	}
	//call simulation function
}
