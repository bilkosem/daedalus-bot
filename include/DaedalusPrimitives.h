#pragma once
#include <variant>
enum class OrderTypes { MARKET, LIMIT, OCO };

struct Market {
    int quantity;
    int fee;
    int orderId;
};

struct Limit {
    int price;
    int quantity;
    int amount;
    int fee;
    int orderId;
    int expire;
};

struct OCO {
    int price;
    int quantity;
    int amount;
    int fee;
    int orderId;
    int expire;
};

using Order = std::variant<Market, Limit, OCO>;

struct Record {
    OrderTypes type;

    int price;
    int quantity;
    int amount;
    int fee;
    int orderId;
};


struct HistoryModule {
    Record enter;
    Record exit;
    int profit;
    int lifeTime;
};