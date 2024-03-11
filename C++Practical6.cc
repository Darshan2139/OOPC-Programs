//Employe Details
#include <iostream>
#include <iomanip>
using namespace std;
class Employee
{
private:

    int Empid;
    string EmpName;
    string Qualification;
    static float AverageExp;
    float Experience;
    static int count;
    long long int ContactNumber;

public:
    Employee()
    {
        count++;
    }

    void EmployeeDetails()
    {
        cout << "Enter the employee id(Positive Integer):";
        cin >> Empid;
        cout << "Enter the employee name:";
        fflush(stdin);
        getline(cin, EmpName);
        cout << "Enter the qualification:";
        cin >> Qualification;
        cout << "Enter the experience of employee(in years):";
        cin >> Experience;
        cout << "Enter the contact number of employee:";
        cin >> ContactNumber;
        AverageExp += Experience;
    }
    int DisplayEmployeeDetails(int &Eid) const
    {
        if (Eid == Empid)
        {
            cout << "Employee Name" << setw(5) << ":" << EmpName << endl;
            cout << "Qualification" << setw(5) << ":" << Qualification << endl;
            cout << "Experience" << setw(8) << ":" << Experience << "years" << endl;
            cout << "Contact Number" << setw(4) << ":" << ContactNumber << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int DeleteEmployeeDetails(int &Eid)
    {
        if (Empid == Eid)
        {
            Empid = 00;
            EmpName = "";
            Qualification = "";
            ContactNumber = 00;
            Experience = 00;
            return 1;
        }
        else
            return 0;
    }
    static void AverageExperience()
    {

        AverageExp = AverageExp / count;
        cout << "The average experience of the employee:" << fixed << setprecision(2) << AverageExp << endl;
    }
};
int Employee::count = 0;
float Employee::AverageExp = 0;

int main()
{

    int n = 0;
    cout << "Enter the number of employee details to be entered:";
    cin >> n;

    class Employee *E;
    E = new Employee[n];
    for (int i = 0; i < n; i++)
    {
        E[i].EmployeeDetails();
    }

    int Eid, a;
    do
    {

        cout << "1.To view the employee details of the employee" << endl;
        cout << "2.To view the average experience of an employee." << endl;
        cout << "3.To delete the employee details." << endl;
        cout << "4.To exit." << endl;
        cout << "Enter any one operation from the following:" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            cout << "Enter employee id:";
            cin >> Eid;
            for (int i = 0; i < n; i++)
            {
                if (E[i].DisplayEmployeeDetails(Eid) == 1)
                    break;

                else
                {
                    cout << "Entered employee id not found." << endl;
                }
            }
            break;
        case 2:
            Employee::AverageExperience();
            cout << endl;

            break;
        case 3:
                cout << "Enter employee id:";
            cin >> Eid;
            for (int i = 0; i < n; i++)
            {
                if (E[i].DeleteEmployeeDetails(Eid) == 1)
                    break;

                else
                {
                    cout << "Entered employee id not found." << endl;
                }
            }
            break;
        case 4:
            cout << "You successfully exited the program.";
            break;
        default:
            cout << "Invalid Input";
        }
    } while (a != 4);
    delete[] E;

    return 0;
}
