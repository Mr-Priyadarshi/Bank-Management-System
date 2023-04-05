
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<cstdio>
#include"checktype2.h"


using namespace std;

class modifycustomer
{
	private:
		string UserId,new_value,junk;
		int index,sub;

	public:
	modifycustomer()
	{
		getline(cin,junk);
		// entering the user id from the user to update their details
		cout<<"\n\n";
		cout << "Enter the UserId to Modify the details: ";
		cin >> UserId;
		cout<<"\n\n";

		// entering the data to be updated for a particular details
		cout << " 1.) Name\n";
		cout << " 2.) Type\n";
		cout << " 3.) Address_1\n";
		cout << " 4.) Address_2\n";
		cout << " 5.) Address_3\n";
		cout << " 6.) City\n";
		cout << " 7.) State\n";
		cout << " 8.) Country\n";
		cout << " 9.) Pin Code\n";
		cout << " 10.) Mobile No\n";
		cout << " 11.) Email id\n";
		cout << " 12.) PAN Card Details\n";
		cout<<"\n\n";
		cout<<"Select the option for modifying the details: ";
		cin >> sub;
		cout<<"\n\n";

		//Determining the index of the field which have to be modified

		switch(sub)
		{
			case 1:
				index = 1;
				cout << "Enter the new Name: ";
				cin >> new_value;
				break;
			case 2:
				index = 2;
				cout << "Enter new Type: ";
				cout<<"1.) Individual\t";
				cout<<"2.) Corporate\n";
				getline(cin,new_value);
				new_value = checktype2(new_value);
				break;
			case 3:
				index = 3;
				cout << "Enter new Address_1: ";
				cin >> new_value;
				break;
			case 4:
				index = 4;
				cout << "Enter new Address_2: ";
				cin >> new_value;
				break;
			case 5:
				index = 5;
				cout << "Enter new Address_3: ";
				cin >> new_value;
				break;
			case 6:
				index = 6;
				cout << "Enter new City: ";
				cin >> new_value;
				break;
			case 7:
				index = 7;
				cout << "Enter new State: ";
				cin >> new_value;
				break;
			case 8:
				index = 8;
				cout << "Enter new Country: ";
				cin >> new_value;
				break;
			case 9:
				index = 9;
				cout << "Enter new Pin_code: ";
				cin >> new_value;
				break;
			case 10:
				index = 10;
				cout << "Enter new Mobile_Number: ";
				cin >> new_value;
				break;
			case 11:
				index = 11;
				cout << "Enter new Email_ID: ";
				cin >> new_value;
				break;
			case 12:
				index = 12;
				cout << "Enter new Pan_Card_Details: ";
				cin >> new_value;
				break;
			default:
			    cout<<"\n\n";
				cout << "***Please Select the correct option to Modify***\n";
				cout<<"\n\n";
				modifycustomer();
		}	
		modify(UserId,new_value,index);
	}


	void modify(string UserId, string new_value, int index)
	{
		string line, word,ui;
		int  count = 0, i;
		vector<string> row;

		// File pointer
		fstream fin,fout;

		// Open an existing CSV file customer_data
		fin.open("customer_details.csv", ios::in);

		// Creating a new file to storeing the updated data
		fout.open("custdatanew.csv", ios::out);

		// Traversing both the file
		while (!fin.eof()) {

			row.clear();

			getline(fin, line);
			stringstream s(line);

			while (getline(s, word, ',')) {
				row.push_back(word);
			}

			ui= row[0];
			int row_size = row.size();

			if (ui == UserId) {
				count = 1;
				stringstream convert;

				// sending a number as a stream into output string
				convert << new_value;

				// the str() converts number into string using vector
				row[index] = convert.str();

				if (!fin.eof()) {
					for (i = 0; i < row_size - 1; i++) {

						// write the updated data in the new file
						fout << row[i] << ",";
					}
					fout << row[row_size - 1] << "\n";
				}
			}
			else {
				if (!fin.eof()) {
					for (i = 0; i < row_size - 1; i++) {

						// writing other existing records into the new file
						fout << row[i] << ",";
					}
					// the last column data ends with '\n' to change the line
					fout << row[row_size - 1] << "\n";
				}
			}
			if (fin.eof())
				break;
		}
		if (count == 0)
		{
			cout<<"\n\n";
			cout << "OOPS!! Not Found Record\n";
			cout<<"\n\n";
		}
			
		else
		{
			cout<<"\n\n";
		cout<<"\n\n******************************************************************************\n\n";
        cout<<"\t\tCongratulations!! Successfully Data Modified ";   
        cout<<"\n\n******************************************************************************\n\n";  
		
			cout<<"\n\n";

		}
			


		fin.close();
		fout.close();

		// removing the existing csv file
		remove("customer_details.csv");

		// renaming the updated file with the existing csv file name as customer_data
		rename("custdatanew.csv", "customer_details.csv");
	}
};

