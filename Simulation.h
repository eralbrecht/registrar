//Registrar Simulation
//Rose Albrecht ealbrecht@chapman.edu #2300456 (section 1)
//Jordan Farmer jfarmer@chapman.edu #2289033 (section 2)
#ifndef SIMULATION
#define SIMULATION
#include <iostream>
#include "Queue.h"
#include "Student.h"
#include "Window.h"
using namespace std;

class Simulation
{
  public:

    Simulation(); //Constructor
    ~Simulation(); //Destructor

    void OpenFile(string inputFile);
    void Analysis();
    void SimulationRun();
  private:
	   int lineCount;
	   string currString;
	   //we will iterate through the file, in waves of information, to create windows, and students
	   //initialize nexted variables
	   int currClock;
	   int currStudentCount;
	   int helpClock;
	   int windowCount;
     int totalStudentCount;
     Queue* studentQueue;

};

#endif
