#include <iostream>
#include <iomanip>
using namespace std;

void menu();

class twoDArray
{

private:
    const static int size = 2;
    int a[size][size];

public:
    void Initialize()
    {
        cout << "\n Enter the values, size = " << size << endl;

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                cin >> a[i][j];
    }
    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                cout << a[i][j]<<"\t";
            cout<<endl;
        }

    }
    void Transpose()
    {
        int temp[size][size];

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                temp[i][j]=a[j][i];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                a[i][j]=temp[i][j];

        
        cout<<"Matrix has been Transposed\n\n";
    }
    void isSymmetry()
    {
        int temp[size][size];
        bool check=false;
         for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                temp[i][j]=a[j][i];
         for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
            {
                if(a[i][j]==temp[i][j])
                check=true;
                else
                {
                check=false;
                break;
                }
            }
        if(check)
        cout<<"The matrix is Symmetric\n\n";
        else
        cout<<"The matrix is NOT Symmetric\n\n";   

    }
    twoDArray multiply(twoDArray obj1, twoDArray obj2)
    {
        twoDArray Ans;
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++)
                for(int k=0;k<size;k++)
                {
                Ans.a[i][j]=Ans.a[i][j]*0;
                Ans.a[i][j]=Ans.a[i][j]+(obj1.a[i][k]*obj2.a[k][i]);

                }
        return Ans;
    }
};

int main()
{
    char input;
    int select_menu;
    cout << "Enter Y to start the program: ";
    cin >> input;

    if (tolower(input) == 'y')
    {
        twoDArray test;
        // test.Initialize();
        menu();
        cin >> select_menu;
        do
        {   
            switch(select_menu)
            {
            case 1:
            {
                test.Initialize();
                break;
            }
            case 2:
            {
                test.Transpose();

                break;
            }
            case 3:
            {
                test.isSymmetry();
                break;
            }
            case 4:
            {
                twoDArray obj1,obj2;
                obj1.Initialize();
                obj2.Initialize();
                test=test.multiply(obj1,obj2);

                cout<<"Multiplied Succesfully!\n";
                break;
            }
            case 5:
            {
                test.Print();
                break;
            }

            case -1:
            {
                system("CLS");
                cout << "Program Exiting...\n\n";
                exit(1);
            }
            default:
                cout << setw(50) << "Invalid Input...Try Again: \n";
            }


            menu();
            cin >> select_menu;
        }while(1);







    }
    else
        cout << "Program Exiting";
}

void menu()
{
    cout << "(1)Initialize \n";
    cout << "(2)Transpose \n";
    cout << "(3)Symmetric \n";
    cout << "(4)Multiplication \n";
    cout << "(5)Print\n\n";
    cout << setw(50) << "Enter the menu you would like to enter or enter -1 to exit:";
}