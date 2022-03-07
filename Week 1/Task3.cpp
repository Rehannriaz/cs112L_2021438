#include <iostream>

using namespace std;

// enum Months
// {
//     Jan = 1,
//     Feb,
//     Mar,
//     Apr,
//     May,
//     Jun,
//     Jul,
//     Aug,
//     Sep,
//     Oct,
//     Nov,
//     Dec
// };
struct DateOfBirth
{
    string month;
    int day;
    int year;
    int month1;
};
struct user_info
{
    string name;
    int age;
    string city;
    DateOfBirth DOB;
};
int monthchange(string m)
{
    if (m.compare("Jan") == 0)
        return 1;
    else if (m.compare("Feb") == 0)
        return 2;
    else if (m.compare("Mar") == 0)
        return 3;
    else if (m.compare("Apr") == 0)
        return 4;
    else if (m.compare("May") == 0)
        return 5;
    else if (m.compare("Jun") == 0)
        return 6;
    else if (m.compare("Jul") == 0)
        return 7;
    else if (m.compare("Aug") == 0)
        return 8;
    else if (m.compare("Sep") == 0)
        return 9;
    else if (m.compare("Oct") == 0)
        return 10;
    else if (m.compare("Nov") == 0)
        return 11;
    else if (m.compare("Dec") == 0)
        return 12;
    else
        return 13;
}
int main()
{
    // Today's Date= 14-2-2022
    DateOfBirth check;
    user_info a[3];
    for (int i = 0; i < 1; i++)
    {
        string month = "";
        cout << "Enter the record of " << i + 1 << " user:\n";
        cout << "Enter the name: ";
        cin >> a[i].name;
        cout << "Enter the age: ";
        cin >> a[i].age;
        cout << "Enter the city: ";
        cin >> a[i].city;
        cout << "Enter the D.O.B:\n ";
        cout << "Enter day: ";
        cin >> a[i].DOB.day;
        if(a[i].DOB.day>31)
        {
            cout << "day does not exist!\nProgram Exiting!";
            exit(1);
        }
        cout << "Enter Month: ";
        cin >> a[i].DOB.month;
        a[i].DOB.month1 = monthchange((a[i].DOB.month));
        if (a[i].DOB.month1 == 13)
        {
            cout << "Month does not exist!\nProgram Exiting!";
            exit(1);
        }
        cout << "Enter Year: ";
        cin >> a[i].DOB.year;
        if (a[i].DOB.year > 2022 && a[i].DOB.year < 1900)
        {
            cout << "Error\nProgram Exiting!";
            exit(1);
        }
    }
    bool check1 = false;
    cout << "Enter a D.O.B to check: ";
    cout << "Enter day: ";
    cin >> check.day;
    cout << "Enter Month: ";
    cin >> check.month;
    check.month1 = monthchange((check.month));
        if (check.month1 == 13)
        {
            cout << "Month does not exist!\nProgram Exiting!";
            exit(1);
        }
    cout << "Enter Year: ";
    cin >> check.year;
    for (int i = 0; i < 3; i++)
    {
        if (a[i].DOB.day == check.day)
        {
            if (a[i].DOB.month1 == check.month1)
            {
                if (a[i].DOB.year == check.year)
                {
                    cout << "\nIt is " << a[i].name << "'s Birthday. Happy Birthday, " << a[i].name<<".";
                    check1 = true;
                }
            }
        }
    }
    if(check1==false)
    cout<<"No ones Birthday on this day!";
}
