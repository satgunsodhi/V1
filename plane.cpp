#include <iostream>
#include <cstring>
#include <string>
#include "master.cpp"
using namespace std;

string airlines[3] = {"IndiGo","Vistara","AirIndia"};
string seatTypes[3] = {"FirstClass" , "BuisnessClass" , "Economy"};
float costs[3][3] = {{{9.5},{7},{4}},{{11.5},{9},{5.5}},{{10.5},{8},{4.5}}}
int GST = 0.18;
int Aviation Tax = 0.20;

class Plane: private master {
    int airline;
    int seatType;
    
    int ChooseAirlines();
    int ChooseSeatType();
    float CalculatePrice(int airline , int seatType , int GST , int distance);


    public:
    Plane(master& m1)

    {
        this -> airline = airlines[ChooseAirlines()];
        this -> seatType = seatTypes[ChooseSeatType()];
        this -> BaseCost = (costs[this -> airline][this -> seatType])*distance;// chk distance
        this -> ServiceFees = this -> BaseCost*AviationTax
        cout << "You have chosen " << this -> airline << " airlines for your journey from " << this -> DepartingLocation << "to " << this -> Destination << endl;
        cout << "Number of Passengers: " << this -> NoofPassengers << endl;
        cout << "Your Seat Type is " << this -> seatType << endl;
        cout << "Your ticket price is rs." << CalculatePrice(this -> airline , this -> seatType, GST , distance) << endl; // look for distance

    }

};

    int Plane::ChooseAirlines()
    {
        int Airline;
        cout << "Please Choose Airline: " << endl;
        for(int i = 0; i < 3 , i++)
        {
            cout << "[" << i+1 << "]  "<< airlines[i];
        }
        cout << endl << "Please Enter Choice: ";
        cin >> Airline;
        return Airline;

    }
    int Plane::ChooseSeatType()
    {
        int seatType;
        cout << "Please Choose your Seat Type: " << endl;
        for(int i = 0; i < 3 ; i++)
        {
            cout << "[" << i+1 << "]  "<< airlines[i];
        }
        cout << endl << "Please Enter Choice: ";
        cin >> seatType;
        return seatType;

    }
    float Plane::float CalculatePrice()
    {
        return baseCost+ BaseCost*GST + ServiceFees;
    }
