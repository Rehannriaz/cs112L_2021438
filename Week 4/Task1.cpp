#include <iostream>

using namespace std;

class Swap
{
private:
    int a;
    int b;

public:
    void setter()
    {
        cout << "Enter the two values: ";
        cin >> a >> b;
    }
    void display()
    {
        cout<<"A = "<< a<<" & B = "<<b;
    }
    void Swapp()
    {
        a=a+b;  // a=3+2 = 5 3-2= 1
        b=a-b;  // b=5-2 = 3
        a=a-b;  // 5-3=2  1+2=3

    }
};


int main()
{
    Swap num;

    num.setter();
    cout<<"Before Swapping ";
    num.display();
    num.Swapp();
    cout<<"\nAfter Swapping ";
    num.display();


}