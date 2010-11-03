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

void Task();
void Pause();

int taskRunCount = 10;
int sleepMilli = 200;

void main ()
{
	printf("CppKinoko usage example\n");
	printf("===============================================================================\n");
	printf("Running a fake task that junst sleeps for %d milliseconds.\n", sleepMilli);
	printf("The test is repeated %d times and the avarage time is displayed.\n", taskRunCount);
	printf("\n");

	Kinoko *kinoko = new Kinoko();
	kinoko->SetTask(&Task);
	kinoko->SetTaskRunCount(taskRunCount);
	kinoko->Run();
	
	printf("Avarage time: %.2f milisec\n", kinoko->GetResult()->GetAverage());
	Pause();
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