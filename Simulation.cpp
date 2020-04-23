//Registrar Simulation
//Rose Albrecht ealbrecht@chapman.edu #2300456 (section 1)
//Jordan Farmer jfarmer@chapman.edu #2289033 (section 2)
#include <iostream>
#include <fstream>
#include "Simulation.h"
#include "Queue.h"
#include "DoublyLinkedList.h"

//need constructor

void Simulation::OpenFile(string inputFile)
{
	lineCount = 0;
	string currString;

  //Instance of file stream
  ifstream inFile;
	//we will iterate through the file, in waves of information, to create windows, and students
	//initialize nexted variables
	int currClock = 0;
	int currStudentCount =0;
	int helpClock = 0;
	int windowCount = 0;
  int totalStudentCount = 0;

  if(!inFile)
  {
    cout << "This file does not exist in the directory. Pleas try again." << endl;
    exit(1);
  }
	while (getline(inFile, currString))
	{
		//getline(inFile, currString);
		if (lineCount == 0)
		{
			windowCount = stoi(currString);
			//call the window thing to create the windows, maybe have a while statment embeded in here that will make the correct number of objects?
			lineCount += 1;
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
}

void Simulation::SimulationRun(int numWindows, int totalStudentCount)
{
	int clock = 0;
	int finishedStudents = 0;
  Window myWindows[numWindows]; //Array to store each window individually, each window has member variables associated for how long it has been occupied, unoccupied, if it is currently occupied, and how much longer it will be occupied for

  //would it be easier to just initialize all of the windows here?

  //this is pasted from main, we can use it to initialize the windows
  			windowArray[windowCount];
			while (windowCount !=0)
			{
				Window *myWindow = new Window();
				windowCount -=1;

				//push to a list of windows but idk how

				windowArray[windowCount-1] = *myWindow;
				//push to an array of windows the size that is the number of windows we have
			}

	//int windowtimer[numWindows]={0}; //initialize our window array as all being unused, eventually their value will be the time left for the current occupant
	while (finishedStudents < totalStudentCount) //while there are still students waiting
	{
    //for all the windows we will check if they are empty
    //if they are, we will fill them and assign the timeRemaining variable based on the student, if they aren't, we will check if the student is done

		for (int i = 0; i < numWindows /*i<windowOccupancy.length*/; i++)
		{

			if(myWindows[i].GetRemaining() == 0)
			{
				finishedStudents +=1; //if the time remaining for a student is 0 ticks, they are finished at the window, so we increase the number of finished students
			}
			myWindows[i].DecrimentRemaining(); //decrease the time left for every student being helped

			//it its empty we will add the amount of time that the student needs help for
			if(myWindows[i].GetRemaining() < 1)
				//
				//dont want it to be 0 because we might be going negative
			{
				Student currentStudent = studentqueue.peek();
				if (currentStudent.getArrival >= clockCounter)//this is to see if its time to pull the next student yet
				{
					Student currentStudent = studentqueue.pop();
					myWindows[i].SetRemaining(currentStudent.getHelp());//set how much time the window will be occupied
					currentStudent.setTimeWaited(currentStudent.getArrival() - clockCounter);//set how long the student had to wait for help
				}
			}
			if(myWindows[i] == 0)
			{
				myWindows[i].WindowTick(true);
			}
			else
			{
				myWindow[i].WindowTick(false);
			}

		}
		clockCounter +=1; //Each run through the while loop is a clock tick
	}
}
void Simulation::Analysis()
{
	int maxtime;
	int studentswaitedover10;
	int idleover5;
	for student in student list
		wait time sum += student.getTimeWaited()
		if (student.getTimeWaited >= 10)
		{
			studentswaitedover10 +=1;
		}
		if (student.getTimeWaited > maxtime)
		{
			maxwaittime = student.getTimeWaited()
		}
	studentwaitmean  = waittimesum/finishedStudents()
	//im not sure how to find a median, ill figure it out tho
	for windows in window list
		idle time sum += window.GetUnoccupied()
		if (window.GetUnoccupied >= 5)
		{
			idleover5 +=1;
		}
		if (window.GetUnoccupied > maxtime)
		{
			maxidletime = student.getTimeWaited()
		}
	windowidlemean  = waittimesum/finishedStudents()
	cout<<"mean student wait time: "<< studentwaitmean<<endl;
	cout<<"median student wait time: "<< uhhhhhhh << endl;
	cout<<"longest student wait time: " << maxwaittime<<endl;
	cout<<"number of students that waited over ten minutes: " << studentswaitedover10<<endl;
	cout<<"mean window idle time: "<<windowidlemean<<endl;
	cout<<"longest window idle time: "<<maxidletime<<endl;
	cout<<"number of windows idle for over 5 minutes: " <<idleover5<<endl;
}





//make a clock, set the time to zero

//access the array of windows we made in main, initialize them as empty

//array of windows that exist, and the time left that the occupied ones will be in use

//pop students from queue but ONLY if there is an open window and the clock is at their time

//when we pop a student also give them the attribute of difference between current time and time arrived

//when the student is done we will push them to an array the size of total student count, and increment the number of students that are done
