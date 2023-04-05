#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "addtxnfile_user.h"

using namespace std;
class transaction_user
{
	private:
    string junk,accountidsrc,accountiddst,amountsrc,amountdst,line,field;
	
	public:
	transaction_user()
	{
        int sub;
		//getline(cin,junk);
		// Take the user id from the user
		cout << "Please enter the type of transaction (1 or 2) \n";
		// Take the informations to be updated of a specific option
		cout << " [ 1 ] Credit\n";
		cout << " [ 2 ] Debit\n";
		cout<<"Please Select the Correct Option(1-2) :- ";
		cin >> sub;
		// Find the index of the modified field
		if(sub == 1)
        {
            reading_user(1);
        }
        else if(sub == 2)
        {
            reading_user(2);
        }
        else
        {
            cout<<"OOPS!! Please Enter Correct Option :- "<<endl;
            transaction_user();
        }
	}
void reading_user(int a)
{
    int temp = a;
    getline(cin,junk);
       
        ifstream file2("account_data.csv");  // Opening the CSV file
        cout<<"Please Enter Source Account Number :- ";
        getline(cin,accountidsrc);
        // Read and display each line of account data
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
        file2.close(); // Close the file
        // destination account
        ifstream file1("account_data.csv");  // Open the CSV file
        string line1,field1;
        cout<<"Please Enter Destination Account Number :- ";
        getline(cin,accountiddst);
        // Read and display each line of Account Data
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
        file1.close();  // Close the file
        txn_user(accountidsrc,amountsrc,accountiddst,amountdst,temp);
}

void txn_user(string accountidsrc,string amountsrc,string accountiddst,string amountdst,int option)
{
    double sumc=0,sumd=0,amount=0;
    cout<<"Please enter the amount to transfer: ";
    cin>>amount;
    amount = round_user(amount);
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
    sumc = round_user(sumc);
    sumd = round_user(sumd);
    amountsrc = to_string(sumc);
    amountdst = to_string(sumd);
    edit_user(accountidsrc,amountsrc,accountiddst,amountdst);
	addtxn_user(accountidsrc,accountiddst,option,amount);

}

void edit_user(string accountidsrc,string amountsrc,string accountiddst,string amountdst)
{
        string line, word,ui;
		int  count = 0, i;
		vector<string> row;

		// File pointer
		fstream fin,fout;

		// Open an existing record
		fin.open("account_data.csv", ios::in);

		// Create a new file to store updated data
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
				// sending a number as a stream into output string
				convert << amountsrc;
				// the str() converts number into string
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
						// writing other existing records in new file
						fout << row[i] << ",";
					}
					// the last column data ends with a '\n'
					fout << row[row_size - 1] << "\n";
				}
			}
			if (fin.eof())
				break;
		}
		if (count == 0)
			cout << "\n\nOOPS File Not Found\n\n";
		else
			cout<<"\n\nDone!!!!! Transaction Completed\n\n";
		fin.close();
		fout.close();
		// cout<<"Data modified Successfully";
		// removing the existing file
		remove("account_data.csv");
		// renaming the updated file with the existing file name
		rename("accdatanew.csv", "account_data.csv");
     
        ///////////////////////////////////////////////
        string linee, wordd,uii;
		int  countt = 0, ii=0;
		vector<string> roww;

		// File pointer
		fstream finn,foutt;

		
		finn.open("account_data.csv", ios::in); // Open an existing record
		
		foutt.open("accdatanew.csv", ios::out); // Create a new file to store updated data
		
		while (!finn.eof()) { // Traverse the file
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
				
				convertt << amountdst; // Sending a number as a stream into output string
				
				roww[4] = convertt.str(); // The str() converts number into string
				if (!finn.eof()) {
					for (ii = 0; ii < row_sizee - 1; ii++) {
						foutt << roww[ii] << ","; // write the updated data in new file
					}
					foutt << roww[row_sizee - 1] << "\n";
				}
			}
			else {
				if (!finn.eof()) {
					for (ii = 0; ii < row_sizee - 1; ii++) {
						
						foutt << roww[ii] << ","; // writing other existing records in new file
					}
					
					foutt << roww[row_sizee - 1] << "\n"; // The last column data ends with a '\n'
				}
			}
			if (finn.eof())
				break;
		}
		if (countt == 0)
			cout << "\n\nOOPS Wrong!! Not Found File \n\n";
		fin.close();
		fout.close();
		// cout<<"Successfully Data modified ";
		remove("account_data.csv"); // Removing the existing file
		rename("accdatanew.csv", "account_data.csv");//Renaming the updated file with the existing file name
}
double round_user(double var)
    {
        double value = (int)(var * 100 + .5);
        return (double)value / 100;
    }
};

int main()
{
    transaction_user t2;
}