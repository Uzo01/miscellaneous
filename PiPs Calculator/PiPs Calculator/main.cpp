#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;

// Function to calculate pip value
double calculatePipValue(double lotSize, double marketValue, string pair) {
    map<string, double> pipFactors = {
        {"GBPUSD", 0.0001},
        {"NZDUSD", 0.0001},
        {"USDJPY", 0.01},
        {"GBPJPY", 0.01},
        {"US30", 1},      // US30 moves in whole numbers
        {"XAUUSD", 0.1},  // Gold moves in 0.1 increments
        {"XAGUSD", 0.01}  // Silver moves in 0.01 increments
    };

    if (pipFactors.find(pair) == pipFactors.end()) {
        cout << "Error: Unsupported trading pair. Please try again.\n";
        return -1;
    }

    double pipFactor = pipFactors[pair];
    return (lotSize * 10 * pipFactor) / marketValue;
}

int main() {
    char choice;
    do {
        double balance, marketValue, lotSize, tpPips, slPips;
        string pair, tradeType;

        cout << "Enter the trading pair (e.g., GBPUSD, NZDUSD, USDJPY, GBPJPY, US30, XAUUSD, XAGUSD): ";
        cin >> pair;
        transform(pair.begin(), pair.end(), pair.begin(), ::toupper);

        cout << "Are you going long (buy) or short (sell)? (buy/sell): ";
        cin >> tradeType;
        transform(tradeType.begin(), tradeType.end(), tradeType.begin(), ::tolower);

        if (tradeType != "buy" && tradeType != "sell") {
            cout << "Error: Invalid trade type. Please enter 'buy' or 'sell'.\n";
            continue;
        }

        cout << "Enter account balance (in USD): ";
        if (!(cin >> balance) || balance <= 0) {
            cout << "Error: Invalid balance input.\n";
            cin.clear(); cin.ignore(10000, '\n'); continue;
        }

        cout << "Enter lot size (e.g., 0.01, 0.1, 1): ";
        if (!(cin >> lotSize) || lotSize <= 0) {
            cout << "Error: Invalid lot size input.\n";
            cin.clear(); cin.ignore(10000, '\n'); continue;
        }

        cout << "Enter market value: ";
        if (!(cin >> marketValue) || marketValue <= 0) {
            cout << "Error: Invalid market value input.\n";
            cin.clear(); cin.ignore(10000, '\n'); continue;
        }

        cout << "Enter Take Profit (TP) in pips (decimal allowed): ";
        if (!(cin >> tpPips) || tpPips <= 0) {
            cout << "Error: Invalid TP input.\n";
            cin.clear(); cin.ignore(10000, '\n'); continue;
        }

        cout << "Enter Stop Loss (SL) in pips (decimal allowed): ";
        if (!(cin >> slPips) || slPips <= 0) {
            cout << "Error: Invalid SL input.\n";
            cin.clear(); cin.ignore(10000, '\n'); continue;
        }

        double pipValue = calculatePipValue(lotSize, marketValue, pair);
        if (pipValue == -1) continue;

        double pipMove = (pair == "USDJPY" || pair == "GBPJPY") ? 0.01 :
            (pair == "US30") ? 1 :
            (pair == "XAUUSD") ? 0.1 :
            (pair == "XAGUSD") ? 0.01 : 0.0001;

        double tpMarketValue = (tradeType == "buy") ? marketValue + (tpPips * pipMove) : marketValue - (tpPips * pipMove);
        double slMarketValue = (tradeType == "buy") ? marketValue - (slPips * pipMove) : marketValue + (slPips * pipMove);

        double profit = tpPips * pipValue;
        double loss = slPips * pipValue;

        cout << fixed << setprecision(2);
        cout << "\n--- Trade Analysis ---\n";
        cout << "Trading Pair: " << pair << "\n";
        cout << "Trade Type: " << (tradeType == "buy" ? "BUY (Going Long)" : "SELL (Going Short)") << "\n";
        cout << "Pip Value: $" << pipValue << " per pip\n";
        cout << "Potential Profit: $" << profit << "\n";
        cout << "Potential Loss: $" << loss << "\n";
        cout << setprecision(5);
        cout << "Market Value at TP: " << tpMarketValue << "\n";
        cout << "Market Value at SL: " << slMarketValue << "\n";

        cout << "\nWould you like to calculate another trade? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Goodbye!" << endl;
    return 0;
}
