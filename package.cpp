#include <iostream>
#include "car.cpp"
#include "hotel.cpp"
#include "train.cpp"
#include "plane.cpp"
using namespace std;

class Package: private master {
    protected:
    int TotalPrice;
};