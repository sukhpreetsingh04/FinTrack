#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "ErrorHandler.h"
using namespace std;

class userInterfaceFintrack
{
public:
    string user_name;
    string preferred_currency;
    string primary_account_name;
    int current_balance;
    int monthly_spending_limit;
    string spending_limit;

public:
    inline void userInterface()
    {
        cout << "$ finTrack init " << endl;
        cout << endl;

        cout << "> Enter User Name: ";
        getline(cin, user_name);
        cin.ignore();

        cout << "> Preferred currency: ";
        getline(cin, preferred_currency);
        cin.ignore();

        cout << "> Enter Primary account name: ";
        getline(cin, primary_account_name);
        cin.ignore();

        cout << "> Current balance for " << primary_account_name << ": ";
        cin >> current_balance;

        cout << endl;

        cout << "> Set a monthly spending limit? (Press 'Q' to skip): ";
        cin >> spending_limit;

        fintrackErrorHandler fEH;
        fEH.setSpendingLimit(spending_limit, monthly_spending_limit);

        cout << endl;

        cout << "✅ Profile " << user_name << " created! Ready to track expenses." << endl;
    }
};

#endif