#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Account {
private:
    string name;
    char type;
    double limit;
    vector<double> balance;
public:
    double getLimit() const;

    const string &getName() const;

    char getType();

    Account() = default;

    Account(char t, const string &s) {
        name = s;
        type = t;
        if (type == 'n') {
            limit = 0;
        } else {
            limit = -100000; //can be expanded if the account holder shows to pay its debts  ^^
        }
    }

    double getBalance() {
        double totalDeposit = accumulate(balance.begin(), balance.end(), 0.0);
        return totalDeposit;
    }

    void setBalance(double amount) {
        balance.push_back(amount);
    }
};

//-----------------------------------------------
// Getter and Setters
//-----------------------------------------------
char Account::getType() {
    return type;
}

double Account::getLimit() const {
    return limit;
}

const string &Account::getName() const {
    return name;
}

//-----------------------------------------------
// Objects Creation
//-----------------------------------------------
vector<Account> acccount_active;

//-----------------------------------------------
// Test functions
//-----------------------------------------------
bool doesTheAccountExists(const string &name) {
    for (std::vector<int>::size_type i = 0; i != acccount_active.size(); i++) {
        if (name == acccount_active[i].getName()) {
            return true;
        }
    }
}

bool isBalancePositive(const string &name) {
    for (std::vector<int>::size_type i = 0; i != acccount_active.size(); i++) {
        if (name == acccount_active[i].getName()) {
            if (acccount_active[i].getBalance() > 0) {
                return true;
            }
        }
    }
}

bool isTheTransactionAllowed(const string &name, double amount) {
    for (int i = acccount_active.size(); i >= 0; --i) {
        if (name == acccount_active[i].getName()) {
            double balance = acccount_active[i].getBalance();
            if (acccount_active[i].getType()=='n') {
                double net_user_balance = balance += amount;
                return net_user_balance >= 0;
            }else{
                return true;
            }
        }
    }

}

//-----------------------------------------------
// Error handling
//-----------------------------------------------
void errorHandling(char errorType, int lineNumber) {
    switch (errorType) {
        case 'n':
            cerr << "Error on Line " << lineNumber << ": account cannot hold negative balance" << endl;//transaction

            break;
        case 'x':
            cerr << "Error on Line " << lineNumber << ": account does not exist" << endl; //remove account, transaction

            break;
        case 'e':
            cerr << "Error on Line " << lineNumber << ": account already exists" << endl; //create account,

            break;
        case 'z':
            cerr << "Error on Line " << lineNumber << ": account holds negative balance" << endl; //remove account,

            break;
    }
}

//-----------------------------------------------
// Bank functions
//-----------------------------------------------

void pushBalance(const string &name, double amount) {
    for (std::vector<int>::size_type i = 0; i != acccount_active.size(); i++) {
        if (name == acccount_active[i].getName()) {
            acccount_active[i].setBalance(amount);
        }
    }
}

void createAccount(const string &name, char type, int lineNumber) {
    bool doesExists = doesTheAccountExists(name);
    if (doesExists) {
        errorHandling('e', lineNumber);
    } else {
        Account account(type, name);
        acccount_active.push_back(account);
    }
};

void makeTransaction(const string &name, int lineNumber, double amount) {
    bool doesExists = doesTheAccountExists(name);
    bool isTransactionallowed = isTheTransactionAllowed(name, amount);
    if (doesExists && isTransactionallowed) {
        pushBalance(name, amount);
    } else if (doesExists == false) {
        errorHandling('x', lineNumber);
    } else {
        errorHandling('n', lineNumber);
    }
}

void removeAccount(const string &name, int lineNumber) {
    bool doesExists = doesTheAccountExists(name);
    bool positiveBalance = isBalancePositive(name);
    if (doesExists && positiveBalance) {
        for (int i = acccount_active.size(); i >= 0; --i) {
            if (name == acccount_active[i].getName()) {
                acccount_active.erase(acccount_active.begin() + i);
            }
        }
    } else if (positiveBalance == false) {
        errorHandling('z', lineNumber);
    } else {
        errorHandling('x', lineNumber);
    }
}

void printSummary() {
    for (std::vector<int>::size_type i = 0; i != acccount_active.size(); i++) {
        if (acccount_active[i].getBalance() > 0) {
            cout << acccount_active[i].getName() << " own " << acccount_active[i].getBalance() << " euros." << endl;
        } else {
            cout << acccount_active[i].getName() << " owes " << acccount_active[i].getBalance() << " euros." << endl;
        }
    }
}

void parseLogs() {
    char action;
    string name;
    char type;
    double amount = 0;
    int lineNumber = 0;

    while (cin >> action) {
        ++lineNumber;
        if (action == 'c') {
            cin >> name >> type;
            createAccount(name, type, lineNumber);
            cin.clear();
        } else if (action == 't') {
            cin >> name >> amount;
            makeTransaction(name, lineNumber, amount);
            cin.clear();
        } else if (action == 'r') {
            cin >> name;
            removeAccount(name, lineNumber);
            cin.clear();
        }
    }
    printSummary();
}

int main() {
    parseLogs();
    return 0;
}
