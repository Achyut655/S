#ifndef MARKET_H
#define MARKET_H

#include <map>
#include "Stock.h"

class Market {
public:
    std::map<std::string, Stock> stocks;

    void simulatePriceChanges();
    void addStock(Stock stock);
    void fetchHistoricalData(const std::string& symbol);
    double getPrice(const std::string& symbol); // Method to retrieve stock price
};

#endif
