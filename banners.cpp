#include<iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);


void Title()
{
    SetConsoleTextAttribute(hc, 0x0C);
    cout << endl;
    cout << " .d8888b.           888    .d8888b.           888  888888                                                              \n";      
    cout << "d88P  Y88b          888   d88P  Y88b          888    .88b                                                              \n";           
    cout << "888    888          888   Y88b.               888     888                                                              \n";
    cout << "888         .d88b.  888888 .Y888b.    .d88b.  888888  888  .d88b.  888  888 888d888 88888b.   .d88b.  888  888 .d8888b \n";
    cout << "888  88888 d8P  Y8b 888       .Y88b. d8P  Y8b 888     888 d88..88b 888  888 888P.   888 .88b d8P  Y8b 888  888 88K     \n";
    cout << "888    888 88888888 888         .888 88888888 888     888 888  888 888  888 888     888  888 88888888 888  888 .Y8888b.\n";
    cout << "Y88b  d88P Y8b.     Y88b. Y88b  d88P Y8b.     Y88b.   88P Y88..88P Y88b 888 888     888  888 Y8b.     Y88b 888      X88\n";
    cout << " .Y8888P88  .Y8888   .Y888 .Y8888P.   .Y8888   .Y888  888  .Y88P.   .Y88888 888     888  888  .Y8888   .Y88888  88888P'\n";
    cout <<"                                                    .d88P                                                  888         \n";
    cout <<"                                                 .d88P.                                              Y8b d88P         \n";
    cout <<"                                                888P.                                                 .Y88P\n" ;
    SetConsoleTextAttribute(hc, 0x07);
}

void FlightBanner()
{
    SetConsoleTextAttribute(hc, 0x03);
    cout << "\t\t\t\t\tBook a Flight" << endl;
    SetConsoleTextAttribute(hc, 0x07);
}
void TrainBanner()
{
    SetConsoleTextAttribute(hc, 0x03);
    cout << "\t\t\t\t\tBook a Train" << endl;
    SetConsoleTextAttribute(hc, 0x07);
}
void HotelBanner()
{
    SetConsoleTextAttribute(hc, 0x03);
    cout << "\t\t\t\t\tBook a Hotel" << endl;
    SetConsoleTextAttribute(hc, 0x07);
}
void CabBanner()
{
    SetConsoleTextAttribute(hc, 0x03);
    cout << "\t\t\t\t\tBook a Cab" << endl;
    SetConsoleTextAttribute(hc, 0x07);
}
void PackagesBanner()
{
    SetConsoleTextAttribute(hc, 0x03);
    cout << "\t\t\t\t\tPackages" << endl;
    SetConsoleTextAttribute(hc, 0x07);
}
void BillingBanner()
{
    SetConsoleTextAttribute(hc, 0x03);
    cout << "\t\t\t\t\tBilling, Payments and Summary" << endl;
    SetConsoleTextAttribute(hc, 0x07);
}

void LineOne()
{
    cout << endl;
    system("cls");
    SetConsoleTextAttribute(hc, 0x0A);
    cout << "==================================================================================================================================\n";
    cout << "                                                           Loading...                                                             \n";
    cout << "==================================================================================================================================\n" << endl;
    SetConsoleTextAttribute(hc, 0x07);
    Sleep(1000);
    system("cls");
}
void LineTwo()
{
    SetConsoleTextAttribute(hc, 0x06);
    cout << "----------------------------------------------------------------------------------------------------------------------------------\n";
    SetConsoleTextAttribute(hc, 0x07);
}
