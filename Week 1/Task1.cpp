#include <iostream>
#include <iomanip>
/*
86>A 4
82><86 A- 3.67
78 -82 B+ 3.3
74-78 B 3
70-74 B- 2.67
66-70 C+ 2.33
*/
using namespace std;

const float A = 4;
const float A_neg = 3.67;
const float B_pos = 3.33;
const float B = 3;
const float B_neg = 2.67;
const float C_pos = 2.33;
const int cr_hour = 3;

struct Student
{
    string name;
    string RegNo;
    string DegreeProgram;
    int NoOfCourses;
    int courses[10];
    float cgpa;
};
float grade(float SGPA);
int main()
{
    Student a[3];
    float SGPA = 0;
    for (int i = 0; i < 3; i++)
    {
         float total = 0;
        cout << "Enter the record of " << i + 1 << " student:\n";
        cout << "Enter the name: ";
        cin >> a[i].name;
        cout << "Enter the reg.no.:";
        cin >> a[i].RegNo;
        cout << "Enter the degree program: ";
        cin >> a[i].DegreeProgram;
        cout << "Enter the number of courses: ";
        cin >> a[i].NoOfCourses;

        for (int j = 0; j < a[i].NoOfCourses; j++)
        {
            cout << "Enter the marks of " << j + 1 << " course:";
            cin >> a[i].courses[j];
            total += (a[i].courses[j] * 3);
        }
        SGPA = total / (a[i].NoOfCourses * 3);
        a[i].cgpa= grade(SGPA);
    }
    cout<<"S.No."<<setw(20)<<"Name"<<setw(20)<<"Reg.No."<<setw(20)<<"Degree Program"<<setw(20)<<"SGPA"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<i+1<<setw(20)<<a[i].name<<setw(20)<<a[i].RegNo<<setw(20)<<a[i].DegreeProgram<<setw(20)<<a[i].cgpa<<endl;
    }
}
float grade(float SGPA)
{
    if (SGPA >= 86)

        return A;

    else if (SGPA < 86 && SGPA >= 82)

        return (A_neg);

    else if (SGPA < 82 && SGPA >= 78)

        return (B_pos);
    else if (SGPA < 78 && SGPA > 74)

        return (B);

    else if (SGPA < 74 && SGPA > 70)

        return (B_neg);

    else if (SGPA < 70 && SGPA > 66)

        return (C_pos);

    else
        return 2.0;
}
