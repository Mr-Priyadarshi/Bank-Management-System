#include <iostream>
#include "customerdetails.h"
#include "customerquery.h"
#include "transaction_user.h"

using namespace std;

class main_user
{
    private:
        int value;
        string junk;
    public:
    main_user()
    {
        getline(cin,junk);
        up:
        cout<<" [ 1 ] View Customer Details\n";
        cout<<" [ 2 ] Transfer Money\n";
        cout<<" [ 3 ] Query/Report on customer account & transactions\n";
        cout<<" [ 4 ] Quit Application\n";
        cout<<endl;
        cout<<"Please Select Correct Option :- ";
        cin>>value;
        if(value==1)
        {
            customerdetails d;
            goto up;
        }
        else if(value==2)
        {
            transaction_user trans2; 
            goto up;
        }
        else if(value==3)
        {
            customerquery q;
            goto up;
        }
        else if(value==4)
        {
            system("exit");
        }
        else
        {
            cout<<"OOPS Wrong!! Please Enter Correct Option ";
            main_user();
        }
    }
};