// Practical 10 - Custom exceptions in banking
// Daksh Singh, Roll No 33, AIDS-C
#include <iostream>
#include <exception>
using namespace std;

class InvalidAmount : public exception {
public:
    const char* what() const noexcept { return "Amount must be more than 0"; }
};

class InsufficientFunds : public exception {
public:
    const char* what() const noexcept { return "Not enough balance"; }
};

class Account {
    float balance = 5000;
public:
    void withdraw(float amt) {
        if (amt <= 0) throw InvalidAmount();
        if (amt > balance) throw InsufficientFunds();
        balance -= amt;
        cout << "Withdrawn " << amt << ", balance = " << balance << endl;
    }
};

int main() {
    cout << "Name: Daksh Singh | Roll No: 33" << endl;

    Account acc;
    float tests[3] = {1000, -200, 9000};

    for (int i = 0; i < 3; i++) {
        try {
            acc.withdraw(tests[i]);
        }
        catch (InvalidAmount& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (InsufficientFunds& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    return 0;
}
