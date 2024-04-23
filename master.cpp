#ifndef _OBJECT_H
#define _OBJECT_H
#include <iostream>
#include <cmath>
#include <cstring>
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
        this -> hour;
        this -> minute;
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
    char Name[255];
    int LocationId;
    char LocationPin[255];
    Location(float latitude, float Longitude) {
        this -> Latitude = Latitude;
        this -> Longitude = Longitude;
    }
    Location() {};

    void operator=(const Location &loc) {
        Latitude = loc.Latitude;
        Longitude = loc.Longitude;
    }
};


class master {
    protected:
    Time Duration;
    int NoofPassengers;
    Location DepartingLocation;
    char NameOfPassenger[255];
    Location Destination;
    char Route[255];
    int BaseCost;
    float HandlingCharges = 150;
    float ServiceFees;
    float GST;
    friend class Train;
    friend class Plane;
    friend class Car;
    friend class Hotel;

    public:
    master() {
        cout << "Enter Name of head Passenger: ";
        cin >> NameOfPassenger;
        cout << "Enter No. of Passengers: ";
        cin >> NoofPassengers;
        cout << "Please Choose your destination Location: \n1. Shimla\n2. Goa\n3. Manali\n Choice: ";
        cin >> Destination.LocationId;
        cout << "Please Choose your current Location: \n1. Shimla\n2. Goa\n3. Manali\nChoice: ";
        cin >> DepartingLocation.LocationId;
    }

    master(const char * inp) {};
    virtual float FindBaseCost(int,Location, Location);
    virtual float CalcGST(int);
    virtual float CalcPrice();
    virtual void getRoute();
};

float master::FindBaseCost(int CostPerKm, Location a1, Location a2) {
    return CostPerKm*DistanceFinder(a1,a2);
};

float master::CalcGST(int BaseCost) {
    return GST*BaseCost;
};

ostream & operator << (ostream &out,  Time &time) {
    out << time.hour << 'h' << time.minute << 'm' << time.second << 's';
    return out;
}

float DistanceFinder(Location a1, Location a2) {
    return acos(sin(a1.Latitude)*sin(a2.Latitude)+cos(a1.Latitude)*cos(a2.Latitude)*cos(a2.Longitude-a1.Longitude))*6371;
}

float master::CalcPrice() {
    return BaseCost;
}

void master::getRoute() {
    cout << Route;
}
#endif
