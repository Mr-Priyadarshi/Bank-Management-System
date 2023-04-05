#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "txnidgenerate_user.h"

void addtxn_user(string accountidsrc,string accountiddst,int option,double amount)
{
    string type;
    if(option==1)
    {
        type = "Credit";
    }
    else
    {
        type = "Debit";
    }
    fstream fout;
    fout.open("txn.csv", ios::out | ios::app);
    string txniid = txnno2();
    int txnid = stoi(txniid);
    ++txnid;
    for (int i = 0; i < 1; i++)
        {
        cout<<"\nThe Transaction ID is :- "<<txnid<<endl;
        // Insert the informations to file customer data
        fout << txnid << ","<< type << ","<< accountidsrc << ","<< accountiddst << ","<< amount<< "\n";
        }        
}