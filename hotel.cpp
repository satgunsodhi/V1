#include "master.cpp"
#include "main.cpp"
#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;

class Hotel
{
    public:
    int location;
    int num;
    int duration;
    int roomcount;
    float price;
    char hotelName[40];
    char roomType[20];
    void display();
    Hotel(int location,int noOfpeople,int duration)
    {
        this->location=location;
        this->num=noOfpeople;
        this->duration=duration;
    }
};

void Hotel::display()
{
    int c1,c2;

    //LOCATION 1-MANALI
    if(location==1)
    {
        while(true)
        {
            cout<<"MAIN MENU:"<<endl<<"1. The Royal Majestic Mountain View"<<endl<<"2. Hotel New Meadows Inn"<<endl<<"3. Exit";
            cout<<"Enter your choice: ";
            cin>>c1;
            if(c1==1)
            {
                strcpy(hotelName,"The Royal Majestic Mountain View");
                cout<<"FACILITIES AVAILABLE: Complementary Breakfast, Free Parking and WIFI, Pool and Gym inclusive";
                cout<<"MENU:"<<endl<<"1. King Room (2 guests max)"<<endl<<"2. Deluxe Family Suite (4 guests max)"<<endl<<"3. Go back to MAIN";
                cout<<"Choose room type: ";
                cin>>c2;
                if(c2==1)
                {
                    strcpy(roomType,"King Room");
                    roomcount=ceil(num/2);
                    price=(4000-roomcount)+(num-roomcount)*300;
                }
                else if(c2==2)
                {
                    strcpy(roomType,"Deluxe Family Suite");
                    roomcount=ceil(num/4);
                    price=(7000-roomcount)+(num-roomcount)*300;
                }
                else if(c2==3)
                {
                    continue;
                }
            }
            else if(c1==2)
            {
                strcpy(hotelName,"Hotel New Meadows Inn");
                cout<<"FACILITIES AVAILABLE: Complementary Brekafast, Free WIFI, Spa and Sauna";
                cout<<"MENU:"<<endl<<"1. Double Room (2 guests max)"<<endl<<"2. Family Room with Balcony (4 guests max)"<<endl<<"3. Go back to MAIN";
                cout<<"Choose room type: ";
                cin>>c2;
                if(c2==1)
                {
                    strcpy(roomType,"Double Room");
                    roomcount=ceil(num/2);
                    price=(2000-roomcount)+(num-roomcount)*300;
                }
                else if(c2==2)
                {
                    strcpy(roomType,"Family Room with Balcony");
                    roomcount=ceil(num/4);
                    price=(5000-roomcount)+(num-roomcount)*300;
                }
                else if(c2==3)
                {
                    continue;
                }
            }
            else
            {
                break;
            }
        }
    }

    //LOCATION 2-GOA
    else if(location==2)
    {
        while(true)
        {
            cout<<"MAIN MENU:"<<endl<<"1. Casa De Goa"<<endl<<"2. The Fern Habitat"<<endl<<"3. Exit";
            cout<<"Enter your choice: ";
            cin>>c1;
            if(c1==1)
            {
                strcpy(hotelName,"Casa De Goa");
                cout<<"FACILITIES AVAILABLE: Complementary Breakfast, Free Parking and WIFI, Pool and Gym inclusive";
                cout<<"MENU:"<<endl<<"1. King Room (2 guests max)"<<endl<<"2. Deluxe Family Suite (4 guests max)"<<endl<<"3. Go back to MAIN";
                cout<<"Choose room type: ";
                cin>>c2;
                if(c2==1)
                {
                    strcpy(roomType,"King Room");
                    roomcount=ceil(num/2);
                    price=(1000-roomcount)+(num-roomcount)*300;
                }
                else if(c2==2)
                {
                    strcpy(roomType,"Deluxe Family Suite");
                    roomcount=ceil(num/4);
                    price=(4000-roomcount)+(num-roomcount)*300;
                }
                else if(c2==3)
                {
                    continue;
                }
            }
            else if(c1==2)
            {
                strcpy(hotelName,"The Fern Habitat");
                cout<<"FACILITIES AVAILABLE: Complementary Brekafast, Free WIFI, Spa and Sauna";
                cout<<"MENU:"<<endl<<"1. Double Room (2 guests max)"<<endl<<"2. Family Room with Balcony (4 guests max)"<<endl<<"3. Go back to MAIN";
                cout<<"Choose room type: ";
                cin>>c2;
                if(c2==1)
                {
                    strcpy(roomType,"Double Room");
                    roomcount=ceil(num/2);
                    price=(3000-roomcount)+(num-roomcount)*300;
                }
                else if(c2==2)
                {
                    strcpy(roomType,"Family Room with Balcony");
                    roomcount=ceil(num/4);
                    price=(6000-roomcount)+(num-roomcount)*300;
                }
                else if(c2==3)
                {
                    continue;
                }
            }
            else
            {
                break;
            }
        }
    }

    //LOCATION 3- SIKKIM
    else if(location==3)
    {
        while(true)
        {
            cout<<"MAIN MENU:"<<endl<<"1. Golden Crescent"<<endl<<"2. Vivanta"<<endl<<"3. Exit";
            cout<<"Enter your choice: ";
            cin>>c1;
            if(c1==1)
            {
                strcpy(hotelName,"Golden Crescent");
                cout<<"FACILITIES AVAILABLE: Complementary Breakfast, Free Parking and WIFI, Pool and Gym inclusive";
                cout<<"MENU:"<<endl<<"1. King Room (2 guests max)"<<endl<<"2. Deluxe Family Suite (4 guests max)"<<endl<<"3. Go back to MAIN";
                cout<<"Choose room type: ";
                cin>>c2;
                if(c2==1)
                {
                    strcpy(roomType,"King Room");
                    roomcount=ceil(num/2);
                    price=(2000-roomcount)+(num-roomcount)*300;
                }
                else if(c2==2)
                {
                    strcpy(roomType,"Deluxe Family Suite");
                    roomcount=ceil(num/4);
                    price=(5000-roomcount)+(num-roomcount)*300;
                }
                else if(c2==3)
                {
                    continue;
                }
            }
            else if(c1==2)
            {
                strcpy(hotelName,"Vivanta");
                cout<<"FACILITIES AVAILABLE: Complementary Brekafast, Free WIFI, Spa and Sauna";
                cout<<"MENU:"<<endl<<"1. Double Room (2 guests max)"<<endl<<"2. Family Room with Balcony (4 guests max)"<<endl<<"3. Go back to MAIN";
                cout<<"Choose room type: ";
                cin>>c2;
                if(c2==1)
                {
                    strcpy(roomType,"Double Room");
                    roomcount=ceil(num/2);
                    price=(5000-roomcount)+(num-roomcount)*300;
                }
                else if(c2==2)
                {
                    strcpy(roomType,"Family Room with Balcony");
                    roomcount=ceil(num/4);
                    price=(10000-roomcount)+(num-roomcount)*300;
                }
                else if(c2==3)
                {
                    continue;
                }
            }
            else
            {
                break;
            }
        }
    }
    price=price*duration;
}