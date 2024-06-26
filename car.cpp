#include <iostream>
#include <cstring>
#include <string>
#include "master.cpp"

using namespace std;
char places[][255] = {"Sikkim", "Goa", "Manali"};

//class to encapsulate data members and member functions needed for car
class Car: public master{
    protected:
        int location;
        int choice2;
        int choice;
        int choice3;
        int distance = 0;

    public:
    //initialzing constructor
    Car() : distance(0) {}
    //copy constructor
    Car (master &m): master("Ignore") {
        this-> Destination.LocationId = m.Destination.LocationId; // Location 1: Sikkim 2: Goa 3: Manali
        strcpy(NameOfPassenger,m.NameOfPassenger);
        this-> NoofPassengers = m.NoofPassengers;
        ServiceFees = 50;
        calculateFare();
    }
    //function to calculate the fare
    void calculateFare() {
        string * list;
        int * dist;
        
        //distance and location stored in array - goa
        if (Destination.LocationId == 2) {
            string l1[]= {"Aguada Fort", "Dudhsagar", "Panaji", "Baga beach", "Chapora Fort"};
            int d1[] = {100, 120, 25, 140, 80};
            list = l1;
            dist = d1;
        }
        
        //distance and location stored in array- Manali
        else if (Destination.LocationId== 3) {
            string l1[] = {"Jogini Falls ", "Nehru Kund", "Rohtang Valley", "Mall Road", "Hadimba Devi temple"};
            int d1[] = {110, 76, 130, 95, 150};
            list = l1;
            dist = d1;
        }
        //distance and location stored in array- Sikkim
        else if (Destination.LocationId == 1) {
            string l1[]= {"Buddha Park", "Hanuman tok", "Gurudongmar Lake", "Gangtok", "Khangchendzonga National Park"};
            int d1[] = {98, 76, 135, 87, 133};
            list = l1;
            dist = d1;
        }

        else {
            cout << "Invalid location choice." << endl;
        }
        //choosing tourist places 
        for (int i = 0; i < 5; i++) {
            cout << list[i] << "\nDo you want to go to " << list[i] << "? [0: No, 1:Yes]: ";
            SetConsoleTextAttribute(hc, 0x0A);
            while(true) {
                cin >> choice;
                if(choice == 0 || choice == 1) {
                    break;
                }
                cout << "Invalid Place, Please enter a valid choice: ";
            }
            SetConsoleTextAttribute(hc, 0x07);
            fflush(stdout);
            fflush(stdin);
            if (choice == 1) {
                distance += dist[i];
            }
        }
        
        ////choosing car type and calculating the BaseCost
        int carType;
        if((NoofPassengers==0)||(NoofPassengers<0)){
            cout<<"retry";
        }
        else if(NoofPassengers<8){
            BaseCost = distance * 19.5;
        }
        else if((NoofPassengers>5) &&(NoofPassengers<8)){
            BaseCost = distance * 33;
        }
        else{
            cout<<"Which seater car do you prefer[5/7]: ";
            SetConsoleTextAttribute(hc, 0x0A);
            while(true){
                cin>>carType;
                //cost of car for 5 seater
                if(carType==5){
                    int num_cars = (NoofPassengers + 4) / 5;
                    BaseCost = distance * num_cars * 19.5;
                    break;
                }
                else if(carType==7){
                    int num_cars = (NoofPassengers + 6) / 7;
                    BaseCost = distance * num_cars * 33;
                    break;
                }
                else{
                    cout<<"Please enter between 5 or 7: ";
                }
            }
        }
        //confirm booking
        cout<<"Confirm your booking[0: No, 1: Yes]: ";
        while(true){
            SetConsoleTextAttribute(hc, 0x0A);
            cin>>choice3;
            SetConsoleTextAttribute(hc, 0x07);
            if(choice3 == 1){
                cout<<"Booking Confirmed!\n";
                break;
            }
            else {
                distance=1;
                BaseCost=1;
                break;
            }
        }
    }
    //function to print total car bill
    int PrintBill(){
        LineOne();
        cout << "\t\t\t\t\t\t\tCar Booking\n";
        cout<<"|    Booking for: "<<NameOfPassenger << endl;
        cout<<"|    Location selected: "<<places[Destination.LocationId]<<endl;
        cout<<"|    Total distance: "<<distance<<endl;
        cout<<"|    HandlingFees: " << HandlingCharges << endl;
        cout<<"|    ServiceFees: " << ServiceFees << endl;
        cout<<"|    Total Fare: Rs."<<CalcPrice()<<endl;
        cout<<"\nWe thank you for choosing our new service!\n";
        //returns price to main function
        return CalcPrice();
    }
};
