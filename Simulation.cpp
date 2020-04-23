//Registrar Simulation
//Rose Albrecht ealbrecht@chapman.edu #2300456 (section 1)
//Jordan Farmer jfarmer@chapman.edu #2289033 (section 2)
#include <iostream>
#include "Simulation.h"
Simulation::SimulationRun(int numWindows, int totalStudentCount)
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
<<<<<<< HEAD
				//push to a list of windows but idk how
				//make an array of windows and the size of the array is the number of windows
=======
				windowArray[windowCount-1] = *myWindow;
				//push to an array of windows the size that is the number of windows we have
>>>>>>> caebf6feab64f578068ead66eb3d6b9a50a3b30c
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






bool done = false;
int clockCounter = 0;
int windowOccupancy[
while (!done)
{

//make a clock, set the time to zero

//access the array of windows we made in main, initialize them as empty

//array of windows that exist, and the time left that the occupied ones will be in use

//pop students from queue but ONLY if there is an open window and the clock is at their time

//when we pop a student also give them the attribute of difference between current time and time arrived

//when the student is done we will push them to an array the size of total student count, and increment the number of students that are done
