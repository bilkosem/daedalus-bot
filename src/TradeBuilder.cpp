#include "TradeBuilder.h"

void TradeBuilder::setStrategy(std::string strategyName)
{
	trade.strategy = strategyName;
}

void TradeBuilder::setEnterOrder(Order order)
{

	trade.enter = order;
}

void TradeBuilder::setExitOrder(Order order)
{
	trade.exit = order;
}

void TradeBuilder::parseJson()
{
}

Trade TradeBuilder::build()
{
	return trade;
}
