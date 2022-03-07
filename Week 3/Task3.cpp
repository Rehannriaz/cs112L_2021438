#include <iostream>

using namespace std;

int main()
{
    int size;
    cout << "Enter Array size :";
    cin >> size;
    int *array = new int[size];
    cout << "Enter Array elements: ";
    for (int i = 0; i < size; i++)
        cin >> array[i];
    cout << "Input Array: ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";

    int *cpyarray = new int[size];

    // for(int i=0;i<size;i++)
    int index;
    int i = 0;
    for (int j = 0; j < size; j++)
        if (array[j] > 0)
            cpyarray[i++] = array[j];

  
    for (int k = 0; k < size; k++)
        if (array[k] < 0)
            cpyarray[i++] = array[k];

    cout<<endl<<"Your Array: ";
    for(int a=0;a<size;a++)
    cout<<cpyarray[a]<<" ";
}