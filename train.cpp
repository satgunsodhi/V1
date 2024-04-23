#include <iostream>
#include <cstring>
#include "master.cpp"
using namespace std;

class Train:public master {

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
        
        NoofPassengers = m.NoofPassengers;
        DepartingLocation = m.DepartingLocation;
        Destination =  m.Destination;
        GetTrain();

        ServiceFees = 40; //Reservation Fees
        float CateringCharge = 68;
        GST = 5;
    }
    int GetTrain();
    void setTrainInfo(float, float, const char*, int, int);
    float CalcPrice();
    int PrintBill() {
        cout << "-------------------------Train Booking-------------------------";
        cout << "Route Chosen: " << Route;
        cout << "Train Fare: " << BaseCost;
        cout << "Catering Charges: " << CateringCharge;
        cout << "Service Fees: " << ServiceFees;
        cout << "Total Fare: " << CalcPrice();
        return CalcPrice();
        return 0;
    }
};

void Train::setTrainInfo(float ti, float distance, const char * info, int AC, int SL) {
    Route = DepartingLocation.Name + " - " + Destination.Name;
    Duration.set((int)ti, round((ti-(int)ti)*60));
    cout << Route << endl << Duration << endl << info << endl << "AC: " << AC << " SL: " << SL << endl; 
}

int Train::GetTrain() {
    int AC, SL;
    static int Booked = 0;
    cout << "We found these routes for you!\n";

    // 1: Shimla, 2:Goa, 3:Manali
    setTrainInfo(DistanceFinder(DepartingLocation, Destination)/380, DistanceFinder(DepartingLocation, Destination),"Runs on MTWTFSS",441, 225);

    if(!Booked) {
        cout << "\nHow comfortable do you wish to be? [1: AC, 2:SL]: ";
        cin >> TrainClass;
        if(TrainClass == 1) {
            BaseCost = AC;
        }
        else if(TrainClass == 2) {
            BaseCost = SL;
        }
        cout << "\nDo you wish to confirm Booking? [0: No, 1:Yes]: ";
        int n;
        cin >> n;
        if (n != 1) {
            return -1;
        }
        Booked = 1;
        cout << "Your Choices have been booked!" << endl;
    }
    return 0;
}

float Train::CalcPrice() {
    return BaseCost*(1+GST) + ServiceFees + CateringCharge;
}