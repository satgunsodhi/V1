#include <iostream>
#include <cstring>
#include <string>
#include "master.cpp"

using namespace std;
char places[][255] = {"Sikkim", "Goa", "Manali"};

class Car: public master{
    protected:
        int location;
        int choice2;
        int choice;
        int distance = 0;

    public:
    Car() : distance(0) {}
    Car (master &m): master("Ignore") {
        this-> Destination.LocationId = m.Destination.LocationId; // Location 1: Sikkim 2: Goa 3: Manali
        strcpy(NameOfPassenger,m.NameOfPassenger);
        this-> NoofPassengers = m.NoofPassengers;
        calculateFare();
    }
    void calculateFare() {
        string * list;
        int * dist;
        if (Destination.LocationId == 2) {
            string l1[]= {"Aguada Fort", "Dudhsagar", "Panaji", "Baga beach", "Chapora Fort"};
            int d1[] = {100, 120, 25, 140, 80};
            list = l1;
            dist = d1;
        }
        
        else if (Destination.LocationId== 3) {
            string l1[] = {"Jogini falls", "Nehru kund", "Rohtang valley", "Mall road", "Hadimba devi temple"};
            int d1[] = {110, 76, 130, 95, 150};
            list = l1;
            dist = d1;
        }

        else if (Destination.LocationId == 1) {
            string l1[]= {"Buddha Park", "Hanuman tok", "Gurudongmar lake", "Gangtok", "Khangchendzonga national park"};
            int d1[] = {98, 76, 135, 87, 133};
            list = l1;
            dist = d1;
        }

        else {
            cout << "Invalid location choice." << endl;
        }

        for (int i = 0; i < 5; i++) {
            cout << list[i] << "\nDo you want to go to " << list[i] << "? [0: No, 1:Yes]: ";
            cin >> choice2;
            fflush(stdout);
            fflush(stdin);
    if (choice2 == 1) {
                distance += dist[i];
            }
        }
        
        int carType;
        if((NoofPassengers==0)||(NoofPassengers<0)){
            cout<<"retry";
        }
        else if(NoofPassengers<6){
            BaseCost = distance * 19.5;
        }
        else if((NoofPassengers>5) &&(NoofPassengers<8)){
            BaseCost = distance * 33;
        }
        else{
            cout<<"Which seater car do you prefer[5/7]: ";
            cin>>carType;
            if(carType==5){
                int num_cars = (NoofPassengers + 4) / 5;
                BaseCost = distance * num_cars * 19.5;
            }
            else if(carType==7){
                int num_cars = (NoofPassengers + 4) / 7;
                BaseCost = distance * num_cars * 33;
            }
            else{
                cout<<"Please enter between 5 or 7";
            }
        }
        cout<<"Confirm your booking[0: No, 1: Yes]: ";
        cin>>choice;
        if(choice == 1){
            cout<<"Booking Confirmed\n";
        }
        else {
            distance=1;
            BaseCost=1;
        }
    }
    int PrintBill(){
        cout<<"--------------------------Car Booking--------------------------"<<endl;
        cout<<"|    Booking for: "<<NameOfPassenger << endl;
        cout<<"|    Location selected: "<<places[Destination.LocationId]<<endl;
        cout<<"|    Total distance: "<<distance<<endl;
        cout<<"|    HandlingFees: " << HandlingCharges << endl;
        cout<<"|    ServiceFees: " << ServiceFees << endl;
        cout<<"|    Total Fare: "<<BaseCost<<endl;
        cout<<"\nWe thank you for choosing our new service!\n";
        return CalcPrice();
    }
};
