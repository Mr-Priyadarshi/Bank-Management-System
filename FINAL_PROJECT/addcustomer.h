#include <iostream>
#include <string>
#include <fstream>
#include <vector> 
#include <sstream>
#include <cmath>
#include <ctime>
#include <regex>
#include <cstdlib>

using namespace std;

class addcustomer
{
    private:
        fstream fout,fout2,fout3;
        string Name,Type,Address1,Address2,Address3,City,State,Country,PinCode,PhoneNumber,Email,Pan;
        double Balance;
        string type , Status , OpeningDate , customeriid , password , utype , junk;
    public:
    addcustomer()
    {
        //Creates a new file or Opens an existing CSV file .
        fout.open("customer_details.csv", ios::out | ios::app);
        fout2.open("account_data.csv", ios::out | ios::app);
        fout3.open("login_details.csv", ios::out | ios::app);

        cout << "Please Enter the correct informations of Customers:- "<<endl;

        //Calling userid function to get current userid and typeCasting it into int then after incrementation for generate next userID
        string acc = accno(), user = userid();     
        //Converting acc info int into string data type and similar user info int into string data type
        int accountnumber = stoi(acc) , UserId = stoi(user);
        ++accountnumber;
        ++UserId;

        // Reading the Input
        for (int i = 0; i < 1; i++)
        {
            getline(cin,junk);
            cout<<"The UserID is: "<<UserId<<endl;
            cout<<"[ U ] Customer User\n";
            cout<<"[ A ] Administrator\n";
            cout<<"Please Select the User Type: \n";
            getline(cin,utype);
            utype = checkusertype(utype);
            cout<<endl;
            cout<<"Enter Customer Id (Used for Login)\n";
            getline(cin,customeriid);
            cout<<"Password :- ";
            password = gpassword();
            cout << password << endl;
            cout<<"Please Enter Correct Name :- ";
            getline(cin,Name);
            cout<<endl;
            cout<<"Please Enter Correct Type :- \n";
            cout<<"[ 1 ] Individual\t";
            cout<<"[ 2 ] Corporate\n";
            getline(cin,Type);
            Type = checktype1(Type);
            cout<<endl;
            cout<<"Please Enter Correct Address 1 :- ";
            getline(cin,Address1);
            cout<<endl;
            cout<<"Please Enter Correct Address 2 :- ";
            getline(cin,Address2);
            cout<<endl;
            cout<<"Please Enter Correct Address 3 :- ";
            getline(cin,Address3);
            cout<<endl;
            cout<<"Please Enter Correct City :- ";
            getline(cin,City);
            cout<<endl;
            cout<<"Please Enter Correct State :- ";
            getline(cin,State);
            cout<<endl;
            cout<<"Please Enter Correct Country :- ";
            getline(cin,Country);
            cout<<endl;
            cout<<"Please Enter Correct PinCode :- ";
            getline(cin,PinCode);
            PinCode = checkPincode(PinCode);
            cout<<endl;
            cout<<"Please Enter Correct Phone number :- ";
            getline(cin,PhoneNumber);
            PhoneNumber = checkPhone(PhoneNumber);
            cout<<endl;
            cout<<"Please Enter Correct  Email :- ";
            getline(cin,Email);
            Email = emailcheck(Email);
            cout<<endl;
            cout<<"Please Enter Correct  PAN(Personal Account Number) :- ";
            getline(cin,Pan);
            Pan = validpan(Pan);
            cout<<endl;

            //Different File 
            cout<<"The Account Number Generated Is :- "<<accountnumber<<endl;
            cout<<"Please Select Type of Account: \n";
            cout<<"[ 1 ] SB Account\t\t";
            cout<<"[ 2 ] Current Account\n";
            getline(cin,type);
            type = checkatype(type);
            cout<<endl; 

            cout<<"Please Select Correct Status of Account: \n";
            cout<<"[ 1 ] Enabled\t\t";
            cout<<"[ 2 ] Disabled\n";
            getline(cin,Status);
            Status = checkstatus(Status);
            cout<<endl;

            cout<<"The Date Of Opening: ";
            OpeningDate = curdate();
            cout<<OpeningDate<<endl;

            cout<<"Please Enter the Balance: ";
            cin>>Balance;
            cout<<endl;

           // Inserting informations to the file Customer Data
            fout << UserId << ","<< Name << ","<< Type << ","<< Address1 << ","<< Address2 << ","
                << Address3 << ","<< City << ","<< State <<","<< Country <<","<< PinCode <<","
                << PhoneNumber <<","<< Email <<","<< Pan<< endl;

            // Inserting informations to the file Account Data
            fout2 << accountnumber << ","<< type << ","<< Status << ","<< UserId << ","
                << Balance << ","<< OpeningDate<<endl;

            // Inserting informations to the file logindata
            fout3 << customeriid << ","<< password << ","<< utype<< endl;      
        }
        cout<<"\n\n******************************************************************************\n\n";
        cout<<"\t\tCongratulations!!!! Successfully Inserted Data.!!!!!!!";    
        cout<<"\n\n******************************************************************************\n\n";  
    }

    string userid()  //user id generation
{
    fstream myfile;
    string details,word,l;
    vector<string> row; //Intialize a vector for storing each word in CSV File
   
    myfile.open("customer_details.csv", ios::in);  //Open a CSV File
    int count=0;  //Count lines of CSV file
    while(getline(myfile,l))
    {
        count++;
    } 
    myfile.close();  //Close file
    
    myfile.open("customer_details.csv", ios::in); //Opening file again.
 
    for(int i=0; i<=count; i++) //Enter each words in vector
    {
        getline(myfile,details);
        stringstream s(details);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
    }
    int index = (count*13)-13;
    string temp = row[index];
    return temp;
}

//Checking Customer Type
string checktype1(string Type)
{
    string a = Type;
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
        cout<<"OOPS!! Please Enter Correct option(1 - 2) :- ";
        getline(cin,a);
        checktype1(a);
    }
    return temp;
}
//Checking Pin Code Validations
string checkPincode(string pincode)
{
    string result="";
    try
    {
        int temp = stoi(pincode);
        if(temp >= 1 && temp <=999999)
        {
            result = to_string(temp);
        }
        else
        {
            throw result;  
        }
    }
    catch(...)
    {
        cout<<"OOPS!! Please Enter only Integers as Pincode :- ";
        getline(cin,result);
        result=checkPincode(result);
    }
return result;
}
// Checking Contact or Phone Number Validations
string checkPhone(string phone)
{
    string result="";
    try
    {
        long int temp = stol(phone);
        if(temp >= 1 && temp <= 9999999999)
        {
            result = to_string(temp);
        }
        else
        {
            throw result;
        }
    }
    catch(...)
    {
        cout<<"OOPS!! Please Enter only integers as Phone Number :- ";
        getline(cin,result);
        result=checkPhone(result);
    }
    return result; 
}
//Checking Email Id Validations
string emailcheck(string email)
{
    string temp;
    const regex pattern("(\\w+)@(\\w+)(\\.(\\w+))+");
    int a = regex_match(email,pattern);
    if(a==1)
    {
        temp = email;
    }
    else
    {
        cout<<"OOPS!! Please Enter correct Email ID :- ";
        getline(cin,email);
        emailcheck(email);
    }
    return email;
}
//Checking PAN(Personal Account Number) Validations
string validpan(string pan)
{
    string temp;
	const regex pattern("[A-Z]{5}[0-9]{4}[A-Z]{1}"); //Applied Regex to Checking for Valid PAN
    int a = regex_match(pan, pattern);
	if (a==1)
	{
		temp = pan;
	}
	else
	{
		cout<<"OOPS!! Please Enter correct PAN(Personal Account Number) :- ";
        getline(cin,pan);
        validpan(pan);
	}
    return pan;
}
//Checking Account Number Validations 
string accno()
{
    fstream myfile;
    string details,word,l;
    vector<string> row;  //Intialize a vector for storing each word in account_data CSV File
    
    myfile.open("account_data.csv", ios::in); //Opening CSV File

    int count=0; //Counting Lines of CSV file
    while(getline(myfile,l))
    {
        count++;
    }
    myfile.close();  //Closing File
    
    myfile.open("account_data.csv", ios::in); //Opening File Again.
    for(int i=0; i<=count; i++) //Entering each words in vector
    {
        getline(myfile,details);
        stringstream s(details);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
    }
    int index = (count*6)-6;
    string temp = row[index];
    return temp;
}
//Checking Account Type Validations
string checkatype(string Type)
{
    string a=Type;
    string temp;
    if(a=="1")
    {
        temp = "SB Account";
    }
    else if(a=="2")
    {
        temp = "Current Account";
    }
    else
    {
        cout<<"OOPS!! Please Enter Correct Option :- ";
        getline(cin,a);
        checkatype(a);
    }
    return temp;
}

//Checking Status Validations
string checkstatus(string Type)
{
    string a=Type;
    string temp;
    if(a=="1")
    {
        temp = "Enabled";
    }
    else if(a=="2")
    {
        temp = "Disabled";
    }
    else
    {
        cout<<"OOPS!! Please Enter Correct Option :- ";
        getline(cin,a);
        checkstatus(a);
    }
    return temp;
}
//Current Date Validations
string curdate()
{
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    int month = (tPtr->tm_mday);
    int date = (tPtr->tm_mon)+1;
    int year = (tPtr->tm_year)+1900;
    string m = to_string(month);
    string d = to_string(date);
    string y = to_string(year);
    string temp = d + "/" + m + "/" + y;
    
    return temp;
}
//Generating Password
    string gpassword() 
    {
        string temp;
        int length = 6; 
        string password = "";
        srand(time(NULL)); // Seed the random number generator with the current time
        for (int i = 0; i < length; i++) {
            char random_char = 'a' + rand() % 26; // Generate a Random Lowercase Letter
            password += random_char;
        }
        temp = password;
        return temp;
    }
    
// Checking User Type Validations
    string checkusertype(string Type)
{
    string a=Type;
    string temp;
    if(a=="U")
    {
        temp = "U";
    }
    else if(a=="A")
    {
        temp = "A";
    }
    else
    {
        cout<<"OOPS!! Please Enter Correct Option :- ";
        getline(cin,a);
        checkusertype(a);
    }
    return temp;
}
};