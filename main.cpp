#include <iostream>
#include "User.h"
#include "Market.h"

int main() {
    Market market;
    User user("testuser", "password123");

    market.fetchHistoricalData("AAPL");
    market.fetchHistoricalData("GOOGL");

    user.buyStock("AAPL", 10, market);
    user.buyStock("GOOGL", 5, market);

    std::cout << "User's total portfolio value: $" << user.portfolio.calculateTotalValue(market.stocks) << std::endl;

    user.analyzeStock("AAPL", market);
    user.analyzeStock("GOOGL", market);

    user.sellStock("AAPL", 5, market);
    std::cout << "User's total portfolio value after selling: $" << user.portfolio.calculateTotalValue(market.stocks) << std::endl;

    return 0;
}
