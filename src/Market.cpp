#include "Market.h"
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void Market::fetchHistoricalData(const std::string& symbol) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, ("https://api.example.com/historical?symbol=" + symbol).c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        else {
            auto json = nlohmann::json::parse(readBuffer);
            for (const auto& price : json["prices"]) {
                addStock(Stock(symbol, price.get<double>()));
            }
        }
        curl_easy_cleanup(curl);
    }
}

double Market::getPrice(const std::string& symbol) {
    if (stocks.find(symbol) != stocks.end()) {
        return stocks[symbol].currentPrice;
    }
    return 0.0;
}

void Market::simulatePriceChanges() {
    // Implementation to simulate price changes
}

void Market::addStock(Stock stock) {
    stocks[stock.symbol] = stock;
}
