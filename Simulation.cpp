//Registrar Simulation
//Rose Albrecht ealbrecht@chapman.edu #2300456 (section 1)
//Jordan Farmer jfarmer@chapman.edu #2289033 (section 2)
#include "Simulation.h"
Simulation::SimulationRun(int windows, int totalStudentCount
{
	int clockCounter = 0;
	int finishedStudents;
	int windowOccupancy[window]={0}; //initialize our window array as all being unused, eventually their value will be the time left for the current occupent
	while (finishedStudents < totalStudentCount)
	{
		for (int i = 0; i<windowOccupancy.length; i++)
		{

			if(windowOccupancy[i] == 1)
			{
				finishedStudents +=1; //we are about to decriment the time left that every student has so this is about to go to zero signifying theyre finishing
			}
			//decriment the time left for each student
			windowOccupancy[i] = (windowOccupance[i] -1); //maybe this can be done with a -=1? im not sure
			
			
			//now we up the clock value
			clockCounter +=1;
			//for all the windows we will check if they are empty
			//it its empty we will add the amount of time that the student needs help for
			if(windowOccupancy[i] < 1)//dont want it to be 0 because we might be going negative
			{
				Student currentStudent = studentqueue.peek();
				if (currentStudent.getArrival >= clockCounter)
				{
					Student currentStudent = studentqueue.pop();
					windowOccupancy[i] = currentStudent.getHelp();
					currentStudent.setTimeWaited(currentStudent.getArrival() - clockCounter);
				}
			}
			if(windowOccupancy[i] > 0)
			{
				//need to figure out how to use a "window" method to add time occupied for the window object in the same index location as the occupied window
			}
			else
			{
				//same as above but want to increment the unoccupied count
			}
			
		}
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
