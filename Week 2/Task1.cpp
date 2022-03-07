#include <iostream>
#include <bitset>
#define read(type,var) type var; cin>>var;
using namespace std;
#define PowCheck(num) if(num&(num-1)) { cout<<"No "<<num<< " is not the power of 2";} else {cout<<"Yes "<< num<< " is the power of 2";}

int main()
{
    cout<<"Please enter number: ";
    read(int,num);
    PowCheck(num);
}
   



















// bool Powercheck(int num)
// {
//     if(!(num&(num-1)))
//     {
//         return true;
//     }
//     else
//     {
//     return false;

//     }
    
// }
    // check=PowCheck(num);
    // if(check)
    // {
    //     cout<<"Yes "<< num<< " is the power of 2";
    // }
    // else 
    //     cout<<"No "<<num<< " is not the power of 2";
 // #if PowCheck(num)
    //         #if(!(num&(num-1))
    //     {
    //         return true;
    //     }
    //     #else
    //     {
    //         return false;
    //     }

    // #endif
