#include <iostream>

class master {
    protected:
    char ClassName[255];
    char Destination[255];
    char route1[255];
    char route2[255];
    float HandlingCharges;
    float ServiceFees;
    float GST;
};

class Time {
    protected:
    int hour;
    int minute;
    int second;
};