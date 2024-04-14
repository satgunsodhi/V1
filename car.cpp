//#include "master.cpp"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Location {
protected:
    string location;
    string choice2;
    int distance;
public:
    Location() : distance(0) {}
    virtual void calculateFare() = 0;
};

class Car : public Location {
private:
    int distanceCost;
    int seatType;
public:
    Car() : distanceCost(0) {}

    void calculateFare() override {
        cout << "Enter your location (A/B/C): ";
        cin >> location;
        if (location == "A") {
            cout << "A1\nDo you want to go to A1? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 35;
            }
            cout << "A2\nDo you want to go to A2? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 33;
            }
            cout << "A3\nDo you want to go to A3? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 40;
            }
            cout << "A4\nDo you want to go to A4? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 25;
            }
            cout << "A5\nDo you want to go to A5? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 22;
            }
        }
        if (location == "B") {
            cout << "B1\nDo you want to go to B1? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 42;
            }
            cout << "B2\nDo you want to go to B2? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 28;
            }
            cout << "B3\nDo you want to go to B3? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 25;
            }
            cout << "B4\nDo you want to go to B4? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 33;
            }
            cout << "B5\nDo you want to go to B5? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 43;
            }
        }
        if (location == "C") {
            cout << "C1\nDo you want to go to C1? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 21;
            }
            cout << "C2\nDo you want to go to C2? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 34;
            }
            cout << "C3\nDo you want to go to C3? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 37;
            }
            cout << "C4\nDo you want to go to C4? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 49;
            }
            cout << "C5\nDo you want to go to C5? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 28;
            }
        }
        cout << "What car type will you prefer[5 seater/7 seater]: ";
        cin >> seatType;
        if (seatType == 5) {
            distanceCost = distance * 19.5;
            cout << "Total Fare: " << distanceCost << endl;
        }
        else if (seatType == 7) {
            distanceCost = distance * 33;
            cout << "Total Fare: " << distanceCost << endl;
        }
        else {
            cout << "Please enter either 5 or 7 for car type." << endl;
        }
    }
};
