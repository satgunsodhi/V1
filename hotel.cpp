#include "master.cpp"
#include <iostream>
#include <ctype.h>
#include <string.h>
#include <cmath>
using namespace std;

class Hotel: public master
{
    public:
    int roomcount;
    float price;
    char hotelName[40];
    char roomType[20];
    void display();
<<<<<<< HEAD
    void PrintBill(const char * roomname, float people, int base);
=======
    int PrintBill();
    void f1(const char * roomname, int people, int base);
>>>>>>> 04b67c3b2e69fb721e83a6139c2cd3f8332b47f4
    Hotel(master &m) : master("Ignore")
    {
        this->Destination.LocationId = m.Destination.LocationId;
        this-> NoofPassengers = m.NoofPassengers;
        this->Duration = m.Duration;
        GST=12;
        display();
    }
};

void Hotel::display()
{
    int c1,c2;

    //Destination.LocationId 1-MANALI
    if(Destination.LocationId==1)
    {
        while(true)
        {
            cout<<"\nMAIN MENU:"<<endl<<"1. The Royal Majestic Mountain View"<<endl<<"2. Hotel New Meadows Inn"<<endl<<"3. Exit";
            cout<<"\nEnter your choice: ";
            cin>>c1;
            if(c1==1)
            {
                strcpy(hotelName,"The Royal Majestic Mountain View");
                cout<<"\nFACILITIES AVAILABLE: Complementary Breakfast, Free Parking and WIFI, Pool and Gym inclusive";
                cout<<"\nMENU:"<<endl<<"1. King Room (2 guests max,4000/-)"<<endl<<"2. Deluxe Family Suite (4 guests max,7000/-)"<<endl<<"3. Go back to MAIN";
                cout<<"\nChoose room type: ";
                cin>>c2;
                if(c2==1)
                {
                    PrintBill("King Room", 2.0,4000);
                    break;
                }

                else if(c2==2)
                {
                    PrintBill("Deluxe Family Suite", 4.0,7000);
                    break;
                }
                else if(c2==3)
                {
                    continue;
                }
                else
                {
                    cout<<"Invalid Choice";
                    continue;
                }
            }
            else if(c1==2)
            {
                strcpy(hotelName,"Hotel New Meadows Inn");
                cout<<"\nFACILITIES AVAILABLE: Complementary Brekafast, Free WIFI, Spa and Sauna\n";
                cout<<"\nMENU:"<<endl<<"1. Double Room (2 guests max,2000/-)"<<endl<<"2. Family Room with Balcony (4 guests max,5000/-)"<<endl<<"3. Go back to MAIN";
                cout<<"\nChoose room type: ";
                cin>>c2;
                if(c2==1)
                {
                    PrintBill("Double Room", 2.0,2000);
                    break;
                }
                else if(c2==2)
                {
                    PrintBill("Family Room with Balcony", 4.0,5000);
                    break;
                }
                else if(c2==3)
                {
                    continue;
                }
                else
                {
                    cout<<"Invalid Choice";
                    continue;
                }
            }
            else if(c1==3)
            {
                break;
            }
            else
            {
                cout<<"Invalid Choice";
                continue;
            }
        }
    }

    //Destination.LocationId 2-GOA
    else if(Destination.LocationId==2)
    {
        while(true)
        {
            cout<<"\nMAIN MENU:"<<endl<<"1. Casa De Goa"<<endl<<"2. The Fern Habitat"<<endl<<"3. Exit";
            cout<<"\nEnter your choice: ";
            cin>>c1;
            if(c1==1)
            {
                strcpy(hotelName,"Casa De Goa");
                cout<<"\nFACILITIES AVAILABLE: Complementary Breakfast, Free Parking and WIFI, Pool and Gym inclusive";
                cout<<"\nMENU:"<<endl<<"1. King Room (2 guests max,1000/-)"<<endl<<"2. Deluxe Family Suite (4 guests max,4000/-)"<<endl<<"3. Go back to MAIN";
                cout<<"\nChoose room type: ";
                cin>>c2;
                if(c2==1)
                {
                    PrintBill("King Room", 2.0,1000);
                    break;
                }
                else if(c2==2)
                {
                    PrintBill("Deluxe Family Suite", 4.0,4000);
                    break;
                }
                else if(c2==3)
                {
                    continue;
                }
                else
                {
                    cout<<"Invalid Choice";
                    continue;
                }
            }
            else if(c1==2)
            {
                strcpy(hotelName,"The Fern Habitat");
                cout<<"\nFACILITIES AVAILABLE: Complementary Brekafast, Free WIFI, Spa and Sauna";
                cout<<"\nMENU:"<<endl<<"1. Double Room (2 guests max,3000/-)"<<endl<<"2. Family Room with Balcony (4 guests max,6000/-)"<<endl<<"3. Go back to MAIN";
                cout<<"\nChoose room type: ";
                cin>>c2;
                if(c2==1)
                {
                    PrintBill("Double Room", 2.0,3000);
                    break;
                }
                else if(c2==2)
                {
                    PrintBill("Family Room with Balcony", 4.0,6000);
                    break;
                }
                else if(c2==3)
                {
                    continue;
                }
                else
                {
                    cout<<"Invalid Choice";
                    continue;
                }
            }
            else if(c1==3)
            {
                break;
            }
            else
            {
                cout<<"Invalid Choice";
                continue;
            }
        }
    }

    //Destination.LocationId 3- SIKKIM
    else if(Destination.LocationId==3)
    {
        while(true)
        {
            cout<<"\nMAIN MENU:"<<endl<<"1. Golden Crescent"<<endl<<"2. Vivanta"<<endl<<"3. Exit";
            cout<<"\nEnter your choice: ";
            cin>>c1;
            if(c1==1)
            {
                strcpy(hotelName,"Golden Crescent");
                cout<<"\nFACILITIES AVAILABLE: Complementary Breakfast, Free Parking and WIFI, Pool and Gym inclusive";
                cout<<"\nMENU:"<<endl<<"1. King Room (2 guests max, 2000/-)"<<endl<<"2. Deluxe Family Suite (4 guests max, 5000/-)"<<endl<<"3. Go back to MAIN";
                cout<<"\nChoose room type: ";
                cin>>c2;
                if(c2==1)
                {
                    PrintBill("King Room", 2.0,2000);
                    break;
                }
                else if(c2==2)
                {
                    PrintBill("Deluxe Family Suite", 4.0,5000);
                    break;
                }
                else if(c2==3)
                {
                    continue;
                }
                else
                {
                    cout<<"Invalid Choice";
                    continue;
                }
            }
            else if(c1==2)
            {
                strcpy(hotelName,"Vivanta");
                cout<<"\nFACILITIES AVAILABLE: Complementary Brekafast, Free WIFI, Spa and Sauna";
                cout<<"\nMENU:"<<endl<<"1. Double Room (2 guests max, 5000/-)"<<endl<<"2. Family Room with Balcony (4 guests max, 10000/-)"<<endl<<"3. Go back to MAIN";
                cout<<"\nChoose room type: ";
                cin>>c2;
                if(c2==1)
                {
                    PrintBill("Double Room", 2.0,5000);
                    break;
                }
                else if(c2==2)
                {
                    PrintBill("Family Room with Balcony", 4.0,10000);
                    break;
                }
                else if(c2==3)
                {
                    continue;
                }
                else
                {
                    cout<<"Invalid Choice";
                    continue;
                }
            }
            else if(c1==3)
            {
                break;
            }
            else
            {
                cout<<"Invalid Choice";
                continue;
            }
        }
    }
    price=price*ceil(Duration.timeReadOut()/24);
}
void Hotel::PrintBill(const char * roomname, float people, int base) 
{
    strcpy(roomType, roomname);
    roomcount=ceil(NoofPassengers/people);
<<<<<<< HEAD
    price=((base*roomcount)+(NoofPassengers-roomcount)*300)*(1+GST/100);
    cout<<"\nHotel Booked!!" << endl;
    cout<<"\n--------------------------------------------------------------------------------";
    cout<<"\n| Name of the Hotel: " << hotelName;
    cout<<"\n| Type of Room: "<<roomType;
    cout<<"\n| Number of Rooms: "<<roomcount;
    cout<<"\n| GST= "<<GST<<"%";
    cout<<"\n| Total Price for Hotel along with additional(if needed): Rs."<<price;
    cout<<"\n-------------------------------------------------------------------------------\n";
=======
    price=((base-roomcount)+(NoofPassengers-roomcount)*300)*(1+GST/100);
    cout<<"\nHotel Booked!!" << endl;
    //cout<<"check"<<price;
    //here it prints correct
    cout<<"\n-------------------------------------------------";
    cout<<"\n| Name of the Hotel: "<<hotelName<<" |";
    cout<<"\n| Type of Room: "<<roomType<<" |";
    cout<<"\n| Number of Rooms: "<<roomcount<<" |";
    cout<<"\n| GST= "<<GST<<"% |";
    cout<<"\n| Total Price for Hotel along with additional(if needed): Rs."<<price<<" |";
    cout<<"\n-------------------------------------------------\n";
>>>>>>> 04b67c3b2e69fb721e83a6139c2cd3f8332b47f4
}
int Hotel::PrintBill()
{
    //here it says 0
    cout<<"\n--------------------------------------------------------------------------------";
    cout<<"\n| Name of the Hotel: "<<hotelName<<"|";
    cout<<"\n| Type of Room: "<<roomType<<"                                      |";
    cout<<"\n| Number of Rooms: "<<roomcount<<"                                              |";
    cout<<"\n| GST= "<<GST<<"%                                                       |";
    cout<<"\n| Total Price for Hotel along with additional(if needed): Rs."<<price<<"    |";
    cout<<"\n-------------------------------------------------------------------------------\n";
    return 0;
}