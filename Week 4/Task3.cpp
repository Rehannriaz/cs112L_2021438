#include <iostream>
#include <iomanip>
using namespace std;

void menu();

class small_set
{
private:
    const static int size = 10;
    int num;
    int array[size];

public:
    void set(int item);
    void clear(int item);
    int test(int num);
    void print();
    void arrayfix()
    {
        for (int i = 0; i < size; i++)
        {
            array[i] = -1;
        }
    }
};
void small_set::set(int item)
{
    static int i = 0;
    if (item >= 0 && item <= 31)
    {
        array[i] = item;
        i++;
        cout << "Item Successfully Stored!\n";
    }
    else
        cout << "Invalid number Entered!\n";
}
void small_set::clear(int item)
{
    bool check=false;
    for (int i = 0; i < size; i++)
        if (array[i] == item)
        {
            array[i] = -1;
            check=true;
        }

    if(check)
    {
        cout<<"Cleared out successfully!\n";
    }
    else
    cout<<"not found!\n";

}
int small_set::test(int num)
{
    bool check = false;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == num)
        {
            check = true;
            break;
        }
        else
        {
            check = false;
        }
    }
    if (check)
        return 1;
    else
        return 0;
}

void small_set::print()
{
    cout << "Set contains [";
    for (int i = 0; i < size; i++)
        if (array[i] >= 0 && array[i] <= 31)
            cout << array[i] << ",";
    cout << "]\n";
}
int main()
{

    char input;
    int select_menu;
    cout << "Enter Y to start the program: ";
    cin >> input;

    if (tolower(input) == 'y')
    {
        small_set a_set;
        a_set.arrayfix();
        menu();
        cin >> select_menu;
        do
        {
            switch (select_menu)
            {
            case 1:
            {
                int item;
                cout << "\nEnter the element: ";
                cin >> item;
                a_set.set(item);

                break;
            }
            case 2:
            {
                int item;
                cout << "\nEnter the element in the set you would like to clear : ";
                cin >> item;
                a_set.clear(item);

                break;
            }
            case 3:
            {
                int item;
                cout << "\nEnter the element in the set you would like to see if it exists or not : ";
                cin >> item;
                cout << a_set.test(item) << endl
                     << endl;
                break;
            }
            case 4:
            {
                a_set.print();
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
        } while (1);
    }
    else
        cout << "Program Exiting!\n";
}

void menu()
{
    cout << "(1)Set an element in the set \n";
    cout << "(2)Clear an element in the set \n";
    cout << "(3)See whether an element is in set \n";
    cout << "(4)Print\n\n";
    // cout << "(5)Print\n\n";
    cout << setw(50) << "Enter the menu you would like to enter or enter -1 to exit:";
}