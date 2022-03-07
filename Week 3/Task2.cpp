#include <iostream>
using namespace std;
#define read(type, var) \
    type var;           \
    cin >> var;

int sechigh(int array[],int size);
int seclowest(int array[],int size);
int main()
{

    cout << "Enter Array Size: ";
    read(int, size);

    int *array = new int[size];
    // int highest, secondhighest, lowest, secondlowest;

    cout << "Enter Array Elements: ";
    for (int i = 0; i < size; i++)
        cin >> array[i];


    cout<<"Second lowest : "<< seclowest(array,size)<<endl;
    cout<<"Second Highest : "<< sechigh(array,size);
   
}
int sechigh(int array[],int size)
{
    int highest, secondhighest;

    if(array[0]>array[1])
    {
        highest=array[0];
        secondhighest=array[1];
    }
    else
    {
        highest=array[1];
        secondhighest=array[0];
    }

    for(int i=2;i<size;i++)
    {
        if(array[i]>highest)
        {
        secondhighest=highest;
        highest=array[i];
        }
        else if (array[i]<highest && array[i]>secondhighest && secondhighest!=highest)
        {
            secondhighest=array[i];
        }
    }

    return secondhighest;
}
int seclowest(int array[],int size)
{
    int lowest, secondlowest;

    if(array[0]<array[1])
    {
        lowest=array[0];
        secondlowest=array[1];
    }
    else
    {
        lowest=array[1];
        secondlowest=array[0];
    }

    for(int i=2;i<size;i++)
    {
        if(array[i]<lowest)
        {
        secondlowest=lowest;
        lowest=array[i];
        }
        else if (array[i]<lowest && array[i]>secondlowest && secondlowest!=lowest)
        {
            secondlowest=array[i];
        }
    }

    return secondlowest;
}
