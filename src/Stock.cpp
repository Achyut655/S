#include "Stock.h"

Stock::Stock() : symbol(""), currentPrice(0.0) {}

Stock::Stock(std::string sym, double price) : symbol(sym), currentPrice(price) {}

void Stock::updatePrice(double newPrice) {
    currentPrice = newPrice;
    addHistoricalPrice(newPrice);
}

void Stock::addHistoricalPrice(double price) {
    historicalPrices.push_back(price);
}

double Stock::calculateMovingAverage(int period) {
    if (historicalPrices.size() < period) return 0.0;
    double sum = 0.0;
    for (int i = historicalPrices.size() - period; i < historicalPrices.size(); ++i) {
        sum += historicalPrices[i];
    }
    return sum / period;
}
