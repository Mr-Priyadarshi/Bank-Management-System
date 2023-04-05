#include<iostream>
#include<string>
#include<fstream>
#include<vector> 
#include<sstream>

using namespace std;

string txnno1()
{
    fstream myfile;
    string details,word,l;
    vector<string> row;   //Intializing a vector for storing each word in csv file
    myfile.open("txn.csv", ios::in); //Opening CSV File
    int count=0; //Counting lines in CSV file
    while(getline(myfile,l))
    {
        count++;
    }
    myfile.close(); //Closing file
    myfile.open("txn.csv", ios::in);  //Opening file again
    for(int i=0; i<=count; i++) //Entering each words in vector
    {
        getline(myfile,details);
        stringstream s(details);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
    }
    int index = (count*5)-5;
    string temp = row[index];
    return temp;
}