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

KinokoResult::KinokoResult(int count)
{
	times = new double[count];
	this->count = count;
	actualIndex = 0;
	average = -1;
}

KinokoResult::~KinokoResult(void)
{
	if(times != NULL)
		delete[] times;
}

void KinokoResult::AddValue(double time)
{
	times[actualIndex++] = time;
}

double KinokoResult::GetValue(int index)
{
	return times[index];
}

double KinokoResult::GetAverage()
{
	return average;
}

void KinokoResult::Calculate()
{
	double sum = 0;
	
	for (int i = 0; i < count; i++)
	{
		sum += times[i];
	}

	average = sum / (double)count;
}