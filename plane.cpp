#include <iostream>
#include <cstring>
#include <string>
#include "master.cpp"
using namespace std;

string airlines[3] = {"IndiGo","Vistara","AirIndia"};
string seatTypes[3] = {"FirstClass" , "BuisnessClass" , "Economy"};
float costs[3][3] = {{{9.5},{7},{4}},{{11.5},{9},{5.5}},{{10.5},{8},{4.5}}};
int GST = 0.18;
int AviationTax = 0.20;

class Plane: public master {
    int airline;
    int seatType;
    
    void ShowAvailableFlights();
    int ChooseAirlines();
    int ChooseSeatType();
    float CalcPrice();


    public:
    Plane(master& m1)

    {
        ShowAvailableFlights();
        this -> airline = ChooseAirlines();
        this -> seatType = ChooseSeatType();
        this -> BaseCost = FindBaseCost(costs[this -> airline][this -> seatType],DepartingLocation,Destination);
        this -> ServiceFees = this -> BaseCost*AviationTax;
        cout << "You have chosen " << this -> airline << " airlines for your journey from " << this -> DepartingLocation.Name << "to " << this -> Destination.Name << endl;
        cout << "Number of Passengers: " << this -> NoofPassengers << endl;
        cout << "Your Seat Type is " << this -> seatType << endl;
        cout << "Your ticket price is rs." << CalcPrice() << endl; 

    }

};


void Plane::ShowAvailableFlights()
{
    cout << "Avaialble Flights:" << endl;
    for(int i = 0; i < 3; i++)
    {
        Time t1;
        t1.randomTimeGenerator();
        srand(time(NULL));
        cout << "[" << i+1 << "]  "<< airlines[i] << endl;
        cout << "Departure:" << t1 << endl;
        float time_of_flight = DistanceFinder(DepartingLocation,Destination) / (float)900;
        Time FlightDuration((int)time_of_flight, (int)(time_of_flight*100)%100,0);
        cout << "Arrival:" << t1 + FlightDuration << endl;
        cout << "Duration: " << FlightDuration;

    }
    cout << endl << "Please Enter Choice: ";
    
};

int Plane::ChooseAirlines()
{
    int Airline;
    cout << "Please Choose Airline: " << endl;
    for(int i = 0; i < 3; i++)
    {
        
        cout << "[" << i+1 << "]  "<< airlines[i] << endl;
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
        cout << "[" << i+1 << "]  "<< seatTypes[i] << endl;
    }
    cout << endl << "Please Enter Choice: ";
    cin >> seatType;
    return seatType;

}
float Plane:: CalcPrice()
{
    return 2*(BaseCost + BaseCost*GST + ServiceFees);
}
