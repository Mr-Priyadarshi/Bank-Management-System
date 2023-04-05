#include <iostream>
#include "addcustomer.h"
#include "modifycust.h"
#include "transaction_admin.h"
#include "deletecustomer.h"
#include "query.h"
using namespace std;
class main_admin
{
    private:
        int value;
        string defaultGarbage;
    public:
    main_admin()
    {
        getline(cin,defaultGarbage);
        up:
        cout<<"\n[ 1 ] Add Customer information\n";
        cout<<"[ 2 ] Delete Customer information\n";
        cout<<"[ 3 ] Modify Customer information\n";
        cout<<"[ 4 ] Credit/Debit Money from the Customer Account\n";
        cout<<"[ 5 ] Query/Report of customer account and transactions\n";
        cout<<"[ 6 ] Quit Application\n"<<endl;
        cout<<"Please Choose the Correct Option: ";
        cin>>value;
        if(value==1)
        {
            addcustomer add;
            goto up;
        }
        else if(value==2)
        {
            deletecustomer del;
            goto up;
        }
        else if(value==3)
        {
            modifycustomer modify;
            goto up;
        }
        else if(value==4)
        {
            transaction_admin trans1; 
            goto up;  
        }
        else if(value==5)
        {
            query q;
            goto up;
        }
        else if(value==6)
        {
            system("exit");
        }
        else
        {
            cout<<"OOPS Wrong Option!! Please Enter Correct Option :- ";
            main_admin();
        }
    }
};