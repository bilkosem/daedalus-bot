#pragma once
#include "DaedalusPrimitives.h"
#include "TradeBuilder.h"
class BaseStrategy
{
public:
	virtual Trade evaluate() = 0;
};

