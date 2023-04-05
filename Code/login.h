#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "main_admin.h"
#include "main_user.h"
using namespace std;
class login
{
    private:
        string Customer_ID,password,junk;
        fstream file1;
        string details,word,l;
        vector<string> info;

    public:
    login()
    {
        // getline(cin,junk);
        //User should be able to Enter CustomerID & Password
        cout<<"Please enter Customer ID: ";  
        cin>>Customer_ID;
        cout<<"Please enter Password: ";
        system("stty -echo");
        cin>>password;
        system("stty echo");
        

        //Intialize a vector for the purpose of storing each word of csv file
        file1.open("login_details.csv", ios::in);   //Open a CSV File
        int count=0;   //Counting lines of login_details of CSV file
        while(getline(file1,l))
        {
            count++;
        }
 
        file1.close();        //Closing file
        
        file1.open("login_details.csv", ios::in); //Opening file again .
        
        for(int i=0; i<=count; i++)  //Enter each words in vector 
        {
            getline(file1,details);
            stringstream s(details);
            while (getline(s, word, ',')) 
            {
                info.push_back(word);
            }
        }

        int length = info.size() , i = 0 , flag = 0 ;      
        while(i<length)  //comparision between input entered by user and database
        {
                if(Customer_ID == info[i] && password == info[i+1] && info[i+2] == "A")
                {
                    flag=1;
                    break;
                }
                else if(Customer_ID == info[i] && password == info[i+1] && info[i+2] == "U")
                {
                    flag=2;
                    break;
                }
                i += 3;
        }
        if(flag==1)
        {
            cout<<"\n\t\t******************************************************************************\n\n";
            cout<<"\t\t\t\tCongratulations ADMIN!!!! Successfull Login "<<endl;
            cout<<"\n\t\t******************************************************************************\n\n";
            main_admin obj;
        }
        else if(flag==2)
        {
            cout<<"\n\t\t******************************************************************************\n\n";
            cout<<"\t\t\t\tCongratulations USER!!!! Successfull Login "<<endl;
            cout<<"\n\t\t******************************************************************************\n\n";
            main_user obj1;
        }
        else
        {
            cout<<"\n\t\t******************************************************************************\n";
            cout<<"\t\t\t\tOOPS!! Please Enter Correct CustomerID/Password. "<<endl;
            cout<<"\n\t\t******************************************************************************\n\n";
            login();
        }
    }
};