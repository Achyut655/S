#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <vector>

class Stock {
public:
    std::string symbol;
    double currentPrice;
    std::vector<double> historicalPrices;

    Stock();
    Stock(std::string sym, double price);
    void updatePrice(double newPrice);
    void addHistoricalPrice(double price);
    double calculateMovingAverage(int period);
};

#endif
