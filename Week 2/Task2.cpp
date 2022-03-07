#include <iostream>
using namespace std;
#define read(type,var) type var; cin>>var;
#define pow(first,second) int answer=first<<second
// 5  2= 0101 shift left == 1010 == 10100 == 20

int main()
{
    cout<<"Enter first number: ";
    read(int,first);
    cout<<"Enter second number: ";
    read(int,second);
    pow(first,second);
    cout<<"The answer is " << answer;
}