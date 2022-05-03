#include "Trade.h"


std::string Trade::dumpJson() {
	return std::string();
}

std::string Trade::getStrategyName(){ return std::string(); }
OrderTypes Trade::getExitType() { return static_cast<OrderTypes>(exit.index()); }
Order Trade::getExitOrder(){ return exit; }
OrderTypes Trade::getEnterType() { return static_cast<OrderTypes>(enter.index()); }
Order Trade::getEnterOrder(){ return enter; }