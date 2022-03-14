#include <iostream>

using namespace std;

class parity
{
private:
    int size;
    int *array;
    int counter=0;

public:

    void put(int num);
    void print();
    void Delete(int num);
    int test();

    parity()
    {
        size=0;
        array=new int [size];
    }
    ~parity()
    {
        delete &size;
        delete &counter;
        delete [] array;
    }

};

void parity::put(int num)
{
    counter++;
    size++;
    int *temp= new int [size];
    int i=0;
    for(i;i<size-1;i++)
    {
    temp[i]=array[i];

    }
    delete [] array;
    temp[i]=num;
    array=temp;
}
void parity::print()
{
    cout<<"Values are: ";
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"\n\n";
    
}
void parity::Delete(int num)
{
    size--;
    int *temp=new int [size];
    int i=0;
    for(int i=0;i<size;i++)
    {
        temp[i]=array[i];
    }
    delete[] array;
    array=temp;
    

}
int parity::test()
{
    if(counter%2==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
 parity a1;
    int input;
    int num;
    while(1)
    {
        cout<<"\n(1) Put\n";
        cout<<"(2) Print\n";
        cout<<"(3) Delete\n";
        cout<<"(4) Test\n";
        cout<<"(5) Exit\n";

        cout<<"\n\n ENTER THE MENU YOU WOULD LIKE TO ENTER: ";
        cin>>input;

        if(input==1)
        {
            cout<<"Enter a Number: ";
            cin>>num;
            a1.put(num);
            cout<<"\n Number stored\n";
        }
        else if (input==2)
        {
            a1.print();
        }
        else if (input ==3)
        {
            a1.Delete(num);
            cout<<"Deleted\n\n";
        }
        else if (input ==4)
        {
            cout<<"Value returned = "<<a1.test();
            if(a1.test()==1)
                cout<<"\nEven number of puts have been done\n";
            else
                cout<<"\nOdd number of puts have been done\n";
        }
        else if (input ==5)
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
