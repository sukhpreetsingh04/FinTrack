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
        string input = spending_limit;

        while (true)
        {
            // Check if user wants to quit/skip at any point
            if (input == "q" || input == "Q")
            {
                monthly_spending_limit = 0;
                cout << "> Spending Limit Skipped." << endl;
                return;
            }

            try
            {
                size_t pos = 0;
                int temp_limit = stoi(input, &pos);

                // Reject trailing characters like "123abc" or spaces
                if (pos != input.length())
                {
                    throw invalid_argument("Please enter digits only (no letters or symbols).");
                }

                // Reject negative numbers
                if (temp_limit < 0)
                {
                    throw invalid_argument("Invalid amount! Please enter a positive number.");
                }

                // All checks passed: save and exit the loop
                monthly_spending_limit = temp_limit;
                cout << "> Spending Limit added: " << monthly_spending_limit << endl;
                return;
            }
            catch (const invalid_argument &e)
            {
                // Handles non-digits ("abc"), trailing chars ("123abc"), and negative numbers
                cerr << "Error: " << e.what() << endl;
            }
            catch (const out_of_range &e)
            {
                cerr << "Error: Number is too large. Please enter a smaller amount." << endl;
            }

            // Prompt again and read the full line as a string for the next loop iteration
            cout << "> Please enter monthly spending limit again (or 'q' to skip): ";
            
            if (cin.peek() == '\n') 
            {
                cin.ignore();
            }
            getline(cin, input);
        }
    }
};

#endif