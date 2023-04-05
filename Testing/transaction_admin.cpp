#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "addtxnfile_admin.h"

using namespace std;

class transaction_admin
{
	private:
    string junk,accountidsrc,accountiddst,amountsrc,amountdst,line,field;
	
	public:
	transaction_admin()
	{
        int sub;
		//getline(cin,junk);
		// Get the User Id from the User
		cout << "Please enter the Type of transaction (1-2) \n";

		// Get the information to be updated of a specified option
		cout << " [ 1 ] Credit\n";
		cout << " [ 2 ] Debit\n";
		cout<<"Please Select Correct Option :- ";
		cin >> sub;

		// Identifying the index of the modified field
		if(sub == 1)
        {
            reading_admin(1);
        }
        else if(sub == 2)
        {
            reading_admin(2);
        }
        else
        {
            cout<<"Please Enter the Correct Option :- "<<endl;
            transaction_admin();
        }
	}

void reading_admin(int a)
{
    int temp = a;
    getline(cin,junk);
        ifstream file2("account_data.csv");  // Opening the CSV file
        cout<<"Please Enter Source Account Number :- ";
        getline(cin,accountidsrc);
        // Read and Display each line of Account_Data
        while (getline(file2, line))
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
                if(row1[i] == accountidsrc)
                {
                    amountsrc = row1[i+4];
                    break;
                }
            }
        }   
        // cout << "Amount is: " << amountsrc << endl;
        
        file2.close(); // Closing the file

        // Destination account 
        ifstream file1("account_data.csv"); // Open the CSV file
        string line1,field1;
        cout<<"Please Enter Destination Account Number :- ";
        getline(cin,accountiddst);

		// Read and Display each line of Account_Data
        while (getline(file1, line1))
        {
            vector<string> row2;
            stringstream ss(line1);
            while (getline(ss, field1, ','))
            {
                row2.push_back(field1);
            }
            int length2 = row2.size();
            for(int i = 0;i<length2;i++)
            {
                if(row2[i] == accountiddst)
                {
                    amountdst = row2[i+4];
                    break;
                }
            }
        }   
        //cout << "Amount is: " << amountdst << endl;
       
        file1.close();  // Closing the file

        txn_admin(accountidsrc,amountsrc,accountiddst,amountdst,temp);
}

void txn_admin(string accountidsrc,string amountsrc,string accountiddst,string amountdst,int option)
{
    double sumc=0,sumd=0,amount=0;
    cout<<"Please Enter the amount to transfer :- ";
    cin>>amount;
    amount = round_admin(amount);
    double amount1 = stod(amountsrc);
    double amount2 = stod(amountdst);
    if(option == 1)
    {
        sumc = amount1 + amount;
        sumd = amount2 - amount;
    }
    else if(option == 2)
    {
        sumc = amount1 - amount;
        sumd = amount2 + amount;
    }
    sumc = round_admin(sumc);
    sumd = round_admin(sumd);
    amountsrc = to_string(sumc);
    amountdst = to_string(sumd);
    edit_admin(accountidsrc,amountsrc,accountiddst,amountdst);
	addtxn_admin(accountidsrc,accountiddst,option,amount);

}

void edit_admin(string accountidsrc,string amountsrc,string accountiddst,string amountdst)
{
        string line, word,ui;
		int  count = 0, i;
		vector<string> row;	
		fstream fin,fout; // File pointer
		// Opening an existing record
		fin.open("account_data.csv", ios::in);
		// Creating a new file to store updated information
		fout.open("accdatanew.csv", ios::out);
		// Traverse the file
		while (!fin.eof()) {
			row.clear();
			getline(fin, line);
			stringstream s(line);
			while (getline(s, word, ',')) {
				row.push_back(word);
			}
			ui= row[0];
			int row_size = row.size();
			if (ui == accountidsrc) {
				count = 1;
				stringstream convert;
				// Sending a number as a stream into output string
				convert << amountsrc;
				// The str() converts number into string
				row[4] = convert.str();
				if (!fin.eof()) {
					for (i = 0; i < row_size - 1; i++) {

						// write the updated data in new file
						fout << row[i] << ",";
					}
					fout << row[row_size - 1] << "\n";
				}
			}
			else {
				if (!fin.eof()) {
					for (i = 0; i < row_size - 1; i++) {
					// Writing other existing records in new file
						fout << row[i] << ",";
					}
					// The last column data ends with a '\n'
					fout << row[row_size - 1] << "\n";
				}
			}
			if (fin.eof())
				break;
		}
		if (count == 0)
			cout << "\n\nOOPS!!! Not Found Record \n\n";
		else
			cout<<"\n\nCongratulations!!!! Successfully Transaction Done \n\n";
		fin.close();
		fout.close();
		// cout<<"Data modified Successfully";
		// Removing the existing file
		remove("account_data.csv");

		// Renaming the updated file with the existing file name
		rename("accdatanew.csv", "account_data.csv");
     
        ///////////////////////////////////////////////
        string linee, wordd,uii;
		int  countt = 0, ii=0;
		vector<string> roww;

		// File pointer
		fstream finn,foutt;

		// Opening an existing record
		finn.open("account_data.csv", ios::in);

		// Create a new file to store updated data
		foutt.open("accdatanew.csv", ios::out);

		// Traverse the file
		while (!finn.eof()) {

			roww.clear();

			getline(finn, linee);
			stringstream ss(linee);
			while (getline(ss, wordd, ',')) {
				roww.push_back(wordd);
			}
			uii= roww[0];
			int row_sizee = roww.size();
			if (uii == accountiddst) {
				countt = 1;
				stringstream convertt;
				// Sending a number as a stream into output string
				convertt << amountdst;
				// the str() converts number into string
				roww[4] = convertt.str();
				if (!finn.eof()) {
					for (ii = 0; ii < row_sizee - 1; ii++) {
						// Write the updated information in new file
						foutt << roww[ii] << ",";
					}
					foutt << roww[row_sizee - 1] << "\n";
				}
			}
			else {
				if (!finn.eof()) {
					for (ii = 0; ii < row_sizee - 1; ii++) {
					// Writing other existing records in new file
						foutt << roww[ii] << ",";
					}
					// The last column information ends with a '\n'
					foutt << roww[row_sizee - 1] << "\n";
				}
			}
			if (finn.eof())
				break;
		}
		if (countt == 0)
			cout << "\n\nOOPS!! Not Found Record \n\n";
		fin.close();
		fout.close();

		// cout<<"Data modified Successfully";
		// Remove the Existing File
		remove("account_data.csv");

		// Renaming the updated file with the existing file name
		rename("accdatanew.csv", "account_data.csv");
}
double round_admin(double var)
    {
        double value = (int)(var * 100 + .5);
        return (double)value / 100;
    }
};
int main()
{
    transaction_admin t1;
}