#include <iostream>
#include <cstring>
#include <string>
#include "master.cpp"
using namespace std;

string airlines[3] = {"IndiGo","Vistara","AirIndia"};
string seatTypes[3] = {"FirstClass" , "BuisnessClass" , "Economy"};
float costs[3][3] = {
    {6, 5, 4},
    {7.5, 6, 5.5},
    {7, 5.5, 4.5}
};


class Plane: public master {
    int airline;
    int seatType;
    float GST = 0.18;
    float AviationTax = 0.20;
    
    void ShowAvailableFlights();
    int ChooseAirlines();
    int ChooseSeatType();
    float CalcPrice();
    int PrintBill() {
    cout << this ->airline << "Airlines" << endl;
    cout << "your flight from " << this -> DepartingLocation.Name << "to " << this -> Destination.Name << " has been confirmed!" << endl << endl;
    cout << "Tax Invoice: " << endl;
    cout << "Name of Head Passenger: " << this -> NameOfPassenger << endl;
    cout << "Number of Passengers: " << this -> NoofPassengers << endl;
    cout << "Seat type: " << this -> seatType + 1<< endl;
    cout << "Base Cost: " << this -> BaseCost << endl;
    cout << "Aviation Tax: " << this -> ServiceFees << endl;
    cout << "GST: " << GST << endl;
    cout << "Grand Total: " << CalcPrice() << endl;
    cout << "Thank you Flying with us!" << endl;
    return 1;
    }

    public:
    Plane(master& m1) : master("ignore")

    {
        this -> DepartingLocation.LocationId = m1.DepartingLocation.LocationId;
        this -> Destination.LocationId = m1.Destination.LocationId;
        ShowAvailableFlights();
        this -> airline = ChooseAirlines() -1;
        this -> seatType = ChooseSeatType() -1;
        this -> NoofPassengers = m1.NoofPassengers;
        this -> DepartingLocation.LocationId = m1.DepartingLocation.LocationId;
        this -> Destination.LocationId = m1.Destination.LocationId;
        strcpy(NameOfPassenger, m1.NameOfPassenger);
        this -> BaseCost = FindBaseCost(costs[this -> airline][this -> seatType],DepartingLocation,Destination);
        this -> ServiceFees = this -> BaseCost*AviationTax;
        this -> GST = BaseCost*GST;
        cout << "You have chosen " << airlines[this -> airline] << " airlines for your journey from " << this -> getLoc(DepartingLocation.LocationId) << " to " << this -> getLoc(Destination.LocationId) << endl;
        cout << "Number of Passengers: " << this -> NoofPassengers << endl;
        cout << "Your Seat Type is " << seatTypes[this -> seatType] << endl;
        cout << "Your ticket price is Rs." << CalcPrice() << endl; 
    }

};


void Plane::ShowAvailableFlights()
{
    cout << "\nExcellent! We have the following Flights available for you!" << endl;
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
        cout << "Duration: " << (int)time_of_flight << "hrs " << (int)((time_of_flight-(int)time_of_flight) * 60) << "mins"<< endl;
    }
    
};

int Plane::ChooseAirlines()
{
    int Airline;
    cout << "\n Let us know your preffered brand for Aviation: " << endl;
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
    cout << "\nHow comfortable do you wish to be? " << endl;
    for(int i = 0; i < 3 ; i++)
    {
        cout << "[" << i+1 << "]  "<< seatTypes[i] << endl;
    }
    cout << endl << "Enter choice as indicated: ";
    cin >> seatType;
    return seatType;

}
float Plane:: CalcPrice()
{
    cout << "hello";
    return NoofPassengers*(BaseCost + GST + ServiceFees);
}

