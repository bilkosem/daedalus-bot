#pragma once
#include "Trade.h"

class TradeBuilder
{
	Trade trade;
public:
	void setStrategy(std::string strategyName);
	void setEnterOrder(Order order);
	void setExitOrder(Order order);
	void parseJson();
	Trade build();

};

