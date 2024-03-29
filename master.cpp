#include <iostream>

class Time;
class Location;

class master {
    protected:
    int Duration;
    int NoOfPassengers;
    char NameOfPassengers[NoOfPassengers][255];
    char DepartingLocation[255];
    char Destination[255];
    float HandlingCharges;
    float ServiceFees;
    float GST;

    void FindRoute()
    {
        // route finding
    };

    float FindBaseCost(int CostPerKm, Location a1, Location a2)
    {
        return CostPerKm*DistanceFinder(a1,a2);
    };

    float CalcGST(int BaseCost)
    {
        return GST*BaseCost;
    };
};

class Time {
    private:
    int hour;
    int minute;
    int second;
};

class Location {
    private:
    int x;
    int y;
    int z;
}

float DistanceFinder(Location a1, Location a2) {
    return ((a1.x-a2.x)**2 + (a1.y+a2.y)**2 + (a1.z+a2.z)**2)**(1/2);
}