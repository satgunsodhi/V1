//#include "master.cpp"
#include <iostream>
#include <string>
#include <iomanip> // for std::endl
using namespace std;

class Car {
public:
    string location;
    string choice2;
    int distance;
    int distanceCost;
    int seatType;
    Car() : distance(0), distanceCost(0) {}

    void calculateFare() {
        cout << "Enter your location (A/B/C): ";
        cin >> location;
        if (location == "A") {
            cout << "A1\nDo you want to go to A1? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 25;
            }
            cout << "A2\nDo you want to go to A2? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 25;
            }
            cout << "A3\nDo you want to go to A3? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 25;
            }
            cout << "A4\nDo you want to go to A4? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 25;
            }
            cout << "A5\nDo you want to go to A5? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += 25;
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
    }
};
