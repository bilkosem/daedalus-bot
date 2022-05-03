#include "Utils.h"
#include <chrono>
int TimeUtils::dummy() {
	std::cout << "dummy" << std::endl;
    return 0;
}

unsigned long long TimeUtils::getCurrentTimestamp() {
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
        );
    return ms.count();
}

unsigned long long TimeUtils::roundToPeriod(const unsigned long long& current_time, const unsigned long long& periodMinute, const bool toFloor, const unsigned long long offsetSecond) {

    unsigned long long next_time = current_time - (current_time % 60000);            //exact minute
    next_time -= (next_time % (periodMinute * 60000));                              //exact scale

    if (toFloor)
        return next_time + offsetSecond * 1000;
    else
        return next_time + periodMinute * 60000 + offsetSecond * 1000;
}