// Practical 2 - Class and access specifiers
// Daksh Singh, Roll No 33, AIDS-C
#include <iostream>
using namespace std;

class BankAccount {
private:            // private so nobody can change balance directly
    int accNo;
    float balance;

public:             // public functions to use the account
    BankAccount(int a, float b) {
        accNo = a;
        balance = (b < 0) ? 0 : b;
    }

    void deposit(float amt) {
        if (amt > 0) balance += amt;
        else cout << "Invalid amount" << endl;
    }

    void withdraw(float amt) {
        if (amt > balance) cout << "Not enough balance" << endl;
        else balance -= amt;
    }

    void show() {
        cout << "Account " << accNo << " balance = " << balance << endl;
    }
};

int main() {
    cout << "Name: Daksh Singh | Roll No: 33" << endl;

    BankAccount a(101, 5000);
    BankAccount b(102, 2000);

    a.deposit(1000);
    a.withdraw(2500);
    b.withdraw(3000);
    b.deposit(-50);

    a.show();
    b.show();
    return 0;
}
