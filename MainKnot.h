#include <queue> 
using namespace std;

struct Message {
	double value1;
	double value2;
} ;

class MainKnot{
	public:
		MainKnot(unsigned int size);
		void run(double& read1, double& read2); //to do: pass a reference to a vector
		void write(Message m);
		Message read();
		void remove();
	private:
		unsigned int bufforSize;
		queue<Message> buffor;
};

//to do: logging into a file instead of into cout
