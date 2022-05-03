#pragma once
#include "BaseStrategy.h"
class InheritedStrategy :
    public BaseStrategy
{
public:
    Trade evaluate();
};

