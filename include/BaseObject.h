#pragma once
#include <string>
class BaseObject
{
private:
	std::string id;
	std::string timestamp;
public:
	BaseObject();
	std::string getId();
	void setTimestamp(std::string ts);
	std::string getTimestamp();
	virtual std::string dumpJson() = 0;
};

