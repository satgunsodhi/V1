#include <iostream>
#include <cstring>
#include "master.cpp"
using namespace std;

string airlines[3] = {"IndiGo","Vistara","AirIndia"}; //List of Airlines 
string seatTypes[3] = {"FirstClass" , "BuisnessClass" , "Economy"};//List of SeatTypes
//Cost Array
float costs[3][3] = {
    {6, 5, 4},
    {7.5, 6, 5.5},
    {7, 5.5, 4.5}
};

//Plane Class
class Plane: public master {
    int airline;
    int seatType;
    float GST = 0.18; //Defining GST
    float AviationTax = 0.20; //Defining Aviation Tax
    
    void ShowAvailableFlights();
    int ChooseAirlines();
    int ChooseSeatType();
    float CalcPrice();

    public:
    int PrintBill();
    Plane(master& m1) : master("ignore") // Copy Constructor
    {
        this -> DepartingLocation.LocationId = m1.DepartingLocation.LocationId;
        this -> Destination.LocationId = m1.Destination.LocationId;
        ShowAvailableFlights();
        this -> airline = ChooseAirlines() -1;
        this -> seatType = ChooseSeatType() -1;
        this -> NoofPassengers = m1.NoofPassengers;
        this -> DepartingLocation.LocationId = m1.DepartingLocation.LocationId;
        this -> Destination.LocationId = m1.Destination.LocationId;
        this -> Destination.Name = m1.Destination.Name;
        this -> DepartingLocation.Name = m1.DepartingLocation.Name;
        strcpy(NameOfPassenger, m1.NameOfPassenger);
        this -> BaseCost = FindBaseCost(costs[this -> airline][this -> seatType],DepartingLocation,Destination);
        this -> ServiceFees = this -> BaseCost*AviationTax;
        this -> GST = BaseCost*GST;
    }

};


void Plane::ShowAvailableFlights() //Listing all Availalbe Flights
{
    cout << "\nExcellent! We have the following Flights available for you!\n" << endl;
    for(int i = 0; i < 3; i++)
    {
        Time t1;
        t1.randomTimeGenerator();
        srand(time(NULL));
        cout << "[" << i+1 << "]  "<< airlines[i] << endl;
        cout << "Departure:" << t1 << endl;
        float time_of_flight = DistanceFinder(DepartingLocation,Destination) / (float)900;
        cout << "Duration: " << (int)time_of_flight << "hrs " << (int)((time_of_flight-(int)time_of_flight) * 60) << "mins"<< endl;
        LineTwo();
    }
    
};

int Plane::ChooseAirlines() // Select Airlines
{
    int Airline;
    cout << "\nLet us know your preffered brand for Aviation: " << endl;
    for(int i = 0; i < 3; i++)
    {
        
        cout << "[" << i+1 << "]  "<< airlines[i] << endl;
    }
    cout << endl << "Please Enter Choice: ";
    while (true) // Boundary Condition
    {
        SetConsoleTextAttribute(hc, 0x0A);
        cin >> Airline;
        SetConsoleTextAttribute(hc, 0x07);
        if( Airline >= 4 || Airline < 1)
        {
            cout << endl << "Please Select from the given options." << endl;
        }
        else
        {
            break;
        }
    }
    
    return Airline;
    LineTwo();
}
int Plane::ChooseSeatType() // Select SeatType
{
    int seatType;
    cout << "\nHow comfortable do you wish to be? " << endl;
    for(int i = 0; i < 3 ; i++)
    {
        cout << "[" << i+1 << "]  "<< seatTypes[i] << endl;
    }
    cout << endl << "Enter choice as indicated: ";
    while (true) //Boundary Condition
    {
        SetConsoleTextAttribute(hc, 0x0A);
        cin >> seatType;
        SetConsoleTextAttribute(hc, 0x07);
        if( seatType >= 4 || seatType < 1)
        {
            cout << endl << "Please Select from the given options." << endl;
        }
        else
        {
            break;
        }
    }
    return seatType;
    LineTwo();
}
float Plane:: CalcPrice() //Function to Claculate Price
{
    return NoofPassengers*(BaseCost + GST + ServiceFees);
}

//Function to Print Bill
int Plane::PrintBill() {
    LineTwo();
    cout << "|  " << airlines[this ->airline] << " Airlines" << endl;
    cout << "|  " << "your flight from " << this -> DepartingLocation.Name << " to " << this -> Destination.Name << " has been confirmed!" << endl << endl;
    cout << "|  " << "Tax Invoice: " << endl << endl;
    cout << "|  " << "Name of Head Passenger: " << this -> NameOfPassenger << endl;
    cout << "|  " << "Number of Passengers: " << this -> NoofPassengers << endl;
    cout << "|  " << "Seat type: " << this -> seatType + 1<< endl;
    cout << "|  " << "Base Cost: " << this -> BaseCost << endl;
    cout << "|  " << "Aviation Tax: " << this -> ServiceFees << endl;
    cout << "|  " << "GST: " << GST << endl;
    cout << "|  " << "Grand Total: " << CalcPrice() << endl;
    cout << "|  " << "Thank you Flying with us!" << endl;
    LineTwo();
    return CalcPrice();
}
