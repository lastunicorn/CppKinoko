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

#pragma once

#ifdef CPPKINOKO_EXPORTS
	#define CPPKINOKO_API __declspec(dllexport)
#else
	#define CPPKINOKO_API __declspec(dllimport)
#endif

class CPPKINOKO_API KinokoResult
{
private:
	double *times;
	int count;
	int actualIndex;
	double average;

public:
	KinokoResult(int count);
	~KinokoResult(void);

	void AddValue(double time);
	double GetValue(int index);
	double GetAverage();
	void Calculate();
};
