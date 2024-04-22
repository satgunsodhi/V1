#include <iostream>
#include <cstring>
#include "master.cpp"
using namespace std;

class Train:public master {

    protected:
    int NoofPassengers;
    int TrainType;
    char Coach[3];
    Time Duration;
    int TrainNumber;
    int BerthNo;
    int TrainClass;
    Time DepartureTime;
    float TrainSpeed;
    float Distance;
    
    public:
    Train(master& m) {
        
        NoofPassengers = m.NoofPassengers;
        DepartingLocation = m.DepartingLocation;
        Destination =  m.Destination;
        ShowTrains();
        cin >> TrainNumber;
        setTrainInfo(TrainNumber);

        ServiceFees = 15;
        float CateringCharge = 400;
        GST = 5;
    }
    void ShowTrains();
    void PrintTrain();
    void setTrainInfo(int TrainNumber);
};

void Train::PrintTrain() {
        cout << "The Selected Train Booking is as follows:\n";
        cout << DepartingLocation.Name << "To" << Destination.Name << endl;
        cout << "Total Duration:" << DistanceFinder(DepartingLocation, Destination)/TrainSpeed;
}

void Train::setTrainInfo(int TrainNumber) {
    TrainType;
    BerthNo;
    cin >> TrainClass;
    DepartureTime;
    Coach;
}

void Train::ShowTrains() {
    // Location 1: Shimla
    if (strcmp(DepartingLocation.Name, "Shimla")) {
        
    }

    else if(strcmp(DepartingLocation.Name, "Goa")) {
        cout << "2 Routes Available:\n";
        cout << "1. GOHAD ROAD - AMBALA CANT JN VIA GWALIOR";
        cout << "Total Duration: 12h56m";
        cout << "Runs on M T W T F S S";
        cout << "2. GOHAR ROAD - KALKA VIA ETAWAH JN";
        cout << "Total Duration: 16h57m";
    }

    else if(strcmp(DepartingLocation.Name, "Manali")) {

    }
}