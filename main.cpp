#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include "train.cpp"
#include "hotel.cpp"
#include "car.cpp"
#include "plane.cpp"
using namespace std;

int main() {
    cout << "Enter Personal Details:\nEnter the no of passengers:";
    int choice;
    int NoOfPassengers;
    char DepartingLocation[255];
    char Destination[255];
    cin >> NoofPassengers;
    cout << "Enter the name of passengers";
    char NameofPassengers[NoOfPassengers];
    for(int i = 0; i < NoOfPassengers; i++) {
        cin >> NameOfPassengers[i];
    }
    cout << "What brings you today?:\n1. Book a Plane\n2. Book a Train\n3. Rent a Car\n4. Stay at a hotel";
    cin >> choice;
    cout << "Enter your Departing Location";
    cin >> DepartingLocation;
    cout << "Enter your Destination";
    cin >> Destination;
    switch(choice) {
        case 1:
            Addplane(NoOfPassengers, NameOfPassengers, DepartingLocation, Destination);
        case 2:
            Addtrain(NoOfPassengers, NameOfPassengers, DepartingLocation, Destination);
        case 3:
            RentCar(NoOfPassengers, NameOfPassengers, DepartingLocation, Destination);
        case 4:
            AddHotel(NoOfPassengers, NameOfPassengers, DepartingLocation, Destination);
    }
}