#include <iostream>
#include <math.h>
using namespace std;
class caculation
{
private:
    float Real, Imag, sum;

public:
    void getdata()
    {
        cout << "Enter The Real Part: ";
        cin >> Real;

        cout << "Enter The Imaginary Part: ";
        cin >> Imag;

    }
    void putdata()

    {

        if (Imag > 0)
        {
            cout << Real << "+" << Imag << "i" << endl;
        }
        else
        {
            cout<< Real<<Imag<<"i"<<endl;
        }

    }

    caculation operator+(caculation &x)
    {
        caculation temp;
        temp.Real = Real + x.Real;
        temp.Imag = Imag + x.Imag;
        return temp;
    }
    caculation operator-(caculation &x)
    {
        caculation temp;
        temp.Real = Real - x.Real;
        temp.Imag = Imag - x.Imag;
        return temp;
    }
    caculation operator*(caculation &x)
    {

        caculation temp;
        temp.Real = (Real * x.Real) - (Imag * x.Imag);
        temp.Imag = (Real * x.Imag) + (x.Imag + Imag);
        return temp;
        
    }
    caculation operator/(caculation &x)
    {

        caculation temp;
        temp.Real = ((Real * x.Real) + (Imag * x.Imag)) / (Real * Real) + (Imag * Imag);
        temp.Imag = ((x.Imag + Imag) - (Real * x.Imag)) / (Real * Real) + (Imag * Imag);
        return temp;

    }
    caculation operator!()
    {
        caculation temp;
        temp.Real = -Real;
        temp.Imag = -Imag;
        return temp;
    }
};
int main()
{
    class caculation a, b, c;
    char choice;
    a.getdata();
    b.getdata();
    cout << "Choice operator";
    cout << "(+) addition \n (-)subtraction \n (*) multipliction \n (/) subtraction (!) negation\n";
    cout << "Eneter Your Choice :";
    cin >> choice;
    switch (choice)
    {
    case '+':
        c = a + b;
        c.putdata();
        break;
    case '-':
        c = a - b;
        c.putdata();
        break;
    case '*':
        c = a * b;
        c.putdata();
        break;
    case '/':
        c = a / b;
        c.putdata();
        break;
    case '!':
        c = !a;
        c.putdata();
        c = !b;
        c.putdata();
    }

    return 0;
}