#include "rt.h"


class CoffeeMaker : public ActiveClass
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
	CoffeeMaker(int _MyNumber) { MyNumber = _MyNumber; }
	int Start();
	int Stop();

};

class Sprinkler : public ActiveClass {
private:
	int num;
	int val;
	int main(void) {
		printf("Sprinke Some Chocolate on #%d\n", num);
		while (val == 0) {}
		printf("Stop Sprinkling Chocolate on #%d\n", num);
		return 0;
	}

public:
	Sprinkler(int _num) { num = _num; val = 0; }
	void Stop() { val = 1; }
};


class Creamer : public ActiveClass {
private:
	int num;
	int val;
	int main(void) {
		printf("Pour Some Cream on #%d\n", num);
		while (val == 0) {}
		printf("Stop Pouring Cream on #%d\n", num);
		return 0;
	}

public:
	Creamer(int _num) { num = _num; val = 0; }
	void Stop() { val = 1; }
};