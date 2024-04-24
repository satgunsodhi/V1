#include <iostream>
#include <cstring>
#include "master.cpp"
using namespace std;

//creating a derived class train from master base class
class Train:public master {
    //creating variables that were not inherited
    protected:
    int NoofPassengers;
    int TrainType;
    Time Duration;
    int TrainNumber;
    int BerthNo;
    int TrainClass;
    Time DepartureTime;
    float CateringCharge;
    string Route;
    
    public:
    Train(master& m):master("Ignore") {
        // copy constructor
        NoofPassengers = m.NoofPassengers;
        DepartingLocation = m.DepartingLocation;
        Destination =  m.Destination;
        // taking inputs
        GetTrain();

        ServiceFees = 40; //Reservation Fees
        CateringCharge = 68; // price for catering
        GST = 5;
    }
    int GetTrain(); // gets user input
    void setTrainInfo(float, float, const char*, int, int); // sets internal variables
    float CalcPrice();  // calculates final price
    int PrintBill() {
        // get a bill representation
        LineOne();
        cout << "                           Train Booking";
        cout << "|  Route Chosen: " << Route << endl;
        cout << "|  Train Fare: " << BaseCost << endl;
        cout << "|  Catering Charges: " << CateringCharge << endl;
        cout << "|  Service Fees: " << ServiceFees << endl;
        cout << "|  Total Fare: " << CalcPrice() << endl;
        return CalcPrice();
        return 0;
    }
};

void Train::setTrainInfo(float ti, float distance, const char * info, int AC, int SL) {
    Route = DepartingLocation.Name + " - " + Destination.Name; // defining route
    Duration.set((int)ti, round((ti-(int)ti)*60)); // set function for hour and minute
    cout << Route << endl << Duration << endl << info << endl << "AC: " << AC << " SL: " << SL << endl; 
}

int Train::GetTrain() {
    int AC = 441, SL = 225;
    static int Booked = 0;
    LineOne();
    cout << "\nWe found these routes for you!\n\n";

    // 1: Shimla, 2:Goa, 3:Manali
    setTrainInfo(DistanceFinder(DepartingLocation, Destination)/380, DistanceFinder(DepartingLocation, Destination),"Runs on MTWTFSS",AC, SL);

    if(!Booked) {
        // booking if not nooked
        cout << "\nHow comfortable do you wish to be? [1: AC, 2:SL]: ";
        while (true) {
            cin >> TrainClass;
            if(TrainClass == 1 || TrainClass == 2) {
                break;
            }
            cout << "Uh Oh, That class dosent exist! Enter a choice from the given options: ";
        }
        if(TrainClass == 1) {
            BaseCost = AC;
        }
        else if(TrainClass == 2) {
            BaseCost = SL;
        }
        cout << "\nDo you wish to confirm Booking? [0: No, 1:Yes]: ";
        int n;
        while (true) {
            cin >> n;
            if(n == 0 || n == 1) {
                break;
            }
            cout << "Coudn't get that, please enter your choice again: ";
        }
        if (n != 1) { // error checking
            return -1;
        }
        Booked = 1;
        cout << "Your Choices have been booked!" << endl;
    }
    return 0;
}

float Train::CalcPrice() {
    // calculate final price
    return BaseCost*(1+GST) + ServiceFees + CateringCharge;
}