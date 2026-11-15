#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class fintrackErrorHandler
{
public:
    inline void setSpendingLimit(const string &spending_limit, int &monthly_spending_limit)
    {
        if (spending_limit == "q" || spending_limit == "Q")
        {
            monthly_spending_limit = 0;
            cout << "> Spending Limit Skipped.";
            return;
        }

        try
        {
            monthly_spending_limit = stoi(spending_limit);
            if (monthly_spending_limit < 0)
            {
                throw invalid_argument("Invalid amount! Please enter a positive number");
            }
        }

        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << endl;
        }

        monthly_spending_limit = stoi(spending_limit);

        if (monthly_spending_limit < 0)
        {
            cout << "> Please Enter monthly spending limit again: ";
            cin >> monthly_spending_limit;
        }
    }

    inline void currencyChecker()
    {
        //
    }
};

#endif