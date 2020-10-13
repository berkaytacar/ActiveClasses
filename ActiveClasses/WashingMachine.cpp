#include "rt.h"
#include "WashingMachine.h"

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

int WashingMachine::main(void)
{

	//	for (int i = 0; i < 5; i++) {
	//		cout << "I am an ActiveClass1 Object/Thread. My Data is " << MyNumber << ".....\n";
	//		SLEEP(400);
	//	}
	printf("WM #%d: Ready \n", MyNumber);
	SLEEP(400);

	while (1) {
		printf("WM #%d: IDLE \n", MyNumber);
		SLEEP(400);

		while (startButton) {
			WaterInletValve WV1(MyNumber);
			WV1.Resume();
			SLEEP(50);
			printf("WM #%d: FILLING \n", MyNumber);

			SLEEP(400);
			if (stopButton) {
				WV1.Stop();
				WV1.WaitForThread();
				break;
			}


			Motor M1(MyNumber);
			M1.Resume();
			SLEEP(50);
			printf("WM #%d: WASHING \n", MyNumber);
			SLEEP(400);


			if (stopButton) {
				WV1.Stop();
				M1.Stop();
				M1.WaitForThread();
				WV1.WaitForThread();
				break;
			}

			M1.Stop();
			WV1.Stop();
			SLEEP(50);
			printf("WM #%d: DRAINING \n", MyNumber);

			SLEEP(400);
			if (stopButton) {
				M1.WaitForThread();
				WV1.WaitForThread();
				break;
			}
			printf("WM #%d: SPINNING \n", MyNumber);
			SLEEP(400);
			M1.WaitForThread();
			WV1.WaitForThread();
			startButton = 0;
		}

		//////////
		if (stopButton) {
			printf("The WashingMachine # %d has been stopped\n", MyNumber);
			break;
		}
	}

	return 0;
}

///////// start function public //////////
int WashingMachine::Start(void) {
	printf("The WashingMachine #%d has been started\n", MyNumber);
	startButton = 1;
	stopButton = 0;
	return startButton;

}

///////// stop function public //////////
int WashingMachine::Stop(void) {
	//printf("The WashingMachine #%d has been stopped\n", MyNumber);
	stopButton = 1;
	startButton = 0;
	return stopButton;
}

//
//	The program main()
//
