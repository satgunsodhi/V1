#include <iostream>
#include "master.cpp"
using namespace std;

class Train:private master {
    protected:
    Time Duration;
    int TrainClass;
    int berth_no;
    Time DepartureTime;
    public:
    void PrintTrain();
};

void Train::PrintTrain() {
    cout << "Under Progress!\n Until Then check out the individual files\n";
}