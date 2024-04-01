#include<iostream>
#include<iomanip>
using namespace std;
class Employee
{
    private:
    int year,month;
    public:
    getdata()
    {   
        cout<<"Enter the employee experience in years and months:"<<endl;
        cout<<"Years:";
        cin>>year;
        cout <<"Month:";
        cin>>month;
    }
    operator float()
    {

        
           return (year+(month/12.0));

    }

};
int main()
{
    float e;
    Employee a;
    a.getdata();
    e=a;
    cout<<"Employee experience is :"<<fixed<<setprecision(2)<<e;
}