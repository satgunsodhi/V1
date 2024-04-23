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
    char Route[255];
    
    public:
    Train(master& m):master("Ignore") {
        
        NoofPassengers = m.NoofPassengers;
        DepartingLocation.LocationId = m.DepartingLocation.LocationId;
        Destination.LocationId =  m.Destination.LocationId;
        GetTrain();

        ServiceFees = 40; //Reservation Fees
        float CateringCharge = 68;
        GST = 5;
    }
    int GetTrain();
    void PrintTrain();
    void setTrainInfo(const char *, const char *, int, int, const char*, int, int);
    float CalcPrice();
    int PrintBill() {
        cout << "hello!";
        return 0;
    }
};

void Train::PrintTrain() {
        cout << "The Selected Train Booking is as follows:\n";
        cout << DepartingLocation.LocationPin << "To" << Destination.LocationPin << endl;
        cout << "Total Duration:" << 1;
        cout << Duration;
}

void Train::setTrainInfo(const char * Station1, const char * Station2, int hour, int minute,const char * info, int AC, int SL) {
    strcpy(DepartingLocation.LocationPin, Station1);
    strcpy(Destination.LocationPin, Station2);
    strcpy(Route,strcat(strcat(DepartingLocation.LocationPin," - "), Destination.LocationPin));
    Duration.set(hour, minute);
    cout << Route << endl << Duration << endl << info << endl << "AC: " << AC << " SL: " << SL << endl; 
}

int Train::GetTrain() {
    int AC, SL;
    static int Booked = 0;
    cout << "Routes Available:\n";

    // 1: Shimla, 2:Goa, 3:Manali
    if((DepartingLocation.LocationId == 1 && Destination.LocationId == 2) || (Destination.LocationId == 1 && DepartingLocation.LocationId == 2) || TrainNumber == 1)  {
        setTrainInfo("GOHAD ROAD" , "KALKAVIA VIA ETAWAH JN", 16, 57, "Runs On: MTWTFSS", 441, 125);
    }
    
    else if((DepartingLocation.LocationId == 1 && Destination.LocationId == 3) || (Destination.LocationId == 1 && DepartingLocation.LocationId == 3)) {
        setTrainInfo("KALKA", "AMBALA CANT JN", 1, 18, "Runs On: MTWTFSS", 490, 820);
    }

    else if((DepartingLocation.LocationId == 2 && Destination.LocationId == 3) || (Destination.LocationId == 2 && DepartingLocation.LocationId == 3)) {
        setTrainInfo("GOHAD ROAD", "AMBALA CANT JN VIA GWALIOR", 12, 56, "Runs On:MTWTFSS", 441, 225);
    }

    if(!Booked) {
        cout << "Do you wish to confirm Booking? (0: No, 1:Yes): ";
        int n;
        cin >> n;
        if (n != 1) {
            return -1;
        }
        cout << "Choose Your SeatType: (1: AC, 2:SL): ";
        cin >> TrainClass;
        if(TrainClass == 1) {
            BaseCost = AC;
        }
        else if(TrainClass == 2) {
            BaseCost = SL;
        }
        Booked = 1;
        cout << "Your Choices have been booked!" << endl;
    }
    return 0;
}

float Train::CalcPrice() {
    return BaseCost*(1+GST) + ServiceFees + CateringCharge;
}