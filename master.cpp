#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

class Time;

class Location {
    private:
    float Latitude;
    float Longitude;
    friend float DistanceFinder(Location, Location);
    public:
    char Name[255];
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
    int Duration;
    int NoofPassengers;
    Location DepartingLocation;
    char NameOfPassenger[255];
    Location Destination;
    int BaseCost;
    float HandlingCharges = 150;
    float ServiceFees;
    float GST;
    friend class Train;

    public:
    master() {
        cin >> NoofPassengers;
        cin >> NameOfPassenger;
        cin >> NoofPassengers;
        cin >> Destination.Name;
        cin >> DepartingLocation.Name;
        cin >> Duration;
    }
    float FindBaseCost(int,Location, Location);
    float CalcGST(int);
};

float master::FindBaseCost(int CostPerKm, Location a1, Location a2) {
    return CostPerKm*DistanceFinder(a1,a2);
};

float master::CalcGST(int BaseCost) {
    return GST*BaseCost;
};

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
};


float DistanceFinder(Location a1, Location a2) {
    return acos(sin(a1.Latitude)*sin(a2.Latitude)+cos(a1.Latitude)*cos(a2.Latitude)*cos(a2.Longitude-a1.Longitude))*6371;
}