#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include "train.cpp"
#include "hotel.cpp"
#include "car.cpp"
#include "plane.cpp"
#include "package.cpp"
using namespace std;

int main() {
    master m1;
    master *modeOfTransport;
    cout << "\nDo you want custom/packages (1:Custom, 2:Package)?\nChoice: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        int mode;
        while(true) {
            cout << "\nWhich mode of you transport would you prefer? (1:Plane, 2:Train)\nEnter Choice as indicated: ";
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
            cout << "Ah! It seems you have selected something outside of scope, Do Try Again!\n";
            continue;
        }
        cout << modeOfTransport->PrintBill();
        cout << "\nWould you wish to have a hotel reservation? [1:Yes, 0:No]: ";
        cin >> choice;
        if(choice == 1) {
            Hotel h1(m1);
        }
        
        cout << "What is the best way around town? Our Car valet!\nOpt for our option car valet? [1:Yes, 2:No]: ";
        cin >> choice;
        if(choice == 1) {
            Car c1(m1);
        }
    }
    else if (choice == 2) {
        Package p1(m1);
    }

    cout << "\n----------------------------Trip Summary----------------------------\n";
    cout << "Would you like to settle the bill? [1:Yes, 0:No]: ";
    cin >> choice;
    if (choice != 1) {
        cout << "It is a shame to let you go :(";
        return 0;
    }
    cout << "\nBill Paid!"; 
    cout << "\nYou have gotten one heck of a deal!\n";
    cout << "Come back again for your next trip!\n";
    cout << "Happy Travels!\n";
}