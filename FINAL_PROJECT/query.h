#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class query
{
    private:
        string line,field,junk;
    public:
    query()
    {
        getline(cin,junk);
        ifstream file("customer_details.csv"); // Opening the CSV file
        if (!file.is_open())
        {
            cout << "OOPS!! Failed to Open File" << endl;
        }
        // Reading and displaying each line of the file
        while (getline(file, line)) {
            vector<string> row;
            stringstream s(line);
            
            while (getline(s, field, ',')) {
                row.push_back(field);
            }
            for (vector<string>::const_iterator it = row.begin(); it != row.end(); ++it) {
                const string& f = *it;
                cout << f << "  ";
            }
            cout << endl;
        }
        file.close(); // Closing the file
    }
};