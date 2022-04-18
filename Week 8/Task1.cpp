#include <iostream>

using namespace std;

class BankAccount
{
private:
    int accountNumber;
    double balance;

public:
    BankAccount() {}

    BankAccount(int AN, double B)
    {
        accountNumber = AN;
        balance = B;
    }
    void setter(int AN, double B)
    {
        accountNumber = AN;
        balance = B;
    }
    void printAcc()
    {
        cout << "Account Number : " << accountNumber;
        cout << endl;
    }
    void printBal()
    {
        cout << "Balance : " << balance;
        cout << endl;
    }
    void Deposit(double amount)
    {
        balance += amount;
    }
    void Withdraw(double amount)
    {
        if (balance > amount)
            balance -= amount;
        else
            cout << "You do not have " << amount << " in your account, Please deposit first!";
    }
    ~BankAccount()
    {
        // destructor
    }
};

int main()
{
}