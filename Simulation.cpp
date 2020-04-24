//Registrar Simulation
//Rose Albrecht ealbrecht@chapman.edu #2300456 (section 1)
//Jordan Farmer jfarmer@chapman.edu #2289033 (section 2)
#include <fstream>
#include <algorithm> //this library will give us a sort functionality
#include "Simulation.h"
#include "Queue.h"
#include "DoublyLinkedList.h"
using namespace std;
//need constructor
Simulation::Simulation()
{
    studentQueue = new Queue<Student>();
    finishedQueue = new Queue<Student>();
	totalStudentCount = 0;
	windowCount = 0;
}

Simulation::~Simulation()
{

}
void Simulation::OpenFile(string inputFile)
{
	lineCount = 0;
	string currString;

  //Instance of file stream
  ifstream inFile;
  inFile.open(inputFile);
	//we will iterate through the file, in waves of information, to create windows, and students
	//initialize nexted variables
	currClock = 0;
	currStudentCount =0;
	helpClock = 0;
	windowCount = 0;
  totalStudentCount = 0;


  if(!inFile)
  {
    cout << "This file does not exist in the directory. Pleas try again." << endl;
    exit(1);
  }
  cout<<"line44"<<endl;
  //cout<<"inFile:"<<inFile<<endl;
	while (getline(inFile, currString))
	{
		cout<<"line46"<<endl;
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
			cout<<"line66"<<endl;
			helpClock = stoi(currString);
			//this will tell us how long the student will need help for and add them to the queue
			//Student *myStudent = new Student(currClock, helpClock);
      Student *currStudent = new Student(currClock, helpClock);
      studentQueue->insert(*currStudent);


			totalStudentCount += 1;
			//how to push student to the queue
			if (currStudentCount == 1)//this was the last student in the wave and its over and we will start a new wave
			{
				lineCount = 1;
			}
			currStudentCount -= 1;
			cout<<"line86"<<endl;
		}
		cout<<"line88"<<endl;
	}
	cout<<"line90"<<endl;
}

void Simulation::SimulationRun()
{
	cout<<"line95"<<endl;
	int clock = 0;
	int finishedStudents = 0;
  Window myWindows[windowCount]; //Array to store each window individually, each window has member variables associated for how long it has been occupied, unoccupied, if it is currently occupied, and how much longer it will be occupied for


	while (finishedStudents < totalStudentCount) //while there are still students waiting
	{
		cout<<"line103"<<endl;
    //for all the windows we will check if they are empty
    //if they are, we will fill them and assign the timeRemaining variable based on the student, if they aren't, we will check if the student is done

		for (int i = 0; i < windowCount; i++)
		{
			cout<<"line109"<<endl;
			if(myWindows[i].GetRemaining() == 0) //if the time remaining for a student is 0 ticks
			{
				cout<<"line112"<<endl;
				finishedStudents +=1; //they are finished at the window, so we increase the number of finished students

				Student nextInLine = studentQueue->peek();
				if (nextInLine.getArrival() >= clock)//if the student has arrived
				{
					cout<<"line117"<<endl;
          if(studentQueue->isEmpty() == false)
		  {
				Student *currStudent = new Student(studentQueue->remove());
				cout<<"line120"<<endl;
  				myWindows[i].SetRemaining(currStudent->getHelp());//set how much time the window will be occupied
  				cout<<"line122"<<endl;
  				currStudent->setTimeWaited(currStudent->getArrival() - clock); 
				//set how long thestudent had to wait for help
  				cout<<"line124"<<endl;
  				finishedQueue->insert(*currStudent); //moving student from line to finished
  				cout<<"line126"<<endl;
          }


				}
			}
			cout<<"line129"<<endl;
			cout<<"remaining time at the window"<<myWindows[i].GetRemaining();
			myWindows[i].DecrimentRemaining();
			
			//decrease the time left for every student being helped
			cout<<"remaining time at the window"<<myWindows[i].GetRemaining();
			if(myWindows[i].GetRemaining() == 0)
			{
				cout<<"line133"<<endl;
				myWindows[i].WindowTick(true);
			}
			else
			{
				cout<<"line148"<<endl;
				myWindows[i].WindowTick(false);
			}

		}
		cout<<"line142"<<endl;
		clock +=1; //Each run through the while loop is a clock tick
	}
	cout<<"line145"<<endl;
	int maxTime = 0;
	double meanTime = 0;
	int totalStudentWaitTime = 0; //for calculating mean wait time
	int studentsOverTen = 0;
	int medianTime = 0;
	int windowsOverFive = 0;
	double meanWindow = 0;
	int maxWindow = 0;
	int totalWindowIdleTime = 0; //for calculating mean idle time
	Student finishedStudentsArray[totalStudentCount];
	cout<<"line 139"<<endl;
  for(int i = 0; i < totalStudentCount; i++)
  {
    finishedStudentsArray[i] = finishedQueue->remove();
  }
  cout<<"line144"<<endl;
  cout<<"totalStudentCount"<<totalStudentCount<<endl;
  for(int i = 0; i < totalStudentCount; i++)
  {
	cout<<"line147"<<endl;
    totalStudentWaitTime += finishedStudentsArray[i].getTimeWaited();
	cout<<"line149"<<totalStudentWaitTime<<endl;
    if(finishedStudentsArray[i].getTimeWaited() > maxTime)
    {
      maxTime = finishedStudentsArray[i].getTimeWaited();
	  cout<<"line151"<<endl;
    }
cout<<"line154"<<endl;
    if(finishedStudentsArray[i].getTimeWaited() > 10)
    {
      studentsOverTen++;
    }
  }
  int maxtemp = 0;
  int placetemp = 0;
  int tempArray[totalStudentCount];
  	for (int i = 0; i<totalStudentCount; i++)
	{
		tempArray[i] = finishedStudentsArray[i].getTimeWaited();
	}
	sort(tempArray, tempArray+totalStudentCount);
	if (totalStudentCount % 2 ==1)
	{
		medianTime = tempArray[(totalStudentCount - 1)/2];
	}
	else
	{
		medianTime = (tempArray[(totalStudentCount - 1)/2] + tempArray[1+((totalStudentCount - 1)/2)])/2;
		//this is the mean of the two middle values
	}
  for(int i = 0; i < windowCount; i++)
  {
    totalWindowIdleTime += myWindows[i].GetUnoccupied(); //for each window this will increase until the total is found

    if(myWindows[i].GetUnoccupied() > maxWindow){ //If a window has a longer idle time than another, set the max idle time
      maxWindow = myWindows[i].GetUnoccupied();
    }

    if(myWindows[i].GetUnoccupied() > 5)
    {
      windowsOverFive++;
    }
  }

  meanTime = totalStudentWaitTime / totalStudentCount;
  //im not sure how to find a median, ill figure it out tho


 meanWindow  = totalWindowIdleTime / windowCount;

  cout << "Mean student wait time: "<< meanTime << endl;
  //cout<<"median student wait time: "<< uhhhhhhh << endl;
  cout << "Longest student wait time: " << maxTime << endl;
  cout << "Number of students that waited over ten minutes: " << studentsOverTen << endl;
  cout << "Mean window idle time: "<< meanWindow << endl;
  cout << "Longest window idle time: " << maxWindow << endl;
  cout << "Number of windows idle for over 5 minutes: " << windowsOverFive << endl;

}






//make a clock, set the time to zero

//access the array of windows we made in main, initialize them as empty

//array of windows that exist, and the time left that the occupied ones will be in use

//pop students from queue but ONLY if there is an open window and the clock is at their time

//when we pop a student also give them the attribute of difference between current time and time arrived

//when the student is done we will push them to an array the size of total student count, and increment the number of students that are done
