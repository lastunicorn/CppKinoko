#include <time.h>
#include "Kinoko.h"
#include "KinokoResult.cpp"


Kinoko::Kinoko(void)
{
}

Kinoko::~Kinoko(void)
{
	if (result != NULL)
		DestroyKinokoResult(result);
}

void Kinoko::Run(void)
{
	KinokoResult result = CreateKinokoResult(taskRunCount);
	clock_t t1;
	clock_t t2;

	// The Task is run multiple times and then an avarage is calculated.

	int i;
	for (i = 0; i < taskRunCount; i++)
	{
		// Announce that the Task is about to be run.
		/*if (beforeTaskRun != NULL)
			beforeTaskRun(i);*/

		// Run the Task.
		t1 = clock();
		task();
		t2 = clock();

		// Calculate and store the time in which the task run.
		result.times[i] = (t2-t1) / (double)CLOCKS_PER_SEC * 1000;

		// Announce that the Task was run.
		/*if (afterTaskRun != NULL)
			afterTaskRun(i, result.times[i]);*/
	}

	// Calculate the average.
	CalculateAverage(&result);

	this->result = &result;
}

KinokoResult Kinoko::CreateKinokoResult(int count)
{
	KinokoResult result;
	result.times = new double[count];
	result.count = count;
	return result;
}

void Kinoko::DestroyKinokoResult(KinokoResult *result)
{
	delete[] result->times;
}

void Kinoko::CalculateAverage(KinokoResult *result)
{
	double sum = 0;
	int i;

	for (i = 0; i < result->count; i++)
	{
		sum += result->times[i];
	}

	result->average = sum / (double)result->count;
}
