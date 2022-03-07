#include <iostream>

using namespace std;

int main()
{
    int num;
    cout<<"Enter number of elements in Array: ";
    cin>>num;

    int *array = new int[num];

    cout<<"Enter Array: ";
    for(int i=0;i<num;i++)
    cin>>array[i];

    cout<<"Initial Array: ";
    for(int i=0;i<num;i++)
    cout<<array[i]<< " ";

    cout<<endl;
    int *resarray = new int[num-1];

    for(int i=0;i<num-1;i++)
    resarray[i]=array[i+1]-array[i];
    
    cout<<"Resultant Array: [ ";
    for(int i=0;i<num-1;i++)
    cout<<resarray[i]<< " ";
    cout<<"]\n";
}