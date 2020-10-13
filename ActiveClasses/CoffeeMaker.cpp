#include "rt.h"
#include "CoffeeMaker.h"

//
//	To create an active class with its own thread running through it. Derive a new class
//	from the base class 'ActiveClass' and then you MUST override the inherited base class function int main(void)
//	if you do not override main() with your own function it will not compile since the class will be abstract
//
//	Note that all active classes are created in the SUSPENDED state to avoid races between the constructor for the class
//	and the kernel which otherwise might try to run a thread through an incompleted constructed class object
//
//	Therefore you must forcible Resume() the class to allow its thread to run.
//

int CoffeeMaker::main(void)
{

//	for (int i = 0; i < 5; i++) {
//		cout << "I am an ActiveClass1 Object/Thread. My Data is " << MyNumber << ".....\n";
//		SLEEP(400);
//	}

	printf("CM #%d: Ready \n", MyNumber);
	SLEEP(400);

	while (1) {
		printf("CM #%d: IDLE \n", MyNumber);
		SLEEP(400);

		while (startButton) {
		
			SLEEP(50);
			printf("CM #%d: BOIL WATER \n", MyNumber);

			SLEEP(400);
			if (stopButton) {
				break;
			}

			SLEEP(50);
			printf("CM #%d: ADD COFFEE \n", MyNumber);
			SLEEP(400);


			if (stopButton) {
				break;
			}

			SLEEP(50);
			printf("CM #%d: ADD WATER \n", MyNumber);
			SLEEP(50);
			Sprinkler S1(MyNumber);
			S1.Resume();
			Creamer C1(MyNumber);
			C1.Resume();
			SLEEP(400);
			if (stopButton) {
				C1.Stop();
				S1.Stop();
				C1.WaitForThread();
				S1.WaitForThread();
				break;
			}
			printf("CM #%d: DISPENSE \n", MyNumber);
			SLEEP(50);
			C1.Stop();
			S1.Stop();
			SLEEP(400);
			C1.WaitForThread();
			S1.WaitForThread();
			startButton = 0;
		}

		//////////
		if (stopButton) {
			printf("The CoffeeMachine # %d has been stopped\n", MyNumber);
			break;
		}
	}

	return 0;
}
	/*
	while (1) {
		printf("CM #%d: Ready \n", MyNumber);
		//cout << "CM #" << MyNumber << " Ready\n";
		SLEEP(400);
		//startButton = Start();
		
		if (startButton == 1) {
			printf("CM #%d: BOIL WATER\n", MyNumber);
			SLEEP(400);
			if (stopButton == 1) {
				printf("The CoffeeMaker #%d has been stopped\n", MyNumber);
				break;
				//return 0;
			}
			printf("CM #%d: ADD COFFEE \n", MyNumber);
			SLEEP(400);
			if (stopButton == 1) {
				printf("The CoffeeMaker #%d has been stopped\n", MyNumber);
				break;
				//return 0;
			}
			printf("CM #%d: ADD WATER \n", MyNumber);
			SLEEP(400);
			if (stopButton == 1) {
				printf("The CoffeeMaker #%d has been stopped\n", MyNumber);
				break;
				//return 0;
			}
			printf("CM #%d: DISPENSE\n", MyNumber);
			SLEEP(400);
			if (stopButton == 1) {
				printf("The CoffeeMaker #%d has been stopped\n", MyNumber);
				break;
				//return 0;
			}
		}

		*/

		//return 0;
		//printf("CM #%d: BOIL WATER\n", MyNumber);
		//cout << "CM #" <<MyNumber << ": BOIL WATER\n";
		/*SLEEP(400);
		printf("CM #%d: ADD COFFEE \n", MyNumber);*/
		//cout << "CM #" << MyNumber << ": ADD COFFEE\n";
		/*SLEEP(400);
		printf("CM #%d: ADD WATER \n", MyNumber);*/
		//cout << "CM #" << MyNumber << ": ADD MILK\n";
		/*SLEEP(400);
		printf("CM #%d: DISPENSE\n", MyNumber);*/
		//cout << "CM #" << MyNumber << ": DISPENSE\n";
		//SLEEP(400);
		//return 0;

///////// start function public //////////
int CoffeeMaker::Start(void) {
	printf("The CoffeeMaker #%d has been started\n", MyNumber);
	startButton = 1;
	stopButton = 0;
	return startButton;

}

///////// stop function public //////////
int CoffeeMaker::Stop(void) {
	//printf("The CoffeeMaker #%d has been stopped\n", MyNumber);
	stopButton = 1;
	startButton = 0;
	return stopButton;
}

//
//	The program main()
//
