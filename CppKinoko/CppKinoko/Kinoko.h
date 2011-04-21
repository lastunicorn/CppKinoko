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

#include "KinokoResult.h"

class CPPKINOKO_API Kinoko
{
private:
	int taskRunCount;
	void (*task)();
	KinokoResult *result;

public:
	Kinoko(void);
	~Kinoko(void);
	
	void (*beforeTaskRun)(int);
	void (*afterTaskRun)(int, double);

	void SetTaskRunCount(int value);
	void SetTask(void (*task)());
	void Run(void);
	KinokoResult* GetResult();
};
