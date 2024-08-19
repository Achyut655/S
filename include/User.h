#ifndef USER_H
#define USER_H

#include <string>
#include "Portfolio.h"
#include "Market.h"

class User {
public:
    std::string username;
    std::string password;
    Portfolio portfolio;

    User(std::string uname, std::string pwd);
    bool authenticate(std::string uname, std::string pwd);
    void buyStock(std::string symbol, int quantity, Market& market);
    void sellStock(std::string symbol, int quantity, Market& market);
    void analyzeStock(const std::string& symbol, Market& market);
};

#endif
