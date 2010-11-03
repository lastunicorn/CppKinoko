#include <stdio.h>
#include <time.h>
#include "windows.h"
#include "Kinoko.h"

#define CLOCKS_PER_MILISEC CLOCKS_PER_SEC * 1000

void Task();
void Pause();
double TestRunner(void (*Task)(int), int count, int testRepeateCount);
double Avarage(double values[], int count);

int taskRunCount = 10;
int sleepMilli = 300;

void main ()
{
	int count = 100000000;

	printf("CppKinoko usage example\n");
	printf("===============================================================================\n");
	printf("Running a fake task that junst sleeps for %d milliseconds.\n", sleepMilli);
	printf("The test is repeated %d times and the avarage time is displayed.\n", taskRunCount);
	printf("\n");

	Kinoko *kinoko = new Kinoko();
	kinoko->SetTask(&Task);
	kinoko->Run();

	//double milis = TestRunner(&Task2, count, 10);
	
	printf("Avarage time: %.2f milisec\n", kinoko->GetResult()->average);
	Pause();
}

double TestRunner(void (*Task)(int), int count, int testRepeateCount)
{
	double* times = new double[testRepeateCount];

	for (int i = 0; i < testRepeateCount; i++)
	{
		printf("Running: %d", i);

		clock_t t1 = clock();
		Task(count);
		clock_t t2 = clock();

		times[i] = (t2-t1) / (double)CLOCKS_PER_MILISEC;
		
		printf(" - %.2f\n", times[i]);
	}

	printf("\n");

	double avarage =  Avarage(times, testRepeateCount);
	delete[] times;
	return avarage;
}

void Task()
{
	Sleep(sleepMilli);

	/*int* a = new int[count];

	for (int register i = 0; i < count; i++)
	{
		a[i] = i;
	}

	delete[] a;*/
}

void Pause()
{
	printf("\nPress enter to continue...");
	getchar();
	printf("\n");
}

double Avarage(double values[], int count)
{
	double sum = 0;

	for (int i = 0; i < count; i++)
	{
		sum += values[i];
	}

	return sum / count;
}