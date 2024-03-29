#include <iostream>
#include <cstring>
#include "master.cpp"
using namespace std;

class Train:private master {
    Train(int NoofPassengers, int TrainType, char * Couch, int TrainNumber, int TrainClass, int BerthNo) {
        
        this -> NoofPassengers = NoofPassengers;
        this -> TrainType = TrainType;
        strcpy(this -> Coach, Coach);
        this -> DepartureTime = DepartureTime;
        strcpy(this -> DepartingLocation, DepartingLocation);
        strcpy(this -> Destination, Destination);
        setTrainInfo(TrainNumber);
        this -> TrainClass = TrainClass;
        this -> BerthNo = BerthNo;

        HandlingCharges = 40;
        float CateringCharge = 400;
        GST = 5;
    }

    protected:
    int NoofPassengers;
    int TrainType;
    char Coach[3];
    Time Duration;
    int TrainNumber;
    int BerthNo;
    int TrainClass;
    Time DepartureTime;
    
    public:
    void PrintTrain();
    friend void setTrainInfo(int TrainNumber);
};

void AddTrain(/* take required inputs*/) {
    int TrainType;
    char Coach[3];
    Time DepartureTime;
    int TrainClass;
    int TrainNumber;
    int BerthNo;
    ShowTrains();
    cin >> TrainType;
    cin >> Coach;
    cin >> TrainNumber;
    cin >> TrainClass;
    cin >> BerthNo;
    Train t1(NoofPassengers, TrainType, Coach, TrainNumber, TrainClass, BerthNo);
}
void Train::PrintTrain() {
        // display booked train info
}

void setTrainInfo(int TrainNumber) {
    // Set info like departure, destination and time for the current train
}

void ShowTrains() {
    // Show a list of all the available Train and its routes
}