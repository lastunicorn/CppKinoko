#pragma once
#include "KinokoResult.cpp"

class Kinoko
{
private:
	int taskRunCount;
	void (*task)();
	KinokoResult *result;
	KinokoResult* CreateKinokoResult(int count);
	void DestroyKinokoResult(KinokoResult *result);
	void CalculateAverage(KinokoResult *result);

public:
	Kinoko(void);
	void SetTask(void (*task)());
	void Run(void);
	KinokoResult* GetResult();
	virtual ~Kinoko(void);
};
