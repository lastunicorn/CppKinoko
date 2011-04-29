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
#include "KinokoResult.h"


/*
--------------------------------------------------------------------------------
Initializes a new instance of the KinokoResult class with the number of
measurements to store.
--------------------------------------------------------------------------------
*/
KinokoResult::KinokoResult(int count)
{
	times = new double[count];
	this->count = count;
	actualIndex = 0;
	average = -1;
}

/*
--------------------------------------------------------------------------------
Releases the memory used by the current instance of the KinokoResult class.
--------------------------------------------------------------------------------
*/
KinokoResult::~KinokoResult(void)
{
	if(times != NULL)
		delete[] times;
}

/*
--------------------------------------------------------------------------------
Adds a new time measurement to the list of time measurements.
--------------------------------------------------------------------------------
*/
void KinokoResult::AddValue(double time)
{
	times[actualIndex++] = time;
}

/*
--------------------------------------------------------------------------------
Gets the time measurement at the specified index.
--------------------------------------------------------------------------------
*/
double KinokoResult::GetValue(int index)
{
	return times[index];
}

/*
--------------------------------------------------------------------------------
Gets the average value in miliseconds of the time measurements.
--------------------------------------------------------------------------------
*/
double KinokoResult::GetAverage()
{
	return average;
}

/*
--------------------------------------------------------------------------------
Calculates all usefull values from the measured data.
--------------------------------------------------------------------------------
*/
void KinokoResult::Calculate()
{
	double sum = 0;
	
	for (int i = 0; i < count; i++)
	{
		sum += times[i];
	}

	average = sum / (double)count;
}