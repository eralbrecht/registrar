#include <iostream>

using namespace std;
int main(int argc, char** argv)
{

	string analysisString;

	//loads in file
	while (analysisString.length() == 0)
	{
		if (argc > 1)
		{
			string inputFile = argv[1];
			cout << "file name is: " << inputFile << endl;
			analysisString = inputFile
		}
		else
		{
			cout << "you must give a file name as your command line argument when calling this function" << endl;
		}
	}
	int lineCount = 0;
	string currString;
	//we will iterate through the file, in waves of information, to create windows, and students
	while (getLine(analysisString, currString)
	{
		if (lineCount == 0)
		{
			int windowCount = currString(int);
			//call the window thing to create the windows, maybe have a while statment embeded in here that will make the correct number of objects?
			lineCount += 1;
		}
		if (lineCount == 1)
		{
			lineCount += 1;
			int currClock = currString(int);
		}
		if (lineCount == 2)
		{
			lineCount += 1;
			int currStudentCount = currString(int);
		}
		if (lineCount ==3)
		{
			//call student object function and use the clock value, and time needed for service in window
			if (currStudentCount == 1)//this was the last student in the wave and its over and we will start a new wave
			{
				lineCount = 1;
			}
			currStudentCount -= 1;
		}
	}
	//call simulation function
}
