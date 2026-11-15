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
        try
        {
            monthly_spending_limit = stoi(spending_limit);
            if (monthly_spending_limit < 0)
            {
                cout << endl;
                throw invalid_argument("Invalid amount! Please enter a positive number");
            }
        }

        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << endl;
        }

        cout << endl;
        
        cout << "> Please Enter monthly spending limit again: ";
        cin >> monthly_spending_limit;
    }
};

#endif