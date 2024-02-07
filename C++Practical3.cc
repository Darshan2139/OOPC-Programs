#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
using namespace std;
class CarDetails
{
private:
    int CarNum,SeatNum;
    string ModelName,FuelType,Transmission;
    float Price,Mileage,TankCapacity;
    char Airbag;
public:
    void GetData();
    void DisplayData();
    void PutDataModel(int);  
    void PutDataFuel(int);
    void PutDataPrice(float);
};
void CarDetails :: GetData()
{
    cin.ignore();
    cout << "Enter the model name : ";
    getline(cin, ModelName);
    cout << endl;
    cout << "Enter the fuel type : ";
    getline(cin, FuelType);
    cout << endl;
    cout << "Enter the showroom price : ";
    cin >> Price;
    cout << endl;
    cout << "Enter the mileage of car : ";
    cin >> Mileage;
    cout << endl;
    cin.ignore();
    cout << "Enter the transmission the car is manual or amt : ";
    getline(cin, Transmission);
    cout << endl;
    cout << "Enter the tank capacity : ";
    cin >> TankCapacity;
    cout << endl;
    cout << "Enter the seating capacity : ";
    cin >> SeatNum;
    cout << endl;
    cout << "Enter 'y' if airbag is available else 'n' : ";
    cin >> Airbag;
    cout << endl;
}
void CarDetails :: PutDataModel(int i)
{
    cout << i + 1 << ") " << ModelName;
}
void CarDetails :: PutDataFuel(int Num)
{
    switch (Num)
    {
    case 1:
        if (FuelType == "petrol" || FuelType == "Petrol")
        {
            DisplayData();
        }
        
        break;
    case 2:
        if (FuelType == "diesel" || FuelType == "Diesel")
        {
            DisplayData();
        }
        
        break;
    case 3:
        if (FuelType == "cng" || FuelType == "CNG")
        {
            DisplayData();
        }
        
        break;
    case 4:
        if (FuelType == "electric" || FuelType == "Electric")
        {
            DisplayData();
        }
        
        break;
    
    default:
            cout << "please select give option";
        break;
    }
}
void CarDetails :: PutDataPrice(float Pr)
{
    if (Price < Pr)
    {
        DisplayData();
    }
}
void CarDetails :: DisplayData(){
    cout << left << setw(8) << "model" << left << setw(9) << "fuel" << left << setw(11) << "price" << left << setw(12) << "milage" << left << setw(15) << "transmission" << left << setw(15) << "tank capacity" << left << setw(10) << "seat" << left << setw(9) << "airbag" << endl;
    cout << endl;
    cout << left << setw(8) << ModelName << left << setw(9) << FuelType << left << setw(11) << Price << left << setw(12) << Mileage << left << setw(15) << Transmission << left << setw(15) << TankCapacity << left << setw(10) << SeatNum << left << setw(9) << Airbag << endl;
}
int main()
{
    int Number, Option, i,ModelNum,FuelNum;
    float Price;
    cout << "Enter the number of cars (max 999) : ";
    cin >> Number;
    cout << endl;
    CarDetails car[Number]; 
    for (i = 0; i < Number; i++)
    {
        cout << i + 1 << ") car details : " << endl;
        car[i].GetData();
    } 
    cout << "\nWELCOME TO TATA MOTORS "<<endl;
    cout << "\nGET THE CAR DETAILS AS PER YOUR PREFRENCE " << endl;
    cout << "\n(1) Model name (2) Fuel type (3) price " << endl;
    cout << "\nENTER YOUR OPTION : ";
    cin >> Option;
    cout << endl;
    cout << "\n--------------------------------" << endl;
    switch (Option)
    {
    case 1:
        cout << "\nLIST OF TATA CARS" << endl;
        for (i = 0; i < Number; i++)
            car[i].PutDataModel(i);
        cout << endl << "Enter your choise : ";
        cin >> ModelNum;
        car[ModelNum - 1].DisplayData();
        break;
    case 2:
        cout << "TATA MOTORS ARE AVAILABLE WITH FUEL OPTION" << endl;
        cout << endl << "(1) Petrol (2) Diesel (3) CNG (4) Electric " << endl << endl;
        cout << "ENTER YOUR FUEL PREFRENCE : ";
        cin >> FuelNum;
        for ( i = 0; i < Number; i++)
        {
            car[i].PutDataFuel(FuelNum);
        }
        
        break;
    case 3:
        cout << "ENTER YOUR MAXIMUM AFFORDABLE RANGE IN LAKHS : ";
        cin >> Price;
        for ( i = 0; i < Number; i++)
        {
            car[i].PutDataPrice(Price);
        }
        
    default:
        cout << "Sorry you don't choose the option given by us " << endl;
        break;
    }

cout<<"23CE051DARSHAN KACHHIYA";

}