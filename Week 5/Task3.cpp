#include <iostream>
#include <string>
using namespace std;

class stringType
{
private:
    string str_1;
    string str_2;

public:
    stringType()
    {
        str_1 = "";
        str_2 = "";
    }
    ~stringType()
    {
        cout<<"Destructor Called";
    }


    void setValues(string str1, string str2)
    {
        str_1 = str1;
        str_2 = str2;
        cout << "String have beeen succesfully Saved.\n\n";
    }

    void printValues()
    {
        cout << "String 1: " << str_1 << endl;
        cout << "String 2: " << str_2 << endl;
    }
    int strlen(string s1)
    {
        int len = 0;
        while (s1[len] != '\0')
        {
            len++;
        }

        return len;
    }
    int maxLength()
    {
        int i=strlen((str_1));
        // int i = 0;
        // while (str_1[i] != '\0')
        // {
        //     i++;
        // }
        int j = 0;
        while (str_2[j] != '\0')
        {
            j++;
        }

        if (i > j)
            return i;
        else if (j > i)
            return j;
        else
            return i;
    }
    int compare(string s1, string s2)
    {
        int num = 0;
        int s1_len = 0;
        while (s1[s1_len] != '\0')
        {
            s1_len++;
        }
        int s2_len = 0;
        while (s2[s2_len] != '\0')
        {
            s2_len++;
        }
        int min;
        int max;

        if(s2_len>s1_len)
        {
        min=s1_len;
        max=s2_len;
        }
        else
        {
        max=s1_len;
        min=s2_len;
        }

        for(int i=0;i<min;i++)
        {
            if(s1[i]>s2[i])
            {
                num+=s1[i]-s2[i];
            }
            if(s1[i]<s2[i])
            {
                num+=s1[i]-s2[i];
            }
        }
        return num;

    }
    string concatenate(string s1, string s2)
    {
        s1+=s2;
        return s1;
    }
    void copy(string source, string destination)
    {
        cout<<"\nBEFORE\n";
        cout<<"source: "<<source;
        cout<<"\ndestination: "<<destination;
        destination=source;
        cout<<"\nAfter\n";
        cout<<"source: "<<source;
        cout<<"\ndestination: "<<destination;
        
    }
    int searchWord(string word)
    {
        bool checker = false;
        int s1_len = 0;
        while (str_1[s1_len] != '\0')
        {
            s1_len++;
        }
        int s2_len = 0;
        while (str_2[s2_len] != '\0')
        {
            s2_len++;
        }

        for (int i = 0; i < s1_len; i++)
        {
            if (word[i] == str_1[i])
                checker = true;
        }

        if (checker)
            return 1;

        checker = false;
        for (int i = 0; i < s2_len; i++)
        {
            if (word[i] == str_2[i])
                checker = true;
        }
        if (checker)
            return 1;

        else
            return 0;
    }
    int searchChar(char ch)
    {
       bool checker = false;
        int s1_len = 0;
        while (str_1[s1_len] != '\0')
        {
            s1_len++;
        }
        int s2_len = 0;
        while (str_2[s2_len] != '\0')
        {
            s2_len++;
        }

        for (int i = 0; i < s1_len; i++)
        {
            if (ch == str_1[i])
            {
                checker = true;
                return 1;
            }
        }

        if (checker)
            return 1;

        checker = false;
        for (int i = 0; i < s2_len; i++)
        {
            if (ch == str_2[i])
            {
                checker = true;
                return 1;
            }
        }
        if (checker)
            return 1;

        else
            return 0; 
    }
};

int main()
{
    stringType a1;
    int input;
    int num;
    string s1,s2;
    while (1)
    {
        cout << "\n(1) setValues\n";
        cout << "(2) printValues\n";
        cout << "(3) maxLength\n";
        cout << "(4) compare\n";
        cout << "(5) copy\n";
        cout << "(6) concatenate\n";
        cout << "(7) searchWord\n";
        cout << "(8) searchChar\n";
        cout << "(9) Exit\n";

        cout << "\n\n ENTER THE MENU YOU WOULD LIKE TO ENTER: ";
        cin >> input;

        switch (input)
        {
        case 1:
        {
            cout<<"Enter 1st String: ";
            cin.ignore();
            getline(cin,s1);
            cout<<"Enter 2nd String: ";
            // cin.ignore();
            getline(cin,s2);
            a1.setValues(s1,s2);
            break;
        }
        case 2:
        {
            a1.printValues();
            break;
        }
        case 3:
        {
            cout<<"Max Length between both strings = "<<a1.maxLength();
            break;
        }
        case 4:
        {
            cout<<"Enter 1st String: ";
            cin.ignore();
            getline(cin,s1);
            cout<<"Enter 2nd String: ";
            // cin.ignore();
            getline(cin,s2);
            cout<<"Value = " <<a1.compare(s1,s2);
            break;
        }
        case 5:
        {
            cout<<"Enter 1st String: ";
            cin.ignore();
            getline(cin,s1);
            cout<<"Enter 2nd String: ";
            // cin.ignore();
            getline(cin,s2);
            a1.copy(s1,s2);
            break;
        }
        case 6:
        {
            cout<<"Enter 1st String: ";
            cin.ignore();
            getline(cin,s1);
            cout<<"Enter 2nd String: ";
            getline(cin,s2);
            // cin.ignore();
            cout<<"concatenated string = "<<a1.concatenate(s1,s2);
            break;
        }
        case 7:
        {
            string input;
            cout<<"Enter word you would like to search: ";
            cin>>input;
            cout<<"Value = "<<a1.searchWord(input);
            break;
        }
        case 8:
        {
            char input;
            cout<<"Enter char you would like to search: ";
            cin>>input;

            cout<<"Value = "<<a1.searchChar(input);
            break;
        }
        case 9:
        {
            cout << "Program Exiting\n\n";
            exit(1);
            break;
        }
        default:
        {
            cout << "Invalid number entered \n";
            break;
        }
        }
        cout<<endl;
    }
}