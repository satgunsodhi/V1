#include <iostream>

class master {
    protected:
    char DepartingLocation[255];
    char Destination[255];
    float HandlingCharges;
    float ServiceFees;
    float GST;

    void FindRoute()
    {
        // route finding
    };

    float FindCost()
    {
        // cost finding
    };
};

class Time {
    protected:
    int hour;
    int minute;
    int second;
};

class Location {
    protected:
    int x;
    int y;
    int z;
}

float DistanceFinder(Location a1, Location a2) {
    return ((a1.x-a2.x)**2 + (a1.y+a2.y)**2 + (a1.z+a2.z)**2)**(1/2);
}