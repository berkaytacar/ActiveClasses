#include "rt.h"


class WashingMachine : public ActiveClass
{

	// put any attributes and member functions here that you like 
	// just like any other class along with any constructors and destructors

private:

	int MyNumber;
	int startButton;
	int stopButton;

	//  Must override main() inherited from ActiveClass. The base class constructor will then
	//	create a thread execute main()
	int main(void);

public:
	WashingMachine(int _MyNumber) { MyNumber = _MyNumber; }
	int Start();
	int Stop();
};


class WaterInletValve : public ActiveClass {
private:
	int num;
	int val;
	int main(void) {
		printf("WaterInletValve #%d Initiated\n", num);
		while (val == 0) {}
		printf("WaterInletValve #%d Off\n", num);		
		return 0;
	}

public:
	WaterInletValve(int _num) { num = _num; val = 0; }
	void Stop() { val = 1; }
};

class Motor : public ActiveClass {
private:
	int num;
	int val;
	int main(void) {
		printf("Motor #%d Initiated\n", num);
		while (val == 0) {}
		printf("Motor #%d Off\n", num);
		return 0;
	}

public:
	Motor(int _num) { num = _num; val = 0; }
	void Stop() { val = 1; }
};