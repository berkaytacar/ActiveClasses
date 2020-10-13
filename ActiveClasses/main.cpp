#include "CoffeeMaker.h"
#include "WashingMachine.h"


int main(void)
{
	// create instance of the above active object on the stack
	// then allow it to run and then wait for it to terminate

	CoffeeMaker Object1(1), Object2(2), Object3(3), Object4(4), Object5(5);		// create an instance of the above class and pass constructor the value 1 just to show how to do it
	WashingMachine Object6(6), Object7(7), Object8(8), Object9(9), Object10(10);		// create an instance of the above class and pass constructor the value 2 just to show how to do it

	Object1.Resume();				// allow thread to run
	Object2.Resume();				// allow thread to run
	Object3.Resume();				// allow thread to run
	Object4.Resume();				// allow thread to run
	Object5.Resume();				// allow thread to run
	Object6.Resume();				// allow thread to run
	Object7.Resume();				// allow thread to run
	Object8.Resume();				// allow thread to run
	Object9.Resume();				// allow thread to run
	Object10.Resume();				// allow thread to run

	printf("Parent started Objects\n");
	Object1.Start();
	Object2.Start();
	Object3.Start();
	Object4.Start();
	Object5.Start();
	Object6.Start();
	Object7.Start();
	Object8.Start();
	Object9.Start();
	Object10.Start();
	printf("Parent stopped Object1\n");
	Object1.Stop();
	Object6.Stop();
	Sleep(5000);
	printf("Parent stopped Objects\n");
	//Object1.Stop();
	Object2.Stop();
	Object3.Stop();
	Object4.Stop();
	Object5.Stop();
	//Object6.Stop();
	Object7.Stop();
	Object8.Stop();
	Object9.Stop();
	Object10.Stop();

	//printf("Parent started Object1\n");
	//Object1.Start();
	

	Object1.WaitForThread();
	Object2.WaitForThread();
	Object3.WaitForThread();
	Object4.WaitForThread();
	Object5.WaitForThread();
	Object6.WaitForThread();
	Object7.WaitForThread();
	Object8.WaitForThread();
	Object9.WaitForThread();
	Object10.WaitForThread();


	cout << "Finished\n";

	// object1/2 destructor called at the end of program main()

	return 0;
}


