#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "ErrorHandler.h"
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

        cout << "> Preferred currency: ";
        getline(cin, preferred_currency);

        cout << "> Enter Primary account name: ";
        getline(cin, primary_account_name);

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
        cout << "\n ---------- FINTRACK ----------" << endl;
        cout << " > Welcome, " << user_name << endl;
        cout << " > Current Balance: " << current_balance << " " << preferred_currency << endl;
    }
};

#endif