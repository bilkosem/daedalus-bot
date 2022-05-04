#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <ctime>
#include <future> // https://baptiste-wicht.com/posts/2017/09/cpp11-concurrency-tutorial-futures.html
#include "utils.h"
#include "strategies/InheritedStrategy.h"

#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <nlohmann/json.hpp>
#include <ta-lib/ta_libc.h>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

using json = nlohmann::json;
namespace pt = boost::property_tree;
pt::ptree configRoot;
pt::ptree credRoot;

void application(unsigned long long daedalus_ts) {

    std::this_thread::sleep_for(std::chrono::seconds(7));
}

void testJson() {
    json j =
    {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {
            "answer", {
                {"everything", 42}
            }
        },
        {"list", {1, 0, 2}},
        {
            "object", {
                {"currency", "USD"},
                {"value", 42.99}
            }
        }
    };

    // add new values
    j["new"]["key"]["value"] = { "another", "list" };

    // count elements
    auto s = j.size();
    j["size"] = s;

    // pretty print with indent of 4 spaces
    std::cout << std::setw(4) << j << '\n';
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

void testTalib() {
    std::vector <double> vec;

    //Technical analysis part of the code
    int n = vec.size();  //size of the vector
    std::cout << "size " << n << ' ';
    TA_RetCode retCode;
    retCode = TA_Initialize();
    if (retCode != TA_SUCCESS)
        std::cout << "Cannot initialize TA-Lib !\n" << retCode << "\n";
    else
    {
        std::cout << "TA-Lib correctly initialized.\n";

        /* ... other TA-Lib functions can be used here. */
        std::vector<double> close_price;
        double new_close = 655361;
        close_price.push_back(new_close);
        std::vector<TA_Real> a(655360, 0.0);
        std::vector<TA_Real> b(655360, 0.0);
        std::vector<TA_Real> c(655360, 0.0);
        int s, n;
        TA_RetCode retCode = TA_MACD(0, close_price.size()-1, close_price.data(), 3, 12, 1, &s, &n, a.data(), b.data(), c.data());
        assert(retCode == TA_SUCCESS);

    }
}

int main()
{
    testTalib();
    parseConfig();
    testJson();
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