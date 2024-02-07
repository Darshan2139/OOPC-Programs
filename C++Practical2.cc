//employee details
#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
struct Employee
{
    private:
    int ID;
    string EName,Qualification,ContactN;
    float Experience;

    public:
    void getdata()
    {
        cout<<"Enter Employee ID: ";
        cin>>ID;
        cout<<"Enter "<<ID<<" Employee Name: ";
        fflush(stdin);
        getline(cin,EName);
        cout<<"Enter "<<ID<<" Employee Qualification: ";
        getline(cin,Qualification);
        cout<<"Enter "<<ID<<" Employee Experience: ";
        cin>>Experience;
        cout<<"Enter "<<ID<<" Employee Contact Number: ";
        cin>>ContactN;
    }
    int putdata(int x)
    {
        if(ID==x)
        {
            cout<<endl<<"---------------------------------"<<endl;
            cout<<endl<<"Employee EName"<<setw(5)<<": "<<EName<<endl;
            cout<<endl<<"Qualification"<<setw(5)<<": "<<Qualification<<endl;
            cout<<endl<<"Experience"<<setw(8)<<": "<<Experience<<" Years"<<endl;
            cout<<endl<<"Contact Number"<<setw(4)<<": "<<ContactN<<endl;
            cout<<endl<<"---------------------------------"<<endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
int main()
{
    struct Employee Emp[100];
    int N,i,FoundID,C;
    char ch;
    cout<<"Enter Number Of Employees: ";
    cin>>N;
    cout<<endl;
    for(i=0;i<N;i++)
    {
        Emp[i].getdata();
    }
    system("CLS");
    fflush(stdin);
    do
    {
        cout<<"Enter an Employee ID: ";
        fflush(stdin);
        cin>>FoundID;
        for(i=0;i<N;i++)
        {
            C = Emp[i].putdata(FoundID);
            if(C==1)
            break;
        }
        if (i==N)
        {
            cout<<endl<<"*"<<endl;
            cout<<endl<<"ERROR :ENTERED EMPLOYEE ID DOES NOT EXIST"<<endl;
            cout<<endl<<"*"<<endl;
        }
        cout<<endl<<"Press Y to get another employee detail,Press N to exit: ";
        fflush(stdin);
        cin>>ch;
        cout<<endl;
    } while (ch=='y'||ch=='Y');
    return 0;
}