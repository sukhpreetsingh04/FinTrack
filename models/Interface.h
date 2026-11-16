#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "ErrorHandler.h"
#include <cctype>
#include <iomanip>
using namespace std;

class FinTrackInterface
{
private:
    string user_name;
    string preferred_currency;
    string primary_account_name;
    int current_balance;
    int monthly_spending_limit;
    string spending_limit;

public:
    inline void userInterface()
    {
        cout << "\n$ finTrack init " << endl;

        cout << "> Enter User Name: ";
        getline(cin, user_name);

        for (char &c : user_name)
        {
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        }

        cout << "> Preferred currency: ";
        getline(cin, preferred_currency);

        for (char &c : preferred_currency)
        {
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        }

        cout << "> Enter Primary account name: ";
        getline(cin, primary_account_name);

        for (char &c : primary_account_name)
        {
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        }

        cout << "> Current balance for " << primary_account_name << " account : ";
        cin >> current_balance;
        cin.ignore();

        cout << "> Set a monthly spending limit? (Press 'Q' to skip): ";
        getline(cin, spending_limit);

        fintrackErrorHandler fEH;
        fEH.setSpendingLimit(spending_limit, monthly_spending_limit);

        cout << "✅ Profile " << user_name << " created! Ready to track expenses." << endl;
    }

    inline void FinTrackWindow()
    {
        const string GREEN_BOLD = "\033[1;32m";
        const string RESET     = "\033[0m";

        cout << "\n --------------------------- " << GREEN_BOLD << "FINTRACK" << RESET << " --------------------------" << '\n';

        cout << " | > Welcome, " << left << setw(49) << user_name << "|" << '\n';

        cout << " | > Account: " << left << setw(49) << primary_account_name << "|" << '\n';

        string balance_text = to_string(current_balance) + " " + preferred_currency;

        cout << " | > Current Balance: " << left << setw(41) << balance_text << "|" << '\n';

        balance_text = spending_limit + " " + preferred_currency;

        cout << " | > Spending Limit: " << left << setw(42) << spending_limit << "|" << '\n';

        cout << " ---------------------------------------------------------------" << '\n';
    }
};

#endif