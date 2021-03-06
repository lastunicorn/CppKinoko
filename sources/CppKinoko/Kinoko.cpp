// CppKinoko
// Copyright (C) 2010 Dust in the Wind
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <time.h>
#include "Kinoko.h"

/*
--------------------------------------------------------------------------------
Initializes a new instance of the Kinoko class.
--------------------------------------------------------------------------------
*/
Kinoko::Kinoko(void)
    : taskRunCount(0)
    , task(0)
    , result(0)
    , beforeTaskRun(0)
    , afterTaskRun(0)
{
}

/*
--------------------------------------------------------------------------------
Releases the memory used by current instance of Kinoko class.
--------------------------------------------------------------------------------
*/
Kinoko::~Kinoko(void)
{
	if (result != NULL)
		delete result;
}

/*
--------------------------------------------------------------------------------
Gets or sets the number of times the task is run within the test. The task
should be run multiple times to minimize the measurement errors.
--------------------------------------------------------------------------------
*/
void Kinoko::SetTaskRunCount(int value)
{
	taskRunCount = value;
}

/*
--------------------------------------------------------------------------------
Sets the task that is tested by Kinoko.
--------------------------------------------------------------------------------
*/
void Kinoko::SetTask(void (*task)())
{
	this->task = task;
}

/*
--------------------------------------------------------------------------------
Runs the task multiple times and measures the time intervals spent.
After the test is finished, result is automatically calculated by calling the
KinokoResult->Calculate method.
--------------------------------------------------------------------------------
*/
void Kinoko::Run(void)
{
	KinokoResult *result = new KinokoResult(taskRunCount);

	// The Task is run multiple times and then an average is calculated.

	for (int i = 0; i < taskRunCount; i++)
	{
		// Announce that the Task is about to be run.
		if (beforeTaskRun != NULL)
			beforeTaskRun(i);

		// Run the Task.
		clock_t t1 = clock();
		task();
		clock_t t2 = clock();

		// Calculate the time that was necessary to run the task.
		double intervalMilli = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000;

		// Store the time interval.
		result->AddValue(intervalMilli);

		// Announce that the Task was run.
		if (afterTaskRun != NULL)
			afterTaskRun(i, result->GetValue(i));
	}

	// Calculate the average.
	result->Calculate();

	this->result = result;
}

/*
--------------------------------------------------------------------------------
Gets the results of the test. It is null if no test was run.
Every time the Run method is called, the old result is discarded.
--------------------------------------------------------------------------------
*/
KinokoResult* Kinoko::GetResult()
{
	return result;
}


//--------------------------------------------------
Kinoko* createKinoko(void){
    #pragma comment(linker, "/EXPORT:"__FUNCTION__"="__FUNCDNAME__)
    return new Kinoko();
}