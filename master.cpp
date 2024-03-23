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