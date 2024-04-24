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
        CateringCharge = 68;
        GST = 5;
    }
    int GetTrain();
    void setTrainInfo(float, float, const char*, int, int);
    float CalcPrice();
    int PrintBill() {
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
    Route = DepartingLocation.Name + " - " + Destination.Name;
    Duration.set((int)ti, round((ti-(int)ti)*60));
    cout << Route << endl << Duration << endl << info << endl << "AC: " << AC << " SL: " << SL << endl; 
}

int Train::GetTrain() {
    int AC = 441, SL = 225;
    static int Booked = 0;
    cout << "\nWe found these routes for you!\n\n";

    // 1: Shimla, 2:Goa, 3:Manali
    setTrainInfo(DistanceFinder(DepartingLocation, Destination)/380, DistanceFinder(DepartingLocation, Destination),"Runs on MTWTFSS",AC, SL);

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