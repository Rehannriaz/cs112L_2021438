#include <iostream>
#include <string>

using namespace std;

int reversenum(int num)
{
    // to_string(num);
    string strnum = to_string(num);
    string rev;
    for (int i = strnum.length() - 1; i >= 0; i--)
    {
        rev.push_back(strnum[i]);
    }
    int finalnum = stoi(rev);
    return finalnum;
}
class Officer
{
private:
    static int count;
    int ID;
    string Name;
    string Rank;

public:
    Officer()
    {
        count++;
    }
    
    void setter(int id1 = 0, string name_ = "", string rank_ = "")
    {
        ID = id1;
        Name = name_;
        Rank = rank_;
    }
    void counter()
    {
        cout << "Number of Officers are = " << count;
    }

    void CheckID()
    {
        int rev = reversenum(ID);

        if (rev == ID)
        {
            cout << "\n\nThe Officer is not allowed to enter the restricted area";
        }
        else
            cout << "\n\nThe Officer is allowed to enter the restricted area";
    }
    ~Officer()
    {

    }
};
int Officer::count = -1;

void menu();
int main()
{
    Officer a;
    int input;
    do
    {
        menu();
        cin >> input;
        switch (input)
        {
        case 1:
        {
            Officer a1;
            int ID;
            string name, rank;
            cout << "Enter the ID of the officer: ";
            cin >> ID;
            cout << "Enter the Name of the officer: ";
            cin >> name;

            cout << "Enter the Rank of the officer: ";
            cin >> rank;
            a1.setter(ID, name, rank);

            a1.CheckID();
            break;
        }
        case 2:
        {
            a.counter();
            break;
        }
        case 3:
        {
            cout << "Program Exiting\n";
            return 0;
        }
        default:
        {
            cout << "Invalid Number inputted\n\n";
            break;
        }
        }
        cout << endl
             << endl;

    } while (1);
}

void menu()
{
    cout << "\n\nPlease Select the desired option\n\n";
    cout << "(1)Enter ID of officer\n";
    cout << "(2)Get Total Number Of Officers\n";
    cout << "(3)Exit\n\n";
}