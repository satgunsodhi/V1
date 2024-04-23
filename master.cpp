#ifndef _OBJECT_H
#define _OBJECT_H
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

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
        const int Hour_lb = 0, Hour_ub = 23;
        const int min_lb = 0, min_ub = 59;

        this -> hour = rand() % (Hour_ub - Hour_lb + 1) + Hour_lb;
        this -> minute = rand() % (min_ub - min_lb + 1) + min_lb;
    }

    float timeReadOut() {
        return hour+minute/60+second/3600;
    }
};

class Location {
    private:
    float Latitude;
    float Longitude;
    friend float DistanceFinder(Location, Location);
    public:
    string Name;
    int LocationId;
    char LocationPin[255];
    void set(float latitude, float Longitude) {
        this -> Latitude = Latitude*3.14152/180;
        this -> Longitude = Longitude*3.14152/180;
    }
    Location() {};

    void operator=(const Location &loc) {
        Latitude = loc.Latitude;
        Longitude = loc.Longitude;
        Name = loc.Name;
        LocationId = loc.LocationId;
        strcpy(LocationPin, loc.LocationPin);
    }
};


class master {
    protected:
    Time Duration;
    int NoofPassengers;
    Location DepartingLocation;
    char NameOfPassenger[255];
    Location Destination;
    string Route;
    int BaseCost;
    float HandlingCharges = 150;
    float ServiceFees;
    float GST;
    friend class Train;
    friend class Plane;
    friend class Car;
    friend class Hotel;
    friend class Package;

    public:
    master() {
        cout << "\t\t\t\t\tWelcome To GetSetJourneys Travels!\n";
        cout << "------------------------------------------------------------------------------------------------------\n";
        cout << "Please Enter Some Personal Info to get started!\n";
        cout << "Enter Name of head Passenger: ";
        cin.getline(NameOfPassenger,255);
        cout << "How many of you will be travelling with us? ";
        cin >> NoofPassengers;
        cout << "\n\nWhere do you wish to visit? \n1. Sikkim\n2. Goa\n3. Manali\nEnter Choice as indicated: ";
        cin >> Destination.LocationId;
        cout << "\n\nWhere will you be travelling from?\n1. Mumbai\n2. Delhi\n3. Kolkata\nEnter Choice as indicated: ";
        cin >> DepartingLocation.LocationId;
        setloc(Destination, DepartingLocation);
    }

    master(const char * inp) {};
    virtual float FindBaseCost(int,Location, Location);
    virtual float CalcGST();
    virtual float CalcPrice();
    virtual int getRoute();
    virtual int PrintBill();
    void setloc(Location &, Location&);
};

float master::FindBaseCost(int CostPerKm, Location a1, Location a2) {
    return CostPerKm*DistanceFinder(a1,a2);
};

float master::CalcGST() {
    return GST/100*BaseCost;
};

ostream & operator << (ostream &out,  Time &time) {
    out << time.hour << 'h' << time.minute << 'm' << time.second << 's';
    return out;
}

float DistanceFinder(Location a1, Location a2) {
    return acos(sin(a1.Latitude)*sin(a2.Latitude)+cos(a1.Latitude)*cos(a2.Latitude)*cos(a2.Longitude-a1.Longitude))*6371; 
}

float master::CalcPrice() {
    return BaseCost+CalcGST()+HandlingCharges+ServiceFees;
}

int master::getRoute() {
    cout << Route;
    return 0;
}

int master::PrintBill() {
    cout << "testMessage\n";
    return 0;
}

void master::setloc(Location &Destination, Location &DepartingLocation) {
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
    }
}
#endif
