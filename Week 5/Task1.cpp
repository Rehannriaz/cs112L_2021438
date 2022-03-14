#include <iostream>

using namespace std;

class Heater
{
private:
int temperature;
public:
void tempset(int temp)
{
    temperature=temp;
}
void warmer()
{
    temperature +=5;
}
void cooler()
{
    temperature -=5;
}
void printer()
{
    cout<<"Temperature = "<< temperature;
}
Heater()
{
    temperature=15;
}
~Heater()
{
    // delete &temperature;
    cout<<"Destructor Called\n";
}

};

int main()
{
    Heater a1;
    int input;
    while(1)
    {
        cout<<"\n(1) Warmer\n";
        cout<<"(2) Cooler\n";
        cout<<"(3) Print Temperature\n";
        cout<<"(4) Exit\n";

        cout<<"\n\n ENTER THE MENU YOU WOULD LIKE TO ENTER: ";
        cin>>input;

        if(input==1)
        {
            a1.warmer();
        }
        else if (input==2)
        {
            a1.cooler();
        }
        else if (input ==3)
        {
            a1.printer();
        }
        else if (input ==4)
        {
            cout<<"Program Exiting\n\n";
            exit(1);
        }
        else
        {
            cout<<"Invalid Number entered\n";
        }



    }
    
}