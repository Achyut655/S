#include "Portfolio.h"

double Portfolio::calculateTotalValue(const std::map<std::string, Stock>& marketStocks) {
    double totalValue = 0.0;
    for (const auto& holding : holdings) {
        std::string symbol = holding.first;
        int quantity = holding.second;
        totalValue += marketStocks.at(symbol).currentPrice * quantity;
    }
    return totalValue;
}
