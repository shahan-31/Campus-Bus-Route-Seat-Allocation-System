#include <iostream>
using namespace std;

int main()
{

    // MODULE 1
    
    // 8 Routes
    int routeID[8] = { 101, 102, 103, 104, 105, 106, 107, 108 };
    // char routeName[8]={'L', 'I', 'K', 'M', 'F', 'S', 'R', 'G'};


    char startingPoint;
    char endingPoint;
    char routeName1;
    char routeName2;
    // L --> Lahore55555555555
    // I --> Islamabad
    // K --> Karachi
    // M --> Multan
    // F --> Faisalabad
    // S --> Sargodha
    // R --> Rawalpindi
    // G --> Gujranwala

    // Starting Point Sub Module
    cout << "Choose Starting Point." << endl;
    cout << endl;
    cout << "Enter L or l for City Lahore" << endl;
    cout << "Enter I or i for City Islamabad" << endl;
    cout << "Enter K or k for City Karachi" << endl;
    cout << "Enter M or m for City Multan" << endl;
    cout << "Enter F or f for City Faisalabad" << endl;
    cout << "Enter S or s for City Sargodha" << endl;
    cout << "Enter R or r for City Rawalpindi" << endl;
    cout << "Enter G or g for City Gujranwala" << endl;
    cout << endl;

    cin >> startingPoint;
    if (startingPoint == 'L' || startingPoint == 'l')
    {
        cout << "You chose Lahore" << endl;
    }
    else if (startingPoint == 'I' || startingPoint == 'i')
    {
        cout << "You chose Islamabad" << endl;
    }
    else if (startingPoint == 'K' || startingPoint == 'k')
    {
        cout << "You chose Karachi" << endl;
    }
    else if (startingPoint == 'M' || startingPoint == 'm')
    {
        cout << "You chose Multan" << endl;
    }
    else if (startingPoint == 'F' || startingPoint == 'f')
    {
        cout << "You chose Faisalabad" << endl;
    }
    else if (startingPoint == 'S' || startingPoint == 's')
    {
        cout << "You chose Sargodha" << endl;
    }
    else if (startingPoint == 'R' || startingPoint == 'r')
    {
        cout << "You chose Rawalpindi" << endl;
    }
    else if (startingPoint == 'G' || startingPoint == 'g')
    {
        cout << "You chose Gujranwala" << endl;
    }
    else
    {
        cout << "City doesn't exist | Error 404" << endl;
    }

    cout << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << endl;

    // Ending Point Sub Module
    cout << "Choose Ending Point." << endl;
    cout << endl;
    cout << "Enter L or l for City Lahore" << endl;
    cout << "Enter I or i for City Islamabad" << endl;
    cout << "Enter K or k for City Karachi" << endl;
    cout << "Enter M or m for City Multan" << endl;
    cout << "Enter F or f for City Faisalabad" << endl;
    cout << "Enter S or s for City Sargodha" << endl;
    cout << "Enter R or r for City Rawalpindi" << endl;
    cout << "Enter G or g for City Gujranwala" << endl;
    cout << endl;

    cin >> endingPoint;
    if (endingPoint == 'L' || endingPoint == 'l')
    {
        cout << "You chose Lahore" << endl;

    }
    else if (endingPoint == 'I' || endingPoint == 'i')
    {
        cout << "You chose Islamabad" << endl;

    }
    else if (endingPoint == 'K' || endingPoint == 'k')
    {
        cout << "You chose Karachi" << endl;

    }
    else if (endingPoint == 'M' || endingPoint == 'm')
    {
        cout << "You chose Multan" << endl;

    }
    else if (endingPoint == 'F' || endingPoint == 'f')
    {
        cout << "You chose Faisalabad" << endl;

    }
    else if (endingPoint == 'S' || endingPoint == 's')
    {
        cout << "You chose Sargodha" << endl;

    }
    else if (endingPoint == 'R' || endingPoint == 'r')
    {
        cout << "You chose Rawalpindi" << endl;

    }
    else if (endingPoint == 'G' || endingPoint == 'g')
    {
        cout << "You chose Gujranwala" << endl;

    }
    else
    {
        cout << "City doesn't exist | Error 404" << endl;
    }

    cout << endl;

    cout << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << endl;

    if (startingPoint == 'L' || startingPoint == 'l' && startingPoint == 'K' || startingPoint == 'k')
    {
        routeName1 = 'L';
        routeName2 = 'K';
    }

    //Zunnu
//one bus assignment module
int busID[8] = { 1,2,3,4,5,6,7,8 };
int busSeats[8] = { 30,30,50,30,60,50,50,60 };
if (startingPoint == 'L' || startingPoint == 'l' && endingPoint == 'K' || endingPoint == 'k')
{
    cout << "Bus ID: " << busID[0]<<endl;
    cout << "Route ID: " << routeID[0] << endl;
    cout << "Total seats are: " << busSeats[0] << endl;

}//
        

    return 0;
}
