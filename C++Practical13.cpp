#include <iostream>
#include <iomanip>
using namespace std;
class Employee
{
private:
    int EmployeeId;
    string EmployeeName;
    string Qualification;
    float Experience;
    long double ContactNumber;
    static float AverageExp;

protected:
    void getdata()
    {
        cout << "Enter the employee id(positive integer):";
        cin >> EmployeeId;
        cout << "Enter the employee name:";
        fflush(stdin);
        getline(cin, EmployeeName);
        cout << "Enter the qualification:";
        cin >> Qualification;
        cout << "Enter the experience of employee(in years):";
        cin >> Experience;
        cout << "Enter the contact number of employee:";
        cin >> ContactNumber;
        AverageExp += Experience;
    }
    void putdata()
    {
        cout << "Employee Name" << setw(5) << ":" << EmployeeName << endl;
        cout << "Qualification" << setw(5) << ":" << Qualification << endl;
        cout << "Experience" << setw(8) << ":" << Experience << "years" << endl;
        cout << "Contact Number" << setw(4) << ":" << ContactNumber << endl;
    }
    int search(int &Eid)
    {
        if (EmployeeId == Eid)
        {
            putdata();
            return 1;
        }
        else
        {
            return 0;
        }
    }

public:
    static void AverageExperience(int &x, int &y)
    {

        AverageExp = AverageExp / (y + x);
        cout << "The average experience of the employee:" << fixed << setprecision(2) << AverageExp << endl;
    }
};
class TeachingEmployee : public Employee
{
private:
    string Designation, Specialisation, PayScale;

public:
    void getdata()
    {
        Employee::getdata();
        cout << "Enter the Designation:";
        cin >> Designation;
        cout << "Enter the Specialisation:";
        cin >> Specialisation;
        cout << "Enter the pay scale:";
        cin >> PayScale;
    }
    void putdata()
    {
        cout << "Designation" << setw(9) << ":" << Designation << endl;
        cout << "Specialisation" << setw(13) << ":" << Specialisation << endl;
        cout << "Pay Scale" << setw(9) << ":" << PayScale << endl;
    }
    int search(int &Eid)
    {
        if (Employee::search(Eid) == 1)
        {
            putdata();
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
class NonTeachingEmployee : public Employee
{
private:
    unsigned int Salary;

public:
    void getdata()
    {
        Employee::getdata();
        cout << "Enter the Salary:";
        cin >> Salary;
    }
    void putdata()
    {
        cout << "Salary" << setw(9) << ":" << Salary << endl;
    }
    int search(int &Eid)
    {
        if (Employee::search(Eid) == 1)
        {
            putdata();
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
float Employee::AverageExp = 0;
int main()
{
    int t, nt, Eid, i, b;
    char a;
    cout << "Enter the number of teaching  employee:";
    cin >> t;
    cout << "Enter the number of non-teaching employee:";
    cin >> nt;
    class TeachingEmployee *T;
    class NonTeachingEmployee *NT;
    T = new TeachingEmployee[t];
    NT = new NonTeachingEmployee[t];
    cout << "------Teaching Employee Details------" << endl;
    for (int i = 0; i < t; i++)
    {
        T[i].getdata();
    }
    cout << "------Non-Teaching Employee Details------" << endl;
    for (int i = 0; i < nt; i++)
    {
        NT[i].getdata();
    }

    do
    {
        cout << "1. To Display the employee details." << endl;
        cout << "2. To know the average experience" << endl;
        cout << "3.To exit the program." << endl;
        cin >> b;
        switch (b)
        {

        case 1:
            do
            {

                cout << "Enter the employee id:";
                cin >> Eid;
                for (i = 0; i < t + nt; i++)
                {
                    if (T[i].search(Eid) == 1 || NT[i].search(Eid)==1)
                    {
                        break;
                    }
                }
                if (i == t)
                    cout << "Error the entered employee id not found.";
                cout << "Enter 'Y' to continue or 'N' to exit";
                cin >> a;
            } while (a != 'N');
            break;
        case 2:
            Employee::AverageExperience(t, nt);
            break;
        case 3:
            cout << "You have successfully exited the program." << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
        }
    } while (b != 3);
}