#include <iostream>
#include <string>
using namespace std;

class FinTrack {
public:
    string user_name;
    string preferred_currency;
    string primary_account_name;
    int current_balance;
    int monthly_spending_limit;
    string spending_limit;

public:
    void Interface() {
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

        if (spending_limit == "q" || spending_limit == "Q") {
            cout << "\nspending limit skipped!\n";
        }
        else {
            monthly_spending_limit = stoi(spending_limit);
            cout << "> Monthly spending limit set to: " << monthly_spending_limit << endl;
        }

        cout << endl;

        cout << "✅ Profile " << user_name << " created! Ready to track expenses." << endl;
    }
};

int main() {
    FinTrack Fnt;
    Fnt.Interface();
}