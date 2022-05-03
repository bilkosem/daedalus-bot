#pragma once
#include<iostream>
class TimeUtils
{
public:
	static int dummy();
	static unsigned long long getCurrentTimestamp();
	static unsigned long long roundToPeriod(const unsigned long long& current_time, const unsigned long long& periodMinute, const bool toFloor, const unsigned long long offsetSecond);
};

