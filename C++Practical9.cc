#include <iostream>
#include <iomanip>
using namespace std;
class Milemeter;
class Centimeter
{
private:
    float cm;
public:
    Centimeter()
    {
        cm = 0;
    }
    void getdatacm()
    {
        cout << "Enter the distance in cm:";
        cin >> cm;
    }
    float getcm()
    {
        return cm;
    }
    Centimeter(Milemeter &n);

    void putdatacm()
    {
        cout << "Measurement in cm:" << cm;
    }
};
class Milemeter
{
private:
    float mm;

public:
    Milemeter()
    {
        mm = 0;
    }
    void getdatamm()
    {
        cout << "Enter the distance in mm:";
        cin >> mm;
    }
    float getmm()
    {
        return mm;
    }
    Milemeter(Centimeter &n);

    void putdatamm()
    {
        cout << "Measurement in mm:" << mm;
    }
};
Milemeter::Milemeter(Centimeter &n)
{
    mm = ((n.getcm()) * 10);
}
Centimeter::Centimeter(Milemeter &n)
{
    cm = ((n.getmm()) / 10);
}

int main()
{
    int choice;
    cout << "Enter 1:mm to cm converter." << endl;
    cout << "Enter 2:cm to mm converter." << endl;
    cin >> choice;
    Centimeter a;
    Milemeter b;
    switch (choice)
    {
    case 1:
        b.getdatamm();
        a = b;
        a.putdatacm();
        break;
    case 2:
        a.getdatacm();
        b = a;
        b.putdatamm();
        break;
    default:
        cout << "Invalid";
    }
}