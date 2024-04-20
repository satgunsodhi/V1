#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car {
protected:
    int location;
    string choice2;
    int distance;
public:
    Car() : distance(0) {}

    void selectLocation() {
        cout << "TOURIST PLACES" << endl;
        cout << "1. Goa\n2. Manali\n3. Sikkim" << endl;
        cout << "Where do you want to go? ";
        cin >> location;
    }

    void calculateFare() {
        selectLocation();

        vector<string> list;
        vector<int> dist;

        if (location == 1) {
            list = {"Aguada Fort", "Dudhsagar", "Panaji", "Baga beach", "Chapora Fort"};
            dist = {100, 120, 25, 140, 80};
        } else if (location == 2) {
            list = {"Jogini falls", "Nehru kund", "Rohtang valley", "Mall road", "Hadimba devi temple"};
            dist = {110, 76, 130, 95, 150};
        } else if (location == 3) {
            list = {"Buddha Park", "Hanuman tok", "Gurudongmar lake", "Gangtok", "Khangchendzonga national park"};
            dist = {98, 76, 135, 87, 133};
        } else {
            cout << "Invalid location choice." << endl;
            return;
        }

        for (int i = 0; i < 5; i++) {
            cout << list[i] << "\nDo you want to go to " << list[i] << "? [Y/N]: ";
            cin >> choice2;
            if (choice2[0] == 'Y' || choice2[0] == 'y') {
                distance += dist[i];
            }
        }

        int seatType;
        cout << "What car type will you prefer[5 seater/7 seater]: ";
        cin >> seatType;
        int distanceCost;
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
