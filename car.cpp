#include <iostream>
#include "master.cpp"
#include <string>
#include <cstring>
using namespace std;

class Car {
    public:
    string location;
    char choice2[2];
    int distance;
    int distanceCost;
    int seatType;
    Car() : distance(0), distanceCost(0) {}

    void calculateFare() {
        cin>>location;
        if(location == "A"){
            cout<<"A1"<<endl<<"Do u want to go to A1?[Y/N]";
            cin>>choice2;
            if(choice2[0] == 'Y'){
                distance+=20;
            }
            cout<<"A2"<<endl<<"Do u want to go to A2?[Y/N]";
            cin>>choice2;
            if(choice2[0] == 'Y'){
                distance+=20;
            }
            cout<<"A3"<<endl<<"Do u want to go to A3?[Y/N]";
            cin>>choice2;
            if(choice2[0] == 'Y'){
                distance+=20;
            }
            cout<<"A4"<<endl<<"Do u want to go to A4?[Y/N]";
            cin>>choice2;
            if(choice2[0] == 'Y'){
                distance+=20;
            }
            cout<<"A5"<<endl<<"Do u want to go to A5?[Y/N]";
            cin>>choice2;
            if(choice2[0] == 'Y'){
                distance+=20;
            }
            cin>>"Car Type[5 seater/7 seater]">>seatType;
            if(seatType==5){
                 distanceCost=distance*20;
                 cout<<"Total Fare"<<distanceCost;
            }
            else if(seatType==7){
                distanceCost=distance*30;
                cout<<"Total Fare"<<distanceCost;
            }
        }

};
