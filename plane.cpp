#include <iostream>
#include <cstring>
#include <string>
#include "master.cpp"
using namespace std;

string airlines[3] = {"IndiGo","Vistara","AirIndia"};
string seatTypes[3] = {"FirstClass" , "BuisnessClass" , "Economy"};
float costs[3][3] = {
    {9.5, 7, 4},
    {11.5, 9, 5.5},
    {10.5, 8, 4.5}
};

float GST = 0.18;
float AviationTax = 0.20;

class Plane: public master {
    int airline;
    int seatType;
    
    void ShowAvailableFlights();
    int ChooseAirlines();
    int ChooseSeatType();
    float CalcPrice();
    void PrintBill();
    void getLoc();

    public:
    Plane(master& m1) : master("ignore")

    {
        ShowAvailableFlights();
        this -> airline = ChooseAirlines() -1;
        this -> seatType = ChooseSeatType() -1;
        this -> NoofPassengers = m1.NoofPassengers;
        this -> DepartingLocation = m1.DepartingLocation;
        this -> Destination = m1.Destination;
        this -> BaseCost = FindBaseCost(costs[this -> airline][this -> seatType],DepartingLocation,Destination);
        this -> ServiceFees = this -> BaseCost*AviationTax;
        this -> GST = BaseCost*GST;
        cout << "You have chosen " << airlines[this -> airline] << " airlines for your journey from " << this -> getLoc(DepartingLocation.LocationId) << "to " << this -> getLoc(Destination.LocationId) << endl;
        cout << "Number of Passengers: " << this -> NoofPassengers << endl;
        cout << "Your Seat Type is " << seatTypes[this -> seatType] << endl;
        cout << "Your ticket price is Rs." << CalcPrice() << endl; 

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
        // Time FlightDuration((int)time_of_flight, (int)(time_of_flight*100)%100,0);
        // cout << "Arrival:" << t1 + FlightDuration << endl;
        cout << "Duration: " << time_of_flight << endl;

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
    return NoofPassengers*(BaseCost + GST + ServiceFees);
}
void Plane::PrintBill()
{
    cout << this ->airline << "Airlines" << endl ;
    cout << "your flight from " << this -> DepartingLocation.Name << "to " << this -> Destination.Name << "has been confirmed!" << endl << endl;
    cout << "Tax Invoice: ";
    cout << "Name  of Head Passenger: " << this -> NameOfPassenger;
    cout << "Number of Passengers: " << this -> NoofPassengers;
    cout << "Seat type" << this -> seatType;
    cout << "Base Cost: " << this -> BaseCost;
    cout << "Aviation Tax: " << this -> ServiceFees;
    cout << "GST: " << this -> GST;
    cout << "Grand Total: " << CalcPrice() << endl;
    cout << "Thank you Flying with us!";

}
string Plane:: getLoc(int location)
{
    if(location == 1)
    {
        return "Shimla";
    }
    else if(location == 2)
    {
        return "Goa";
    }
    else if(location == 3)
    {
        return "Manali";
    }
}
