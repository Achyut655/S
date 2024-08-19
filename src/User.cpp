#include "User.h"
#include <iostream>

User::User(std::string uname, std::string pwd) : username(uname), password(pwd) {}

bool User::authenticate(std::string uname, std::string pwd) {
    return (username == uname && password == pwd);
}

void User::buyStock(std::string symbol, int quantity, Market& market) {
    double price = market.getPrice(symbol);
    if (price > 0) {
        portfolio.holdings[symbol] += quantity;
        std::cout << "Bought " << quantity << " shares of " << symbol << " at $" << price << " each." << std::endl;
    } else {
        std::cout << "Stock " << symbol << " not found in the market!" << std::endl;
    }
}

void User::sellStock(std::string symbol, int quantity, Market& market) {
    double price = market.getPrice(symbol);
    if (price > 0 && portfolio.holdings[symbol] >= quantity) {
        portfolio.holdings[symbol] -= quantity;
        std::cout << "Sold " << quantity << " shares of " << symbol << " at $" << price << " each." << std::endl;
    } else {
        std::cout << "Stock " << symbol << " not found or insufficient quantity!" << std::endl;
    }
}

void User::analyzeStock(const std::string& symbol, Market& market) {
    if (market.stocks.find(symbol) != market.stocks.end()) {
        double movingAverage = market.stocks[symbol].calculateMovingAverage(30); // 30-day moving average
        std::cout << "30-day moving average for " << symbol << ": $" << movingAverage << std::endl;
    } else {
        std::cout << "Stock " << symbol << " not found in the market!" << std::endl;
    }
}
