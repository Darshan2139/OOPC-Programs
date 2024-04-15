#include <iostream>
#include <iomanip>
using namespace std;

class product 
{
protected:
    int product_id;
    string product_name;
    string product_manufacturer;
    float product_price;

public:
    product(int id, string name, string manufacturer, float price) 
    {
        product_id = id;
        product_name = name;
        product_manufacturer = manufacturer;
        product_price = price;
    }
    virtual void putdata() = 0;
};

class smartwatch : public product 
{
protected:
    float dial_size;

public:
    smartwatch(int id, string name, string manufactorer, float price, float dialsize) : product(id, name, manufactorer, price) 
    {
        dial_size = dialsize;
    }
    void putdata() 
    {
        cout << product_id << " : " << product_name << " : " << product_manufacturer << " : " << product_price << " : " << dial_size << endl;
    }
};

class bedsheet : public product 
{
protected:
    float height;
    float width;

public:
    bedsheet(int id, string name, string manufactorer, float price, float Height, float Width) : product(id, name, manufactorer, price) 
    {
        height = Height;
        width = Width;
    }
    void putdata() 
    {
        cout << endl << product_id << " : " << product_name << " : " << product_manufacturer << " : " << product_price << " : " << width << " : " << height << endl;
    }
};

int main() 
{
    int n;
    do {
        cout << "Enter 1: smart watch menu\n" << "Enter 2: bedsheet menu" << endl << "Enter your choice : ";
        cin >> n;
        if (n != 1 && n != 2) {
            cout << "Enter valid case." << endl;
        }
    } while (n != 1 && n != 2);

    int product_id;
    string product_name, product_manufacturer;
    float product_price, dial_size, width, height;
    switch (n) 
    {
    case 1:
        cout << endl << "***** ENTER SMART WATCH DATA *****" << endl << endl;
        cout << "Enter product id: ";
        cin >> product_id;
        cout << "Enter product name : ";
        cin.ignore();
        getline(cin, product_name);
        cout << "Enter product manufacturer : ";
        getline(cin, product_manufacturer);
        cout << "Enter product price : ";
        cin >> product_price;
        cout << "Enter product dial size : ";
        cin >> dial_size;
        smartwatch* p1;
        p1 = new smartwatch(product_id, product_name, product_manufacturer, product_price, dial_size);
        cout << "--------------------------------------------------------" << endl;
        p1->putdata();
        cout << "--------------------------------------------------------";

        break;
    case 2:
        cout << endl << "***** ENTER BEDSHEET DATA *****" << endl << endl;
        cout << "Enter product id : ";
        cin >> product_id;
        cout << "Enter product name : ";
        cin.ignore();
        getline(cin, product_name);
        cout << "Enter product manufacturer : ";
        getline(cin, product_manufacturer);
        cout << "Enter product price : ";
        cin >> product_price;
        cout << "Enter bedsheet width : ";
        cin >> width;
        cout << "Enter bedsheet height : ";
        cin >> height;
        bedsheet* p2;
        p2 = new bedsheet(product_id, product_name, product_manufacturer, product_price, height, width);
        cout << "--------------------------------------------------------";
        p2->putdata();
        cout << "--------------------------------------------------------";
        break;
    }
    return 0;
}