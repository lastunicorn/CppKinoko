#pragma once
#include "KinokoResult.cpp"

class Kinoko
{
public:
	Kinoko(void);
	void Run(void);
	virtual ~Kinoko(void);

private:
	int taskRunCount;
	void (*task)();
	KinokoResult *result;
	KinokoResult CreateKinokoResult(int count);
	void DestroyKinokoResult(KinokoResult *result);
	void CalculateAverage(KinokoResult *result);
};
