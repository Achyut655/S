#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <map>
#include <string>
#include "Stock.h"

class Portfolio {
public:
    std::map<std::string, int> holdings;

    double calculateTotalValue(const std::map<std::string, Stock>& marketStocks);
};

#endif
