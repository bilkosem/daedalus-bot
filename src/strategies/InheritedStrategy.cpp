#include "strategies/InheritedStrategy.h"


Trade InheritedStrategy::evaluate(){
	TradeBuilder tb = TradeBuilder();
	tb.setStrategy("DummyName");
	tb.setEnterOrder(Order{ Market{ 1,2,3 } });
	tb.setExitOrder(Order{ Limit{} });
	return tb.build();
}

