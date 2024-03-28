#include <iostream>
#include "master.cpp"
using namespace std;

class Train:private master {
    Train() {
        HandlingCharges = 40;
        float CateringCharge = 400;
        GST = 5;
    }
    protected:
    Time Duration;
    int TrainClass;
    int BerthNo;
    Time DepartureTime;
    public:
    void PrintTrain();
};

void Train::PrintTrain() {
    cout << "Under Progress!\n Until Then check out the individual files\n";
}