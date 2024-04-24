#include <iostream>
#include <cstring>
#include "master.cpp"

using namespace std; 

int run(string, int); // Function prototype

// Use of copy constructor
class Package : public master {
    public:
    // Constructor initializing Package object with a master object
    Package(master &m1) : master("Ignore") {
        // Initialize Package object with values from the provided master object
        this -> NoofPassengers = m1.NoofPassengers;
        strcpy(NameOfPassenger, m1.NameOfPassenger);
        DepartingLocation.LocationId = m1.DepartingLocation.LocationId;
        Destination.LocationId = m1.Destination.LocationId;
        Destination.Name = m1.Destination.Name;
        // Run a function to process the destination and number of passengers
        run(Destination.Name, NoofPassengers);
    }
    // Function to print bill
    int PrintBill() {return 0;};
};

// Class 'Option' to represent customizable options
class Option {
public:
    string name;
    double cost;

    // Constructor to initialize option with name and cost
    Option(const string& name, double cost) : name(name), cost(cost) {}
};

// Class 'Transportation' derived from 'Option'
class Transportation : public Option {
public:
    string mode;

    // Constructor to initialize transportation with mode and cost
    Transportation(const string& mode, double cost) : Option(mode, cost), mode(mode) {}
};

// Class 'Accommodation' derived from 'Option'
class Accommodation : public Option {
public:
    int num_rooms;

    // Constructor to initialize accommodation with name, cost, and number of rooms
    Accommodation(const string& name, double cost, int num_rooms) : Option(name, cost), num_rooms(num_rooms) {}
};

// Class 'Trip' to represent a travel package
class Trip {
private:
    Transportation transport;
    Accommodation accommodation;
    int num_people;
    double total_cost;
    string itinerary;
    string destination;

public:
    // Constructor to initialize a Trip object with destination, transport, accommodation, number of people, and itinerary
    Trip(const string& destination, const Transportation& transport, const Accommodation& accommodation, int num_people, const string& itinerary)
        : destination(destination), transport(transport), accommodation(accommodation), num_people(num_people), itinerary(itinerary) {
        total_cost = calculateTripCost();
    }

    // Function to calculate the total cost of the trip
    double calculateTripCost() const {
        return transport.cost * num_people + accommodation.cost;
    }

    // Get functions to access the trip details
    double getTotalCost() const { return total_cost; }
    int getNumPeople() const { return num_people; }
    int getNumRooms() const { return accommodation.num_rooms; }
    const string& getDestination() const { return destination; }
    
    // Function to display trip details
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

// Function to display available packages meeting specified criteria
void displayAvailablePackages(const Trip* packages, int numPackages, const string& destination, double Cost, int Passengers, int Rooms) {
    cout << "Available Packages for " << destination << ":" << endl;
    for (int i = 0; i < numPackages; ++i) {
        const Trip& package = packages[i];
        if (package.getDestination() == destination &&
            package.getTotalCost() <= Cost &&
            package.getNumPeople() >= Passengers &&
            package.getNumRooms() >= Rooms) {
            package.display();
            cout << endl;
        }
    }
}

// Function to print receipt for the chosen package
void printReceipt(const Trip& chosenPackage) {
    cout << "Receipt for the chosen tour package:" << endl;
    chosenPackage.display();
}

// Function to process destination and number of passengers
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
        Trip("Shimla", car, budgetHotel, 2, "Itinerary for Sikkim:\nDay 1: Arrival and check-in at the hotel.\nDay 2: Sightseeing around the city.\nDay 3: Departure."),
        Trip("Shimla", train, standardHotel, 4, "Itinerary for Sikkim:\nDay 1: Arrival and check-in at the hotel.\nDay 2-3: Explore local attractions.\nDay 4: Departure."),
        Trip("Shimla", plane, luxuryHotel, 6, "Itinerary for Sikkim:\nDay 1: Arrival and transfer to the hotel.\nDay 2-4: Enjoy leisure activities and city tours.\nDay 5: Departure."),
        Trip("Manali", car, standardHotel, 3, "Itinerary for Goa:\nDay 1: Arrival and check-in at the hotel.\nDay 2: Explore nearby attractions.\nDay 3: Departure."),
        Trip("Manali", train, luxuryHotel, 2, "Itinerary for Goa:\nDay 1: Arrival and transfer to the luxury hotel.\nDay 2: Enjoy spa and relaxation.\nDay 3: Departure."),
        Trip("Manali", plane, budgetHotel, 5, "Itinerary for Goa:\nDay 1: Arrival and check-in at the budget hotel.\nDay 2-4: Visit tourist attractions.\nDay 5: Departure."),
        Trip("Goa", car, standardHotel, 3, "Itinerary for Manali:\nDay 1: Arrival and check-in at the hotel.\nDay 2: Beach activities.\nDay 3: Departure."),
        Trip("Goa", train, luxuryHotel, 2, "Itinerary for Manali:\nDay 1: Arrival and transfer to the luxury hotel.\nDay 2: Explore the nightlife.\nDay 3: Departure."),
        Trip("Goa", plane, budgetHotel, 4, "Itinerary for Manali:\nDay 1: Arrival and check-in at the hotel.\nDay 2-3: Water sports.\nDay 4: Departure.")
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
        // Display available packages based on user preferences
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

        // If no packages meet the criteria, prompt user to adjust preferences
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
    if (choice >= 1 && choice <= numPackages) {
        const Trip& chosenPackage = packages[choice - 1];
        printReceipt(chosenPackage);
    } else {
        cout << "Invalid package choice!" << endl;
    }
    return 0;
}
