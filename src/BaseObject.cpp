#include "BaseObject.h"

BaseObject::BaseObject()
{
}

std::string BaseObject::getId()
{
	return id;
}

std::string BaseObject::getTimestamp()
{
	return timestamp;
}

void BaseObject::setTimestamp(std::string ts)
{
	timestamp = ts;
}
