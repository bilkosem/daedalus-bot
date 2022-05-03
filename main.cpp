#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <ctime>
#include <future> // https://baptiste-wicht.com/posts/2017/09/cpp11-concurrency-tutorial-futures.html
#include "utils.h"
//#include "BinanceManager.h"
#include "strategies/InheritedStrategy.h"

#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace pt = boost::property_tree;
pt::ptree configRoot;
pt::ptree credRoot;

void application(unsigned long long daedalus_ts) {

    std::this_thread::sleep_for(std::chrono::seconds(7));
}

void applicationMock() {

    // Create rawdata objects

    // Create analysis objects

    // Create trade instances
    auto ih = InheritedStrategy();
    Trade trade = ih.evaluate();

    if (trade.getExitType() == OrderTypes::LIMIT) {
        Market a = std::get<Market>(trade.getExitOrder());
    }

}

void parseConfig() {

    pt::read_json("/mnt/c/Users/bilko/github/daedalus-bot/config/default.json", configRoot);
    std::string logLevel = configRoot.get<std::string>("log-level");
    std::cout << configRoot.get<std::string>("mongodb.clean") << std::endl;
    /*
    // Iterate on children of a node
    BOOST_FOREACH(const pt::ptree::value_type & v,
        configRoot.get_child("mongodb"))
    {
        std::cout << v.first << " : " << v.second.data() << std::endl;
    }

    // Iterate over a list
    BOOST_FOREACH(pt::ptree::value_type& itemPair, configRoot.get_child("time_scales.1m")) {
        std::cout << itemPair.second.get_value<std::string>() << " ";
    }
    */
}



int main()
{
    parseConfig();
    applicationMock();
    // TODO: Parse the config file
    // Mock varaibles: 
    uint16_t daedalus_period = 1; // 15min

    while (1) {
        unsigned long long daedalus_ts = TimeUtils::getCurrentTimestamp();
        unsigned long long wakeup_ts = TimeUtils::roundToPeriod(daedalus_ts, daedalus_period, false, 0);
        std::cout << "Sleeping for " << (wakeup_ts - daedalus_ts) / 1000 << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(wakeup_ts - daedalus_ts));
        std::cout << "Woke up now " << TimeUtils::getCurrentTimestamp() << " seconds" << std::endl;
        application(wakeup_ts);
    }

}