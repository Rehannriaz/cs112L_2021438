#include <iostream>

using namespace std;
class Person;
class Date;

class Date
{
    friend class Person;

private:
    int year;
    int month;
    int day;

public:
    Date(int y = 0, int m = 0, int d = 0)
    {
        year = y;
        month = m;
        day = d;
    }

    friend istream &operator>>(istream &input, Date &a)
    {
        input >> a.year;
        input >> a.month;
        input >> a.day;
        return input;
    }
    bool validDate()
    {
        if(year>=1960 && year<2023)
            if(month<=12 && month >=1)
                if(day>=1 && day<=31)
                    return true;
        else 
            return false;
        
        return false;
    }
    void dateoutput()
    {
        cout << year << "-" << month << "-" << day;
    }
    friend ostream &operator<<(ostream &output, Date &a)
    {
        output << a.year << "-" << a.month << "-" << a.day;
        return output;
    }

    bool operator<(Date &d)
    {
        if (year < d.year)
            return true;
        else if (year > d.year)
            return false;
        else if (month < d.month)
            return true;
        else if (month > d.month)
            return false;
        else if (day < d.day)
            return true;
        else
            return false;
        return false;
    }
    ~Date()
    {
        //destructor 
    }
};

class Person

{

private:
    static int counter;
    string username;
    int ID;
    Date d1;

public:
    Person(string user_ = "", int ID_ = 0)
    {
        username = user_;
        ID = ID_;
        counter++;
    }
    bool datecompare(Person p)
    {
        bool check = d1 < p.d1;
        if (check)
            return true;
        else
            return false;
    }
    void counterprint()
    {
        cout << counter;
    }
    void dateinput()
    {
        bool check;
        cin >> d1;
        check=d1.validDate();
        while(check==false)
        {
            cout<<"Invalid date Entered\n\n Please enter Again: (YYYY MM DD) ";
            cin>>d1;
            check=d1.validDate();
        }
    }

    friend istream &operator>>(istream &input, Person &a)
    {
        input >> a.username;
        input >> a.ID;
        return input;
    }

    void output(Person &p2, bool checker)
    {
        if (checker)
        {
            cout << username << " is senior to " << p2.username << " because ";
            cout<<d1;
            cout << " is earlier than ";
            p2.d1.dateoutput();
        }
        else
        {
            cout << p2.username << " is senior to " << username << " because ";
            p2.d1.dateoutput();
            cout << " is earlier than ";
            cout << d1;
        }
    }

    ~Person()
    {
        // destructor called
    }
};

int Person::counter = 0;

void setInfo(Person &a1)
{
    cout << "Enter Person No. ";
    a1.counterprint();
    cout << " Data\n";

    cout << "Enter Name and ID: ";
    cin >> a1;

    cout << "Enter joining date(yyyy mm dd): ";
    a1.dateinput();
}
int main()
{
    Person a1;
    setInfo(a1);
    Person a2;
    setInfo(a2);
    bool check = a1.datecompare(a2);
    a1.output(a2, check);
}