#include<iostream>
using namespace std;
int main()
{
 // Campus Bus Route & Seat Allocation System

// Route and Bus Setup
  // 8 Routes
    int routesID[8]={101, 102, 103, 104, 105, 106, 107, 108};
    // char routeName[8]={'L', 'I', 'K', 'M', 'F', 'S', 'R', 'G'};
    
    char routeName[8];
    
    // L --> Lahore
    // I --> Islamabad
    // K --> Karachi
    // M --> Multan
    // F --> Faisalabad
    // S --> Sargodha
    // R --> Rawalpindi
    // G --> Gujranwala
    cout << "Enter L or l for City Lahore" << endl;
    cout << "Enter I or i for City Islamabad" << endl;
    cout << "Enter K or k for City Karachi" << endl;
    cout << "Enter M or m for City Multan" << endl;
    cout << "Enter F or f for City Faisalabad" << endl;
    cout << "Enter S or s for City Sargodha" << endl;
    cout << "Enter R or r for City Rawalpindi" << endl;
    cout << "Enter G or g for City Gujranwala" << endl;
    
    for(int i=0; i<8; i++)
    {
      cin>>routeName[i];
    }

return 0;
}
