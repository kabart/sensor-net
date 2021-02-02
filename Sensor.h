#include <fstream>
#include <string>
using namespace std;

class Sensor{
	public:
		Sensor(string sensorName, string fileName, double& result);
		~Sensor();
		void run();
		void measure();
	private:
		string name;
		fstream read;
		double& data;
};

//todo: add logging into a file
