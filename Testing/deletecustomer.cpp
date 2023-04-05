#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<cstdio>

using namespace std;

class deletecustomer
{
	private:
		fstream fin , fout;
		int count , i;
		string UserId , temp , line , word , junk;
		vector<string> row;
		
	public:
	deletecustomer()
	{
		//getline(cin,junk);
		fin.open("customer_details.csv", ios::in); // Opening the Existing File
		fout.open("custdatanew.csv", ios::out);//Creating a new file to store the non-deleted information

		// Get User Id to select the informations to be deleted
		cout << "Please!! Enter the User ID to delete the Customer information :- ";
		getline(cin,UserId);
		cout<<"\n\n";

        //Please Check if this record exists then leave it and add all remaining data to the new file
		while (!fin.eof())
		{
			row.clear();
			getline(fin,line);
			stringstream s(line);
			while (getline(s, word,','))
			{
				row.push_back(word);
			}
			int row_size = row.size();
			temp = row[0];
			// Please write all the records except that record to be deleted into the new file 
			if (temp != UserId)
			{
				if (!fin.eof())
				{
					for (i = 0; i < row_size - 1; i++)
					{
						fout << row[i] << ",";
					}
					fout << row[row_size - 1] << endl;
				}
			}
			else
			{
				count = 1;
			}
			if (fin.eof())
				break;
		}
		if (count == 1)
		{
		cout<<"\n\n******************************************************************************\n\n";
        cout<<"\t\tDone!!!! Deletion part of Record!!!!!!!";    
        cout<<"\n\n******************************************************************************\n\n"; 
		}
		else
			cout << "\n\nOOPS!!!! Not Found Record\n\n";
		fin.close();
		fout.close();
		remove("customer_details.csv"); // Remove the Existing File	
		rename("custdatanew.csv", "customer_details.csv");//Renaming the new file with the existing file name
	}
};
int main()
{
    deletecustomer d1;
}