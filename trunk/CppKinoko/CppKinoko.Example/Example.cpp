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

#include <stdio.h>
#include <time.h>
#include "windows.h"
#include "Kinoko.h"
#include "KinokoResult.h"

void Task();
void Pause();
void Kinoko_BeforeTaskRun(int stepIndex);
void Kinoko_AfterTaskRun(int stepIndex, double time);

int taskRunCount = 10;
int sleepMilli = 200;

void main ()
{
	printf("CppKinoko usage example\n");
	printf("===============================================================================\n");
	printf("Running a fake task that junst sleeps for %d milliseconds.\n", sleepMilli);
	printf("The test is repeated %d times and the avarage time is displayed.\n", taskRunCount);
	printf("\n");

    //----------
    HMODULE dll = LoadLibrary(L"..\\Debug\\CppKinoko.dll");

    typedef  Kinoko* (*CreateKinoko)(void);
    CreateKinoko createKinoko = (CreateKinoko)GetProcAddress(dll, "createKinoko");
    //----------

	Kinoko *kinoko = createKinoko();//new Kinoko();
	kinoko->SetTask(&Task);
	kinoko->SetTaskRunCount(taskRunCount);
	kinoko->beforeTaskRun = &Kinoko_BeforeTaskRun;
	kinoko->afterTaskRun = &Kinoko_AfterTaskRun;
	kinoko->Run();
	
	printf("Avarage time: %.2f milisec\n", kinoko->GetResult()->GetAverage());
	Pause();

    if(dll){
        FreeLibrary(dll);
    }
}

/*
--------------------------------------------------------------------------------
The task that neesds to be tested.
--------------------------------------------------------------------------------
*/
void Task()
{
	Sleep(sleepMilli);
}

/*
--------------------------------------------------------------------------------
Function called every time before the task is run.
--------------------------------------------------------------------------------
*/
void Kinoko_BeforeTaskRun(int stepIndex)
{
	printf("Running: %d", stepIndex);
}

/*
--------------------------------------------------------------------------------
Function called every time after the task is run.
--------------------------------------------------------------------------------
*/
void Kinoko_AfterTaskRun(int stepIndex, double time)
{
	printf(" - %.2f\n", time);
}

/*
--------------------------------------------------------------------------------
Pauses the console until the user presses a key.
--------------------------------------------------------------------------------
*/
void Pause()
{
	printf("\nPress enter to continue...");
	getchar();
	printf("\n");
}