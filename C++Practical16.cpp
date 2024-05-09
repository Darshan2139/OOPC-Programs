#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include<iomanip>

using namespace std;

class TATA
{
    private:
    string Modelname,Fueltype,airbag,Transmission;
    float Price,Mileage,Tankcap;
    int seat,carchoice;
    public:
    void getcardetail(string model, string fuel, float price, float mileage, string transm, float tank,int seat, string air)
    {
        Modelname = model;
        Fueltype = fuel;
        Price = price;
        Mileage = mileage;
        Transmission = transm;
        Tankcap = tank;
        airbag = air;
    }
    void searchmodel(string Findmodel)
    {
        char MArray[10],Fmodel[15];
        strcpy(MArray,Modelname.c_str());
        strcpy(Fmodel,Findmodel.c_str());
        if(strcmp(MArray,Fmodel)==0)
        {
            cout << Modelname << setw(15) << Fueltype << setw(15) << Price << setw(15) << Mileage << setw(15) << Transmission << setw(18) ;
            cout << Tankcap << setw(20) << seat << setw(11) << airbag  << endl;
        }
    }
    void searchfuel(string fuel)
    {
        char arr[40],arr1[10];
        strcpy(arr,fuel.c_str());
        strcpy(arr1,Fueltype.c_str());
        if(strcmp(arr1,arr)==0)
        {
            cout << Modelname << setw(15) << Fueltype << setw(15) << Price << setw(15) << Mileage << setw(15) << Transmission << setw(18) ;
            cout << Tankcap << setw(20) << seat << setw(11) << airbag  << endl;
        }
    }
    void Sortbyprice(float affordprice)
    {
        if(affordprice>Price)
        {
            cout << Modelname << setw(15) << Fueltype << setw(15) << Price << setw(15) << Mileage << setw(15) << Transmission << setw(18) ;
            cout << Tankcap << setw(20) << seat << setw(11) << airbag  << endl;
        }
    }
}cars[8];

int main() {
    int l = 0; 
    ifstream car("cardata.txt");
    if (!car.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string bags, model, fuel, transm;
    float price, mileage, tank;
    int cap;
    string entry;

    while (getline(car, entry, ';')) 
    {
        stringstream ss(entry);
        string token;
        int index = 0;
        while (getline(ss, token, ',')) 
        {
            switch (index) {
                case 0: 
                    model = token;
                    break;
                case 1: 
                    fuel = token;
                    break;
                case 2: 
                    price = stof(token);
                    break;
                case 3: 
                    mileage = stof(token);
                    break;
                case 4: 
                    transm = token;
                    break;
                case 5: 
                    tank = stof(token);
                    break;
                case 6: 
                    cap = stoi(token);
                    break;
                case 7: 
                    bags = token;
                    break;
                default:
                    break;
            }
            index++;
        }
        cars[l].getcardetail(model,fuel,price,mileage,transm,tank,cap,bags);
        l++; 
    }


    int n=7,i,search,fuels,SModel,afford,re_exe;
    
    re_exe:
    cout << "Welcome to TATA Motors\n";
    cout << "Get the car details as per your preference.\n";
    cout << "1)Model name\n";
    cout << "2)Fuel type\n";
    cout << "3)Price Range\n";
    cout << "Enter your option : ";
    cin >> search;

    switch(search)
    {
        case 1:
        cout << "------------------------------------------";
        cout << "\nList of cars";
        cout << "\n(1)TIAGO\t(2)PUNCH\t(3)ALTROZ\t(4)TIGOR\t(5)NEXON\t(6)HARRIER\t(7)SAFARI";
        cout << "\nCHOOSE YOUR CAR TO GET DETAILS : ";
        cin >> SModel;
        cout << "Model" << setw(15) << "Fuel" << setw(15) << "Price" << setw(15) << "Mileage" << setw(15) << "Transmission" << setw(18) ;
        cout << "Tank Capacity" << setw(20) << "Seating capacity" << setw(11) << "Airbags\n" ;
        switch(SModel)
        {
            case 1:
            for(i=0;i<n;i++)
            {
                cars[i].searchmodel("TIAGO");
            }
            break;
            case 2:
            for(i=0;i<n;i++)
            {
                cars[i].searchmodel("PUNCH");
            }
            break;
            case 3:
            for(i=0;i<n;i++)
            {
                cars[i].searchmodel("ALTROZ");
            }
            break;
            case 4:
            for(i=0;i<n;i++)
            {
                cars[i].searchmodel("TIGER");
            }
            break;
            case 5:
            for(i=0;i<n;i++)
            {
                cars[i].searchmodel("NEXON");
            }
            break;
            case 6:
            for(i=0;i<n;i++)
            {
                cars[i].searchmodel("HARRIER");
            }
            break;
            case 7:
            for(i=0;i<n;i++)
            {
                cars[i].searchmodel("SAFARI");
            }
            break;
        }
        break;
        case 2 :
        cout << "------------------------------------------";
        cout << "TATA MOTORS ARE AVAILABLE WITH  FUEL OPTIONS.";
        cout << "\n1)PETROL \t2)DIESEL \t3)CNG ";
        cout << "\nEnter your fuel preference : "; 
        cin >> fuels;
        cout << "Model" << setw(15) << "Fuel" << setw(15) << "Price" << setw(15) << "Mileage" << setw(15) << "Transmission" << setw(18) ;
        cout << "Tank Capacity" << setw(20) << "Seating capacity" << setw(11) << "Airbags\n" ;
        switch(fuels)
        {
            case 1:
            for(i=0;i<n;i++)
            {
                cars[i].searchfuel("Petrol");
            }
            break;
            case 2:
            for(i=0;i<n;i++)
            {
                cars[i].searchfuel("Diesel");
            }
            break;
            for(i=0;i<n;i++)
            {
                cars[i].searchfuel("CNG");
            }
            break;
        }
        break;
        case 3:
        cout << "------------------------------------------";
        cout << "\nENTER THE MAXIMUM AFFORDABLE RANGE IN LAKHS : ";
        cin >> afford;
        cout << "Model" << setw(15) << "Fuel" << setw(15) << "Price" << setw(15) << "Mileage" << setw(15) << "Transmission" << setw(18) ;
        cout << "Tank Capacity" << setw(20) << "Seating capacity" << setw(11) << "Airbags\n" ;
        for(i=0;i<n;i++)
        {
            cars[i].Sortbyprice(afford);
        }
        break;
    }
    goto re_exe;
    car.close();

    return 0;
}