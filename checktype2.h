#include<iostream>
#include<string>
using namespace std;

string checktype2(string Type)
{
    string a=Type;
    string temp;
    if(a=="1")
    {
        temp = "individaul";
    }
    else if(a=="2")
    {
        temp = "corporate";
    }
    else
    {
        cout<<"Enter Correct option: ";
        getline(cin,a);
        checktype2(a);
    }
    return temp;
}
