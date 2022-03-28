#include <iostream>
#include <string>
using namespace std;

class Person;
class Coordinator;

// Person seperator_();

int length_compare(Person, Person);


class Person
{
    friend class Coordinator;
    friend int length_compare(Person, Person);
    // friend Person seperator_();

private:
    static int counter;
    string unicomp_name;
    string university_name;
    string competition_name;

public:
    Person()
    {
    //     unicomp_name = "";
    //     university_name="";
    //     competition_name="";
        counter++;
    }
    void setter()
    {
        cout << "Enter the competition and University name: ";
        getline(cin, unicomp_name);
    }

    void seperator_()
{

    
    static int i=0;
    for(int j=0;i<unicomp_name.length();i++,j++)
    {
        if(unicomp_name[i]!=' ')
           competition_name.push_back(unicomp_name[i]);
        else
            {
                i++;
                break;
            }
    }
    int j=0;
    while(i<unicomp_name.length())
    {
        university_name.push_back(unicomp_name[i]);
        j++;
        i++;
    }
    i=0;

   
}
   

    ~Person()
    {
        counter--;
    }
};

class Coordinator
{

private:
    Person Person1, Person2;

public:
    Coordinator()
    {
    }

     void seperator()
    {
        Person1.seperator_();
        Person2.seperator_();
    }
    void person_inp()
    {
        Person1.setter();
        Person2.setter();
        // seperator();
    }
    void Uni_check()
    {
        if (Person1.university_name.compare(Person2.university_name) == 0)
        {
            cout << "Message from the coordinator Person1 and Person2 are roommates, and the room number is ";
            cout<<length_compare(Person1,Person2);
        }
        else
        {
            cout << "Message from the coordinator Person1 and Person2 are not roommates";
        }

        cout << endl;
    }

    


    ~Coordinator()
    {
    }
};

int Person::counter = 0;

int main()
{
    Coordinator a1;

    a1.person_inp();
    a1.seperator();
    a1.Uni_check();
}





int length_compare(Person a1, Person a2)
{
    int a1_length = a1.competition_name.length();
    int a2_length = a2.competition_name.length();

    if (a1_length >= a2_length)
        return a1_length;
    else
        return a2_length;
}

// Person seperator_()
// {

    
//     static int i=0;
//     for(int j=0;i<a1.unicomp_name.length();i++,j++)
//     {
//         if(a1.unicomp_name[i]!=' ')
//             a1.competition_name[j]=a1.unicomp_name[i];
//         else
//             {
//                 i++;
//                 break;
//             }
//     }
//     int j=0;
//     while(i<a1.unicomp_name.length())
//     {
//         a1.university_name[j]=a1.unicomp_name[i];
//         j++;
//         i++;
//     }
//     i=0;

//     return a1;
// }