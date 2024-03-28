#include <iostream>
#include <cstring>
#include <string>
#include "master.cpp"
using namespace std;

class plane: private master {
    int airline;
    int noOfAdults;
    int noOfMinors;
    int routeOption;
    int seatType;
    int stops;
    
    public:
    plane(int noOfAdults, int noOfMinors, int routeOption , int seatType, int stops ,char[] DepartingLocation, char[] Destination)
    {
        this -> noOfAdults = noOfAdults;
        this -> noOfMinors = noOfMinors;
        this -> routeOption = routeOption;
        this -> seatType = seatType;
        this -> stops = stops;
        strcpy(this -> DepartingLocation,DepartingLocation);
        strcpy(this -> Destination,Destination);
    }

    char* oneWayRoutes();
    char* roundTripRoutes();
    char* MultiCityRoutes();

};

void showPlane()
{
    // display all the available routes
}


void AddPlane(char DepartingLocation[], char Destination[]) 
{
    int noOfAdults;
    int noOfMinors;
    int routeOption;
    int seatType;
    int stops;
    cin >> noOfAdults;
    cin >> noOfMinors;
    cin >> routeOption;
    cin >> seatType;
    cin >> stops;
    plane p1(noOfAdults,noOfMinors,routeOption,seatType,stops,DepartingLocation,Destination);
    showPlane();
}