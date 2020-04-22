#include "window.h"
int Window::Window()
{
	timeOccupied  = 0;
	timeUnoccupied = 0;
}
void Window::WindowTick(bool isOccupied)
{
	if (isOccupied)
	{
		timeOccupied +=1;
	}
	else
	{
		timeUnoccupied +=1;
	}
}
int Window::GetOccupied()
{
	return timeOccupied;
}
int Window::GetUnoccupied()
{
	return timeUnoccupied;
}
