#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include "train.cpp"
//#include "hotel.cpp"
//#include "car.cpp"
#include "plane.cpp"
//#include "package.cpp"
using namespace std;

int main() {
    master m1;
    master *modeOfTransport;
    cout << "Do you want custom/packages (1:Custom, 2:Package)?\nChoice: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        int mode;
        while(true) {
            cout << "Enter your Method of travel (1:Plane, 2:Train): ";
            cin >> mode;
            if(mode == 1) {
                Plane p1(m1);
                modeOfTransport = &p1;
                break;
            }
            else if (mode == 2) {
                Train t1(m1);
                modeOfTransport = &t1;
                break;
            }
            cout << "Invalid Input!";
            continue;
        }
        //Hotel h1(m1);
        //Car c1(m1);
    }
    else if (choice == 2) {
        //Package p1(m1);
    }
    // final route
    // billing and payments
    // exit
}