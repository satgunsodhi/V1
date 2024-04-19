//#include "master.cpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Location {
protected:
    int location;
    string choice2;
    int distance;
public:
    Location() : distance(0) {}

    void selectLocation() {
        cout << "TOURIST PLACES" << endl;
        cout << "1.Goa\n2.Manali\n3.Sikkim" << endl;
        cout << "Where do you want to go? ";
        cin >> location;
    }

    void calculateFare() {
        cout << "Retry" << endl;
    }
};

class Car : public Location {
private:
    int distanceCost;
    int seatType;
public:
    Car() : distanceCost(0) {}

    void calculateFare() {
        selectLocation();

        if (location == 1) {
            cout << "Aguada Fort\nDo you want to go to Aguada Fort? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') distance += 35;
            
            cout << "Dudhsagar\nDo you want to go to Dudhsagar? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') distance += 33;

            cout << "Panaji\nDo you want to go to Panaji? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') distance += 40;

            cout << "Baga beach\nDo you want to go to Baga beach? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') distance += 25;

            cout << "Chapora Fort\nDo you want to go to Chapora Fort? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') distance += 22;
        }
        else if (location == 2) {
            cout << "Jogini falls\nDo you want to go to Jogini falls? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') distance += 42;

            cout << "Nehru kund\nDo you want to go to Nehru kund? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') distance += 28;

            cout << "Rohtang valley\nDo you want to go to Rohtang valley? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') distance += 25;

            cout << "Mall road\nDo you want to go to Mall road? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') distance += 33;

            cout << "Hadimba devi temple\nDo you want to go to Hadimba devi temple? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') distance += 43;
        }
        else if (location == 3) {
            cout << "Buddha Park\nDo you want to go to C1? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') distance += 21;

            cout << "Hanuman tok\nDo you want to go to Hanuman tok? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') distance += 34;

            cout << "Gurudongmar lake\nDo you want to go to Gurudongmar lake? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') distance += 37;

            cout << "Gangtok\nDo you want to go to Gangtok? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') distance += 49;

            cout << "Khangchendzonga national park\nDo you want to go to Khangchendzonga national park? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') distance += 28;
        }
        cout << "What car type will you prefer[5 seater/7 seater]: ";
        cin >> seatType;
        if (seatType == 5) {
            distanceCost = distance * 19.5;
            cout << "Total Fare: " << distanceCost << endl;
        } else if (seatType == 7) {
            distanceCost = distance * 33;
            cout << "Total Fare: " << distanceCost << endl;
        } else {
            cout << "Please enter either 5 or 7 for car type." << endl;
        }
    }
};
      
