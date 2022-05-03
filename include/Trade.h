#pragma once

#include "BaseObject.h"
#include "DaedalusPrimitives.h"

class Trade :
    public BaseObject
{
public:
    std::string strategy;
    Order enter;
    Order exit;
    HistoryModule history;
    bool isAction;

public:
    std::string dumpJson();
    std::string getStrategyName();
    OrderTypes getExitType();
    Order getExitOrder();
    OrderTypes getEnterType();
    Order getEnterOrder();
};


