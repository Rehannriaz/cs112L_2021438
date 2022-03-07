#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
#include <math.h>
using namespace std;
#define read(type, var) \
    type var;           \
    cin >> var;
#define output(num1, num2, answer)               \
    {                                            \
        cout << "(" << num1 << ") + "            \
             << "(" << num2 << ") = " << answer; \
    }
#define invalidNum      cout << "Invalid number written for base \n Program Exiting!"; exit(1);\


bool BinCheck(string, int);
int toInt(string, int);
int BinAdd(int, int, int);
long HexCheck(string);
string decToHexa(int);
bool OctCheck(string);
int OctalToBinary(int);
int convertBinarytoOctal(long);
int octalToDecimal(int);
int dec_Octal(int);


int main()
{

do
{
    system("CLS");
    cout<<"Addition of different Bases\n";
    cout<<endl;

    int num1, num2;
    cout << "Enter base (2,8,10,16) system: ";
    read(int, base);

    cout << "Enter number 1 with base: ";
    read(string, n1);

    cout << "Enter number 2 with base: ";
    read(string, n2);

    switch (base)
 {
    case 2:
    {
        bool c1, c2;
        c1 = BinCheck(n1, base);
        c2 = BinCheck(n2, base);
        if (c1 == false || c2 == false)
            invalidNum;

        int t1=toInt(n1,base);
        int t2=toInt(n2,base);

        int answer = BinAdd(t1, t2, base);
        answer = stoi(bitset<8>(answer).to_string());  // to convert to binary
        output(n1, n2, answer);
        break;
    }
    case 8:
    {
        bool c1,c2;
        c1=OctCheck(n1);
        c2=OctCheck(n2);
        if(c1==false || c2==false)
        invalidNum;

        int t1 = octalToDecimal(toInt(n1, base));
        int t2 = octalToDecimal(toInt(n2, base));
        int a1=t1+t2;
        int answer=dec_Octal(a1);
        output(n1, n2, answer);

        break;
    }
    case 10:
    {
        
        int temp1 = toInt(n1, base);
        int temp2 = toInt(n2, base);
        int answer = temp1 + temp2;
        output(n1, n2, answer);
        break;
    }
    case 16:
    {
        int answer = (HexCheck(n1) + HexCheck(n2));
        if (answer < 0)
            invalidNum;
        string hexans = decToHexa(answer);
        reverse(hexans.begin(), hexans.end());
        output(n1, n2, hexans);

        break;
    }
    default:
    {
        cout << "Invalid base Entered, Program Exiting!";
        break;
    }
 }
char input;
cout<<"\nDo you want to add another number Y/N?\n";
cin>>input;
if(tolower(input)=='y')
continue;
else if(tolower(input)=='n')
break;
else
cout<<"Invalid Response! \n Program Exiting!\n";
}while(1);
cout<<"\n\nGoodBye!\n";
}
int BinAdd(int n1, int n2, int base)
{
    int carry;
    while(n2!=0)
    {
        carry=n1&n2;
        n1=n1^n2;
        n2=carry<<1;
    }
    return n1;
}
int toInt(string n, int base)
{
    int sum = 0;
    for (int i = n.length() - 1; i >= 0; i--)
        sum += (int(n[i]) - 48) * pow(base, n.length() - 1 - i);
    return sum;
}

bool BinCheck(string num, int base)
{
    int temp = stoi(num);
    while (temp > 0)
    {
        int a = temp % 10;
        temp = temp / 10;
        if (a > base)
        return false;
        
    }
    return true;
}

long HexCheck(string strnum)
{
    long answer = 0;
    for (int i = 0; i < strnum.length(); i++)
    {
        if (strnum[i] >= 48 && strnum[i] <= 57)
            answer = answer + (strnum[i] - 48) * pow(16, strnum.length() - i - 1);

        else if (strnum[i] >= 65 && strnum[i] <= 70)
            answer = answer + (strnum[i] - 55) * pow(16, strnum.length() - i - 1);

        else if (strnum[i] >= 97 && strnum[i] <= 102)
            answer = answer + (strnum[i] - 87) * pow(16, strnum.length() - i - 1);
        else
            answer = -99999;
    }
    return answer;
}
string decToHexa(int num)
{
    string hexans;
    int temp;
    char hexachar[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (num > 0)
    {
        temp = num % 16;
        hexans += hexachar[temp];
        num /= 16;
    }
    return hexans;
}

bool OctCheck(string temp)
{
    int a=stoi(temp);
    while(a>0)
    {
        int digit=a%10;

        if(digit>7 || digit<0)
        return false;
        a/=10;
    }
    return true;
}

int octalToDecimal(int octalNumber)
{
    int dec_num = 0, power = 0, digit;
    while (octalNumber != 0)
    {
        digit = octalNumber % 10;
        octalNumber /= 10;
        dec_num += digit * pow(8, power);
        power++;
    }
    return dec_num;
}

int dec_Octal(int dec_num)
{
    int remainder,temp = 1, oct_num = 0;
    while (dec_num != 0)
    {
        remainder = dec_num % 8;
        dec_num /= 8;
        oct_num += remainder * temp;
        temp *= 10;
    }
    return oct_num;
}