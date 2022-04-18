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
        cout << "Balance : " << balance << "PKR";
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
        cout<<"amount of "<< amount<<" has been successfully added!\n";
    }
    void withdraw(double amount)
    {
        balance -= amount;
    }
    ~BankAccount()
    {
        // destructor
    }
};

class checkingAccount : public BankAccount
{
private:
    double interest;
    double minimumBalance;
    double serviceCharges;

public:
    checkingAccount(int AN = 0, double bal = 0, double inter = 0, double min = 0, double ser = 0) : BankAccount(AN, bal)
    {
        // serviceCharges=100;
        setServiceCharges(ser);
        setInt(inter);
        setMinimum(min);
    }
    void setInt(double inter = 0)
    {
        interest = inter;
    }
    void setMinimum(double min = 0)
    {
        minimumBalance = min;
    }
    void setServiceCharges(double ser = 0)
    {
        serviceCharges = ser;
    }

    void printacc()
    {
        PrintInfo();
        cout << "Interest Rate : " << interest << endl;
        cout << "Minimum Balance: " << minimumBalance << "PKR" << endl;
        cout << "Service Charges: " << serviceCharges << "PKR" << endl;
    }
    void withdraw(double amount)
    {
        if (balance >= minimumBalance)
            balance -= amount;
        else
        {
            cout << "You do not have " << minimumBalance << " in your account, Service Charges Applied\n";
            balance = balance - serviceCharges;

            printAcc();
        }
    }

    ~checkingAccount() {}
};
class savingsAccount : protected BankAccount
{
protected:
    double interest;
    double postInterest;

public:
    savingsAccount(int AN, double Bal, double inter = 0, double postInter = 0) : BankAccount(AN, Bal)
    {
        setInt(inter);
        setPostInt(postInter);
    }
    void setInt(double inter = 0)
    {
        interest = inter;
    }
    void setPostInt(double postInter = 0)
    {
        postInterest = postInter;
        postInterest = balance - (balance * interest);
    }
    void setters(double inter, double postInter)
    {
        interest = inter;
        postInterest = postInter;
    }
    void getPostInterest()
    {

        cout << "Post Interest: " << postInterest << endl;
    }
    void getInterest()
    {
        cout << "Interest: " << interest << endl;
    }

    void Print()
    {
        PrintInfo();
        getPostInterest();
        getInterest();
    }
    void withdraw(double amount)
    {
        balance -= amount;
    }
    ~savingsAccount()
    {
        // destructor
    }
};
void menu()
{
    // cout<<"\n";

}
int main()
{
    // account number, balance, interest rate, minimumBalance, service Charges
    // cout<<"CHECKING ACCOUNT:\n\n";
    checkingAccount A(5195, 30000, 1.5, 100, 5);
    savingsAccount B(2931,50000,1.87,0);
    cout<<"CHECKING ACCOUNT\n";
    A.PrintInfo();
    A.Deposit(5000);
    A.printBal();
    A.withdraw(5000);





    // int input;
    // do
    // {
    //     cout << "WELCOME TO GIKI BANKING SYSTEM \n\n";
    //     menu();
    //     cin >> input;

    //     switch(input)
    //     {
    //         case 1:
    //         {
                
    //             break;
    //         }
    //         case 2:
    //         {
    //             break;
    //         }
    //         case 3:
    //         {
    //             break;
    //         }
    //         case 4:
    //         {
    //             break;
    //         }
    //         case 5:
    //         {
    //             break;
    //         }
    //     }



    // } while (1);
}