//Registrar Simulation
//Rose Albrecht ealbrecht@chapman.edu #2300456 (section 1)
//Jordan Farmer jfarmer@chapman.edu #2289033 (section 2)
#ifndef WINDOW
#define WINDOW

#include <iostream>

using namespace std;
class Window
{
	public:

	Window();
	~Window();
	void WindowTick(bool isOccupied);
	void isOccupied();
	int GetOccupied();
	int GetUnoccupied();
	int GetRemaining();
	int SetRemaining(int time);
	int DecrimentRemaining();
	private:
	int timeOccupied;
	int timeUnoccupied;
	int timeRemaining;
	bool occupied;
};

#endif
