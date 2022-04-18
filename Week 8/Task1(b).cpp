#include <iostream>

using namespace std;

class BankAccount
{
protected:
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
    void PrintInfo()
    {
        printAcc();
        printBal();
    }
    void Deposit(double amount)
    {
        balance += amount;
    }
    void Withdraw(double amount)
    {
        balance -= amount;
    }
    ~BankAccount()
    {
        // destructor
    }
};

class checkingAccount : protected BankAccount
{
private:
    double interest;
    double minimumBalance;
    double serviceCharges;

public:
    checkingAccount(double inter, double min, double ser)
    {
        interest = inter;
        minimumBalance = min;
        serviceCharges = ser;
    }
    void checkingsetter(double inter, double min, double ser)
    {
        interest = inter;
        minimumBalance = min;
        serviceCharges = ser;
    }
    void printAcc()
    {
        PrintInfo();
        cout << "Interest Rate : " << interest << endl;
        cout << "Minimum Balance: " << minimumBalance << endl;
        cout << "Service Charges: " << serviceCharges << endl;
    }
    void Withdraw()
    {
        if (balance > minimumBalance)
            balance -= minimumBalance;
        else
            cout << "You do not have " << minimumBalance << " in your account, Please deposit first!";
    }
};

int main()
{
    // BankAccount a(1,2);
}