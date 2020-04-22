class Window
{
	public:
	void WindowTick(bool isOccupied);
	int GetOccupied();
	int GetUnoccupied();
	private:
	int timeOccupied;
	int timeUnoccupied;