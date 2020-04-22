using namespace std;
class student()
{
public:
	Student(int arrivalTime, int helpTime);
	//constructor
	~Student();
	int getArrival();
	int getHelp();
private:
	int arrive;
	int help;
}