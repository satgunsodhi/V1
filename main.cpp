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
    Title(); // printing logo
    master m1; // defining an object of base class to use the default constructor once
    LineOne(); // visuals
    int price = 0;
    cout << "\nDo you want custom/packages (1:Custom, 2:Package)?\nChoice: ";
    int choice;
    SetConsoleTextAttribute(hc, 0x0A);
    cin >> choice;
    SetConsoleTextAttribute(hc, 0x07);
    LineOne();
    if (choice == 1) {
        int mode;
        while(true) {
            // checking choice for a valid mode of transport input
            cout << "\nWhich mode of you transport would you prefer? (1:Plane, 2:Train)\nEnter Choice as indicated: ";
            SetConsoleTextAttribute(hc, 0x0A);
            cin >> mode;
            SetConsoleTextAttribute(hc, 0x07);
            LineOne();
            if(mode == 1) {
                FlightBanner();
                Plane p1(m1);
                if (p1.BookingConfirm)
                {
                    price += p1.PrintBill(); // printing bill and adding return value calcprice to global price
                }
                Sleep(5000);
                LineOne();
                break;
            }
            else if (mode == 2) {
                TrainBanner();
                Train t1(m1);
                price += t1.PrintBill(); // printing bill and adding return value calcprice to global price
                Sleep(5000);
                LineOne();
                break;
            }
            LineTwo();
            cout << "Ah! It seems you have selected something outside of scope, Do Try Again!\n";
            LineTwo();
            continue;
        }
        HotelBanner();
        cout << "\nWould you wish to have a hotel reservation? [1:Yes, 0:No]: ";
        SetConsoleTextAttribute(hc, 0x0A);
        cin >> choice; // asking if hotel reservation is required
        SetConsoleTextAttribute(hc, 0x07);
        if(choice == 1) {
            Hotel h1(m1);
            price += h1.PrintBill(); // printing bill and adding return value calcprice to global price
            Sleep(5000);
        }
        LineOne();
        CabBanner();
        cout << "What is the best way around town? Our Car valet!\nOpt for our option car valet? [1:Yes, 2:No]: ";
        SetConsoleTextAttribute(hc, 0x0A);
        cin >> choice; // asking if car tour is desired
        SetConsoleTextAttribute(hc, 0x07);
        if(choice == 1) {
            Car c1(m1);
            price += c1.PrintBill(); // printing bill and adding return value calcprice to global price
            Sleep(5000);
            LineOne();
        }
    }
    else if (choice == 2) {
        PackagesBanner();
        Package p1(m1); // jumping to seperate interface for package
    }

    // billing, payments and summary
    BillingBanner();
    cout << "\n----------------------------------------------Trip Summary------------------------------------------------------------------------\n";
    cout << "Trip for: " << m1.NameOfPassenger;
    cout << "\nDate: " << m1.date;
    cout << "\nRoute: " << m1.Route;
    cout << "\nTotal Cost for Trip: " << price << endl;
    cout << "Would you like to settle the bill? [1:Yes, 0:No]: ";
    SetConsoleTextAttribute(hc, 0x0A);
    cin >> choice;
    SetConsoleTextAttribute(hc, 0x07);
    if (choice != 1) {
        cout << "It is a shame to let you go :(";
        return 0;
    }
    LineOne();
    cout << "\nBill Paid!\n";

    // exit
    LineTwo();
    cout << "\nYou have gotten one heck of a deal!\n";
    cout << "Come back again for your next trip!\n";
    cout << "Happy Travels!\n";
}