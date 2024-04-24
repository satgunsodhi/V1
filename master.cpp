#ifndef _OBJECT_H
#define _OBJECT_H
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include "banners.cpp"
using namespace std;


class Date
{
    int date;
    int month;
    int year;

    public:
    Date(int date, int month, int year)
    {
        this ->date = date;
        this ->month = month;
        this ->year = year;
    }
    Date()
    {
        this ->date = 0;
        this ->month = 0;
        this ->year = 0;
    }

    string DisplayDate()
    {
        return to_string(date) + "/" + to_string(month) + "/" + to_string(year); 
    }
    void setDate() 
    {
        cout << endl << "When would you like to Travel?" << endl;
        int days30[] = {4,6,9,11};
        int days31[] = {1,3,5,7,8,10,12};
        while (true)
        {
            cout << "DD: ";
            SetConsoleTextAttribute(hc, 0x0A);
            cin >> date;
            SetConsoleTextAttribute(hc, 0x07);
            cout << "MM: ";
            SetConsoleTextAttribute(hc, 0x0A);
            cin >> month;
            SetConsoleTextAttribute(hc, 0x07);
            year = 2024;

            if (month > 12 || month < 1)
            {
                cout << "Invalid Date";
                setDate();
                return ;
            }
            
            for (int i = 0; i < sizeof(days30)/sizeof(days30[0]); i++)
            {
                if (month == days30[i] && (date > 30 || date < 0))
                {
                    cout << "Invalid Date";
                    setDate();
                    return ;
                }
                
            }
            for (int i = 0; i < sizeof(days31)/sizeof(days31[0]); i++)
            {
                if (month == days31[i] && (date > 31 || date < 0))
                {
                    cout << "Invalid Date";
                    setDate();
                    return ;
                }
                
            }
            if (month == 2 && (date > 29 || date < 0))
            {
                cout << "Invalid Date";
                setDate();
                return ;
            }
            break;
        }
    }
};
//creating time class
class Time {
    private:
    int hour;
    int minute;
    int second;
    public:
    Time(int hour, int minute, int second) {
        this-> hour = hour;
        this-> minute = minute;
        this-> second = second;
    }
    Time() {
        hour = 0; minute = 0; second = 0;
    }
    friend ostream & operator << (ostream &out, Time &loc);

    Time operator+(Time const &t1) { 
        // operator overloading
        Time out;
        out.hour = hour + t1.hour;
        out.minute = minute + t1.minute;
        out.second = second + t1.second;
        return out;
    }

    void set(int hour, int minute, int secoud = 0) {
        this -> hour = hour;
        this -> minute = minute;
        this -> second = second;
    }

    void randomTimeGenerator() { 
        // random time generator
        const int Hour_lb = 0, Hour_ub = 23;
        const int min_lb = 0, min_ub = 59;

        this -> hour = rand() % (Hour_ub - Hour_lb + 1) + Hour_lb;
        this -> minute = rand() % (min_ub - min_lb + 1) + min_lb;
    }

    float timeReadOut() { 
        // get an hour readout
        return hour+minute/60+second/3600;
    }
};

// defining location class
class Location {
    private:
    float Latitude;
    float Longitude;
    friend float DistanceFinder(Location, Location);
    public:
    string Name;
    int LocationId;
    char LocationPin[255];
    void set(float Latitude, float Longitude) {
        this -> Latitude = Latitude*3.14152/180;
        this -> Longitude = Longitude*3.14152/180;
    }
    Location() {};

    void operator=(const Location &loc) { 
        // assignment operator overload
        Latitude = loc.Latitude;
        Longitude = loc.Longitude;
        Name = loc.Name;
        LocationId = loc.LocationId;
        strcpy(LocationPin, loc.LocationPin);
    }
};

// creating a class for everyone to inherit from
class master {

    // defining base variables
    protected:
    Time Duration;
    Date date;
    int NoofPassengers;
    Location DepartingLocation;
    char NameOfPassenger[255];
    Location Destination;
    string Route;
    int BaseCost;
    float HandlingCharges = 150;
    float ServiceFees;
    float GST;


    // letting other classes use master's private variables
    friend class Train;
    friend class Plane;
    friend class Car;
    friend class Hotel;
    friend class Package;

    public:
    master() { 
        // default constructor
        cout << "\n\t\t\t\t\tWelcome To GetSetJourneys Travels!\n";
        cout << "---------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Please Enter Some Personal Info to get started!\n";
        cout << "Enter Name of head Passenger: ";
        SetConsoleTextAttribute(hc, 0x0A);
        cin.getline(NameOfPassenger,255);
        SetConsoleTextAttribute(hc, 0x07);
        cout << "How many of you will be travelling with us? ";
        SetConsoleTextAttribute(hc, 0x0A);
        cin >> NoofPassengers;
        SetConsoleTextAttribute(hc, 0x07);
        cout << "\n\nWhere do you wish to visit? \n1. Sikkim\n2. Goa\n3. Manali\nEnter Choice as indicated: ";
        while(true) {
            SetConsoleTextAttribute(hc, 0x0A);
            cin >> Destination.LocationId;
            SetConsoleTextAttribute(hc, 0x07);
            if (Destination.LocationId > 0 && Destination.LocationId <= 3) {
                break;
            }
            cout << "We dont serve there yet! Please choose from the given choices: ";
        }
        cout << "\n\nWhere will you be travelling from?\n1. Mumbai\n2. Delhi\n3. Kolkata\nEnter Choice as indicated: ";
        while(true) {
            SetConsoleTextAttribute(hc, 0x0A);
            cin >> DepartingLocation.LocationId;
            SetConsoleTextAttribute(hc, 0x07);
            if (DepartingLocation.LocationId > 0 && DepartingLocation.LocationId <= 3) {
                break;
            }
            cout << "We dont serve there yet! Please choose from the given choices: ";
        }
        setloc(Destination, DepartingLocation); // adding name to both location objects
        date.setDate();
        SetConsoleTextAttribute(hc, 0x0A);
        cout << endl << "Searching for Trips on "<< date.DisplayDate() << "....." << endl << endl;
        SetConsoleTextAttribute(hc, 0x07);
        Sleep(1000);
    }

    master(const char * inp) {}; // adding so default constructor is not called in derived classes

    // defining some default functions for derived classes to use
    virtual float FindBaseCost(int,Location, Location);
    virtual float CalcGST();
    virtual float CalcPrice();
    virtual int getRoute();
    virtual int PrintBill();
    void setloc(Location &, Location&);
};

float master::FindBaseCost(int CostPerKm, Location a1, Location a2) {
    return CostPerKm*DistanceFinder(a1,a2); // finding cost by finding distance
};

float master::CalcGST() {
    return GST/100*BaseCost; // getting gst value
};

ostream & operator << (ostream &out,  Time &time) {
    out << time.hour << 'h' << time.minute << 'm' << time.second << 's';
    return out; // operator overloading for cout
}

float DistanceFinder(Location a1, Location a2) {
    // calculating distance from latitude and longitude
    fflush(stdin);
    float R = 6371;
    float r1 = a1.Latitude;
    float r2 = a2.Latitude;
    float phi = a2.Latitude - a1.Latitude;
    float lam = a2.Longitude - a1.Longitude;
    float a = sin(phi/2)*sin(phi/2)+cos(a1.Latitude)*cos(a2.Latitude)*sin(lam/2)*sin(lam/2);
    float c = 2*atan2(sqrt(a), sqrt(1-a));
    float d = R * c;
    return d; 
}

float master::CalcPrice() {
    // finding final price
    return BaseCost+CalcGST()+HandlingCharges+ServiceFees;
}

int master::getRoute() {
    // outputs route
    cout << Route;
    return 0;
}

int master::PrintBill() {
    cout << "Bill will be printed here once the function is overridden\n";
    return 0;
}

void master::setloc(Location &Destination, Location &DepartingLocation) {
    // setting location name and coordinates for both location objects
    switch (Destination.LocationId) {
        case 1:
            Destination.Name = "Sikkim";
            Destination.set(27.3516,88.3239);
            break;
        case 2:
            Destination.Name = "Goa";
            Destination.set(15.2993,74.1240);
            break;
        case 3:
            Destination.Name = "Manali";
            Destination.set(32.2432, 77.1892);
            break;
    }

    switch (DepartingLocation.LocationId)
    {
    case 1:
        DepartingLocation.Name = "Mumbai";
        DepartingLocation.set(19.0760, 72.8777);
        break;
    
    case 2:
        DepartingLocation.Name = "Delhi";
        DepartingLocation.set(28.7041, 77.1025);
        break;
    
    case 3:
        DepartingLocation.Name = "Kolkata";
        DepartingLocation.set(22.5726, 88.3639);
        break;
    }
}
#endif
