#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class customerquery
{
    private:
        string line , field , junk , UserID , type , Status , OpeningDate , amount , accno ;
    public:
    customerquery()
    {
        //getline(cin,junk);
        ifstream file2("account_data.csv"); // Opening the CSV file
        if (!file2.is_open())
        {
            cout << "OOPS!! Failed to Open File" << endl;
        }
        cout<<"Please Enter UserId :- ";
        getline(cin,UserID);
        while (getline(file2, line))// Read and display each line of accdata
        {
            vector<string> row1;
            stringstream s(line);
            while (getline(s, field, ','))
            {
                row1.push_back(field);
            }
            int length1 = row1.size();
            for(int i = 0;i<length1;i++)
            {
                if(row1[i+3] == UserID)
                {
                    accno = row1[i];
                    type = row1[i+1];
                    Status = row1[i+2];
                    amount = row1[i+4];
                    OpeningDate = row1[i+5];
                    break;
                }
            }
        }   
            cout << "Account Number :- " << accno << endl;
            cout << "Type of Account :- " << type << endl;
            cout << "Status of Account :- " << Status << endl;
            cout << "Amount :- " << amount << endl;
            cout << "Opening Date of Account :- " << OpeningDate << endl;
        file2.close();  // Close the file
    }
};
int main()
{
    customerquery q1;
}