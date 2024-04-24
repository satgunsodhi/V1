#include <iostream>
#include <cstring>
#include "master.cpp"

using namespace std; // Function prototype

int run(string, int);

// Package class inheriting from 'master' class
class Package : public master {
    public:
    // Copy constructor
    Package(master &m1) : master("Ignore") {
        // Copying data from 'master' object to 'Package' object
        this -> NoofPassengers = m1.NoofPassengers;
        strcpy(NameOfPassenger, m1.NameOfPassenger);
        DepartingLocation.LocationId = m1.DepartingLocation.LocationId;
        Destination.LocationId = m1.Destination.LocationId;
        Destination.Name = m1.Destination.Name;
        run(Destination.Name, NoofPassengers);
    }
    int PrintBill() {return 0;}; // Printing bill 
};

// Option class for package option
class Option {
public:
    string name;
    double cost;

    // Constructor initializing name and cost
    Option(const string& name, double cost) : name(name), cost(cost) {}
};

// Transportation class inheriting from Option class
class Transportation : public Option {
public:
    string mode;

    // Constructor initializing mode and cost using Option constructor
    Transportation(const string& mode, double cost) : Option(mode, cost), mode(mode) {}
};

// Accommodation class inheriting from Option class
class Accommodation : public Option {
public:
    int num_rooms;

    // Constructor initializing name, cost, and number of rooms using Option constructor
    Accommodation(const string& name, double cost, int num_rooms) : Option(name, cost), num_rooms(num_rooms) {}
};

// Trip class representing a trip package
class Trip {
private:
    Transportation transport;
    Accommodation accommodation;
    int num_people;
    double total_cost;
    string itinerary;
    string destination;

public:
    // Constructor initializing trip details
    Trip(const string& destination, const Transportation& transport, const Accommodation& accommodation, int num_people, const string& itinerary)
        : destination(destination), transport(transport), accommodation(accommodation), num_people(num_people), itinerary(itinerary) {
        total_cost = calculateTripCost();
    }

    // Function to calculate total cost of the trip
    double calculateTripCost() const {
        return transport.cost * num_people + accommodation.cost;
    }

    // Get functions for trip details
    double getTotalCost() const { return total_cost; }
    int getNumPeople() const { return num_people; }
    int getNumRooms() const { return accommodation.num_rooms; }
    const string& getDestination() const { return destination; }

    // Functions to display trip details
    void display() const {
        cout << "Destination: " << destination << endl;
        cout << "Transportation: " << transport.mode << endl;
        cout << "Accommodation: " << accommodation.name << endl;
        cout << "Number of People: " << num_people << endl;
        cout << "Number of Rooms: " << accommodation.num_rooms << endl;
        cout << "Total Cost: Rs." << total_cost << endl;
        cout << "Itinerary: " << endl << itinerary << endl; // Display itinerary
    }
};

// Function to display available packages for a destination based on user preferences
void displayAvailablePackages(const Trip* packages, int numPackages, const string& destination, double Cost, int Passengers, int Rooms) {
    cout << "Available Packages for " << destination << ":" << endl;
    for (int i = 0; i < numPackages; ++i) {
        const Trip& package = packages[i];
        // Check if package meets user preferences
        if (package.getDestination() == destination &&
            package.getTotalCost() <= Cost &&
            package.getNumPeople() >= Passengers &&
            package.getNumRooms() >= Rooms) {
            package.display();
            cout << endl;
        }
    }
}

// Function to print receipt
void printReceipt(const Trip& chosenPackage) {
    cout << "Receipt for the chosen tour package:" << endl;
    chosenPackage.display();
}

int run(string destination, int NoofPassengers) {
    // Transportation options
    Transportation car("Car", 50.0);
    Transportation train("Train", 100.0);
    Transportation plane("Plane", 200.0);

    // Accommodation options
    Accommodation budgetHotel("Budget Hotel", 50.0, 1);
    Accommodation standardHotel("Standard Hotel", 100.0, 2);
    Accommodation luxuryHotel("Luxury Hotel", 200.0, 3);

    // Array to store pre-made packages
    const int numPackages = 9;
    Trip packages[numPackages] = {
        Trip("Sikkim", car, budgetHotel, 2, "Itinerary for Sikkim:\nDay 1: Arrival and check-in at the hotel.\nDay 2: Sightseeing around the city.\nDay 3: Departure."),
        Trip("Sikkim", train, standardHotel, 4, "Itinerary for Sikkim:\nDay 1: Arrival and check-in at the hotel.\nDay 2-3: Explore local attractions.\nDay 4: Departure."),
        Trip("Sikkim", plane, luxuryHotel, 6, "Itinerary for Sikkim:\nDay 1: Arrival and transfer to the hotel.\nDay 2-4: Enjoy leisure activities and city tours.\nDay 5: Departure."),
        Trip("Goa", car, standardHotel, 3, "Itinerary for Goa:\nDay 1: Arrival and check-in at the hotel.\nDay 2: Explore nearby attractions.\nDay 3: Departure."),
        Trip("Goa", train, luxuryHotel, 2, "Itinerary for Goa:\nDay 1: Arrival and transfer to the luxury hotel.\nDay 2: Enjoy spa and relaxation.\nDay 3: Departure."),
        Trip("Goa", plane, budgetHotel, 5, "Itinerary for Goa:\nDay 1: Arrival and check-in at the budget hotel.\nDay 2-4: Visit tourist attractions.\nDay 5: Departure."),
        Trip("Manali", car, standardHotel, 3, "Itinerary for Manali:\nDay 1: Arrival and check-in at the hotel.\nDay 2: Beach activities.\nDay 3: Departure."),
        Trip("Manali", train, luxuryHotel, 2, "Itinerary for Manali:\nDay 1: Arrival and transfer to the luxury hotel.\nDay 2: Explore the nightlife.\nDay 3: Departure."),
        Trip("Manali", plane, budgetHotel, 4, "Itinerary for Manali:\nDay 1: Arrival and check-in at the hotel.\nDay 2-3: Water sports.\nDay 4: Departure.")
    };

    double Cost;
    int Passengers, Rooms;
    cout << "Enter your budget (min. 10,000/-Rs): Rs.";
    cin >> Cost;
    Passengers = NoofPassengers;
    cout << "Enter number of rooms: ";
    cin >> Rooms;
    bool packagesAvailable = false;
    do {
        // Loop until suitable packages are found
        displayAvailablePackages(packages, numPackages, destination, Cost, Passengers, Rooms);
        for (int i = 0; i < numPackages; ++i) {
            const Trip& package = packages[i];
            if (package.getDestination() == destination &&
                package.getTotalCost() <= Cost &&
                package.getNumPeople() >= Passengers &&
                package.getNumRooms() >= Rooms) {
                packagesAvailable = true;
                break;
            }
        }
        // If no suitable packages found, prompt user to adjust preferences
        if (!packagesAvailable) {
            cout << "No packages available for the given details. ";
            cout << "Please adjust your preferences.\n";
            cout << "Enter your budget: Rs.";
            cin >> Cost;
            Passengers = NoofPassengers;
            cout << "Enter number of rooms: ";
            cin >> Rooms;
        }
    } while (!packagesAvailable);

    // Choose a package
    int choice;
    cout << "Enter the package number you want to choose: ";
    cin >> choice;
    
    // Print reciept
    if (choice >= 1 && choice <= numPackages) {
        const Trip& chosenPackage = packages[choice - 1];
        printReceipt(chosenPackage);
    } else {
        cout << "Invalid package choice!" << endl;
    }
    return 0;
}
