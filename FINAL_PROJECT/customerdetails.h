#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class customerdetails
{
    private:
        string line,field,junk,UserID;
        string Name,Type,Address1,Address2,Address3,City,State,Country,PinCode,PhoneNumber,Email,Pan;

    public:
    customerdetails()
    {
        getline(cin,junk);
       
        ifstream file("customer_details.csv");  // Open the CSV file
        if (!file.is_open())
        {
            cout << "OOPS !! Failed to Open File" << endl;
        }
        cout<<"Please Enter UserId :- ";
        getline(cin,UserID);
       
        while (getline(file, line)) // Read and display each line of customer data
        {
            vector<string> row;
            stringstream s(line);
            
            while (getline(s, field, ','))
            {
                row.push_back(field);
            }
            int length = row.size();
            for(int i = 0;i<length;i++)
            {
                if(row[i] == UserID)
                {
                    Name = row[i+1];
                    Type = row[i+2];
                    Address1 = row[i+3];
                    Address2 = row[i+4];
                    Address3 = row[i+5];
                    City = row[i+6];
                    State =  row[i+7];
                    Country =  row[i+8];
                    PinCode = row[i+9];
                    PhoneNumber = row[i+10];
                    Email =  row[i+11];
                    Pan = row[i+12];
                    break;
                }
            }
        }
            cout << "Name :-  " << Name << endl;
            cout << "Type :- " << Type << endl;
            cout << "Address1 :-  " << Address1 << endl;
            cout << "Address2 :- " << Address2 << endl;
            cout << "Address3 :- " << Address3 << endl;
            cout << "City :- " << City << endl;
            cout << "State :- " << State << endl;
            cout << "Country :- " << Country << endl;
            cout << "PinCode :- " << PinCode << endl;
            cout << "PhoneNumber :- " << PhoneNumber << endl;
            cout << "Email :- " << Email << endl;
            cout << "Pan :- " << Pan << endl;
        file.close(); // Close the file
    }
};