#include<iostream>
#include<iomanip>
using namespace std;

class Employee 
{
private:
    int year, month;
public:
    // Conversion constructor from float to Employee
    Employee(float m) {
        year = static_cast<int>(m);
        month = static_cast<int>((m - year) * 12);
    }
    void putdata() {
        cout << "Employee experience is " << year << " years and " << month << " months.";
    }
};

int main() {
    float m;
    cout << "Enter the employee experience (in years and months): ";
    cin >> m;
    Employee a(m);
     // Convert float to Employee using conversion constructor
    a.putdata();
    return 0;
}
