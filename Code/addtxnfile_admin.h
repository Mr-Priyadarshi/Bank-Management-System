#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "txnidgenerate_admin.h"

void addtxn_admin(string accountidsrc,string accountiddst,int option,double amount)
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
    string txniid = txnno1();
    int txnid = stoi(txniid);
    ++txnid;
    for (int i = 0; i < 1; i++)
        {
        cout<<"\nThe Transaction ID is: "<<txnid<<endl;
        // Inserting the information to file Customer Data
        fout<<txnid<< ","<<type<< "," << accountidsrc << "," << accountiddst << "," << amount<< "\n";
        }        
}