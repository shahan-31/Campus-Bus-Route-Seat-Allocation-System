#include <iostream>
using namespace std;

int main()
{
    int choice;

    int RouteID[6];
    // Total # of Routes and it should be Unique.

    int RouteStops[6];
    // Total # of Stops.

    char RouteNames[180];
    /* Purpose:
    This stores the Name of the route (e.g., "Red Line", "Campus Loop", "City Express").
    Why we need it:
    When a student books a seat, they need to know
    which bus line they are taking. We print this name on the screen so they can choose.
    */

    char RouteStartingLocation[180];
    /*
    Purpose:
    This stores the Starting Location (e.g., "Main Gate", "Hostel 1", "DHA Phase 6").
    Why we need it:
    Students need to know where the bus
    begins its journey so they can plan their pickup.
    */

    char RouteEndingLocation[180];
    /*
    Purpose:
    This stores the Destination / Ending Location (e.g., "University Campus", "City Center").
    Why we need it:
    Students need to know where the bus is going to drop them off.
    */

    int BusID[6];
    /*
    Purpose: Stores the Unique ID of the physical bus (e.g., Bus #99, Bus #500).
    Why: Just like a car license plate, every bus needs a unique number so you can tell them apart.
    When you assign a driver or check for repairs (in real life), you use this ID.
    */

    int BusRouteID[6];
    /*
    Purpose: Stores the Route ID that this bus is assigned to drive.
    Why: A bus doesn't just drive anywhere; it drives a specific path.
    If busRouteIDs[0] stores 101, it means Bus 0 is driving Route 101.
    This "links" the Bus arrays to the Route arrays. Without this, the bus wouldn't know where it's going.
    */

    int BusCapacity[6];
    /*
    Purpose: Stores the Total Number of Seats available on that bus (e.g., 40 seats, 60 seats.
    Why: You need to know the limit. You cannot book 41 students on a bus that only has 40 seats.
    This number acts as the "safety ceiling" for bookings.

    BusCapacity[6] means Seats in 6 Different Buses and not 6 Seats per Bus.
    */

    int BusSelectedSeats[6];
    /*
    Purpose: Stores the Count of Seats Currently Taken (e.g., 5 students have booked so far).
    Why: Availability: Capacity - Allocated = Remaining Seats.
    You need this to tell a student "Yes, we have space" or "Sorry, full."
    Updates: Every time you book a student (Option 5), you increase this number (+1). Every time you cancel (Option 7), you decrease it (-1).
    */

    //Z
    //module 3 student registration for transport (for 200 students)
    int alocationID[200];
    int studentID[200];
    char studentName[2000]; // 10*200 bcz we will take 0to10
    char studentDepartment[2000];
    int semester[200];
    char studentContactNumber[2200]; // 200 student contact no with 11 char is 2200 ie 200*11
    int routeIDallocation[200];
    int busIDAllocation[200];
    int seatNumber[200];
    int feeStatus[200];

    //inizializing allocations variables of module3 
    for (int studentallocations = 0; studentallocations < 200; studentallocations++)
    {
         alocationID[studentallocations] = -1;
         studentID[studentallocations] = -1;
         semester[studentallocations] = 0;
         routeIDallocation[studentallocations] = -1;
         busIDAllocation[studentallocations] = -1;
         seatNumber[studentallocations] = 0;
         feeStatus[studentallocations] = 0;
    }
    for (int studentNameAndDepartment = 0; studentNameAndDepartment < 2000; studentNameAndDepartment++)
    {
        studentName[studentNameAndDepartment] = '\0';
        studentDepartment[studentNameAndDepartment] = '0';
    }
    for (int contactsOfStudents = 0; contactsOfStudents < 2200; contactsOfStudents++)
    {
        studentContactNumber[contactsOfStudents] = '\0';
    }
    //Z
    


    cout << "--------------------------------------------" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  Bus Route & Seat Allocation System" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "1) Initialize / Reset Routes & Buses" << endl;
    cout << "2) Add / Replace Route Records" << endl;
    cout << "3) Add / Replace Bus Records" << endl;
    cout << "4) Display Routes & Bus Seat Status" << endl;
    cout << "5) Allocate Seat to Student (Transport Registration)" << endl;
    cout << "6) Update Student Alocation Record" << endl;
    cout << "7) Cancel Seat Allocation" << endl;
    cout << "8) Search / Listings" << endl;
    cout << "9) Display Bus Seat Occupancy View" << endl;
    cout << "10) Validate Records & Detect Conflicts" << endl;
    cout << "11) Generate reports / Summaries" << endl;
    cout << "0) Exit" << endl;
    cout << "-----------------------------------" << endl;
    cout << endl;
    cout << endl;
    do
    {


        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            /*

            Module 1: Initialization / Reset

     Reset all Route IDs to -1
     Reset all Route Text (Names/Start/End) to empty
     Reset all Bus IDs to -1
     Reset all Bus Capacities/Counts to 0

            */
            cout << "Initialize / Reset Routes & Buses selected." << endl;

            for (int routeCounter = 0; routeCounter < 6; routeCounter++) // Goes to every 6 Buses
            {
                RouteID[routeCounter] = -1;
                // -1 means (This particular slot is empty).

                RouteStops[routeCounter] = 0;
                // We wrote 0 because an empty route has no stops.

                int StartingPointOfLockerOfRoute = routeCounter * 30;
                // This tells us where this route starts from.

                /*
    Starting Point of Route Based on their Index

    Index 0 = 0 * 30 = 0
    1st Route Starting at 0

    Index 1 = 1 * 30 = 30
    2nd Route Starting at 30

    Index 2 = 2 * 30 = 60
    3rd Route Starting at 60

    Index 3 = 3 * 30 = 90
    4th Route Starting at 90

    Index 4 = 4 * 30 = 120
    5th Route Starting at 120

    Index 5 = 5 * 30 = 150
    6th Route Starting at 150

    and then 6th Route Ending is till 180.
    */

    // '\0' means nothing like an empty string.

                RouteNames[StartingPointOfLockerOfRoute] = '\0';
                // Route Names are now empty.

                RouteStartingLocation[StartingPointOfLockerOfRoute] = '\0';
                // Route Starting Point is now Empty.

                RouteEndingLocation[StartingPointOfLockerOfRoute] = '\0';
                // Route Ending Location is now Empty.
            }

            for (int busCounter = 0; busCounter < 6; busCounter++)
            {
                BusID[busCounter] = -1;
                // No Bus ID.

                BusRouteID[busCounter] = -1;
                // No Bus Route ID.

                BusCapacity[busCounter] = 0;
                // The Total Bus Capacity is 0.

                BusSelectedSeats[busCounter] = 0;
                // The Seats Selected are not selected now means 0.
            }

            cout << "All Routes and Bus Records have been Successfully Cleared." << endl;
            cout << endl;

        }
        break;
        case 2:
        {
            /*
             Module 2: Add / Replace Route Records
    Find the first empty slot (-1) in routeIDs
    Input a Temporary Route ID
    Check if that ID already exists (Duplicate Check)
    If valid, save ID to the empty slot
    Input Route Name, Start Point, End Point (using offset logic)
    Input Total Stops Count
            */

            cout << "Add / Replace Route Records selected." << endl;
            cout << endl;

            int FreeSlotMethod = -1;
            /* Empty Slot Key which basically says If this Slot is Empty
               Then work on this specific slot and If not Empty then just leave it.
            */

            for (int freeSlotCounter = 0; freeSlotCounter < 6; freeSlotCounter++)
                // FreeSlotCouunter is a Counter Variable to remember which slot is empty by checking indexes of the variables.
            {
                if (RouteID[freeSlotCounter] == -1)
                    // Empty Route ID Found.
                {
                    FreeSlotMethod = freeSlotCounter;
                    // Assigned Free Slot with Free Slot Counter Value 
                    // Indicating on now lets work on this Free Slot

                    break;
                    // Break as we found one.
                }
            }

            if (FreeSlotMethod == -1)
            {
                cout << "No Space Left! All 6 Routes are Full." << endl;
                // No Route ID is Empty so which means all Routes are basically FULL.
            }
            else
            {
                int TemporaryID;
                cout << "Enter New Route ID -- Eg.(101): ";
                cin >> TemporaryID;
                // Getting RouteID from User and also so we can check if this ID is already TAKEN.

                bool RouteID_Exists = false;

                for (int routeID_DuplicateCheckCounter = 0; routeID_DuplicateCheckCounter < 6; routeID_DuplicateCheckCounter++)
                    // Iterate through every RouteID and check if the Duplicates Exists.
                {
                    if (RouteID[routeID_DuplicateCheckCounter] == TemporaryID)
                    {
                        RouteID_Exists = true;
                        // Duplicate Route ID Found.
                        break;
                    }
                }

                if (RouteID_Exists)
                    // Duplicate Found is True so Error.
                {
                    cout << "Error: Route ID " << TemporaryID << " already exists. Please Try Again." << endl;
                }

                else
                {
                    RouteID[FreeSlotMethod] = TemporaryID;
                    // We went to the blank row and assigned it with the ID user gave.

                    cout << "Enter Route Name -- Eg.(Blue Line): ";
                    cin.ignore();
                    /*
                    This is like clearing your throat. The computer gets confused by the "Enter" key you pressed after typing "101".
                    This command eats that key so the computer is ready for the name.
                    */

                    int StartingPointOfLockerOfRoute = FreeSlotMethod * 30;
                    // This tells us where this route starts from.
                    // Read text into the specific section of the long array

                /*
    Starting Point of Route Based on their Index

    Index 0 = 0 * 30 = 0
    1st Route Starting at 0

    Index 1 = 1 * 30 = 30
    2nd Route Starting at 30

    Index 2 = 2 * 30 = 60
    3rd Route Starting at 60

    Index 3 = 3 * 30 = 90
    4th Route Starting at 90

    Index 4 = 4 * 30 = 120
    5th Route Starting at 120

    Index 5 = 5 * 30 = 150
    6th Route Starting at 150

    and then 6th Route Ending is till 180.
    */
                    cin.getline(&RouteNames[StartingPointOfLockerOfRoute], 30);
                    // Got Complete Word for Route Name from USER.

                    cout << "Enter Starting Point of Route: ";
                    cin.getline(&RouteStartingLocation[StartingPointOfLockerOfRoute], 30);
                    // Got Complete Word for Starting Location of Route from USER.

                    cout << "Enter Ending Point of Route: ";
                    cin.getline(&RouteEndingLocation[StartingPointOfLockerOfRoute], 30);
                    // Got Complete Word for Ending Location of Route from USER.

                    cout << "Enter Route Stops: ";
                    cin >> RouteStops[FreeSlotMethod];
                    cout << endl;

                    cout << "Route " << TemporaryID << " added Successfully at Slot " << FreeSlotMethod << "!" << endl;
                    cout << endl;
                }
            }
        }
        break;
        case 3:
        {
            cout << "Add / Replace Bus Records selected." << endl;
            cout << endl;

            int FreeBusSLotMethod = -1;
            // Finding an empty Bus Slot Via -1.

            for (int freeBusSlotMethodCounter = 0; freeBusSlotMethodCounter < 6; freeBusSlotMethodCounter++)
            {
                if (BusID[freeBusSlotMethodCounter] == -1)
                    // -1 means Empty.
                {
                    FreeBusSLotMethod = freeBusSlotMethodCounter;
                    break;
                    // Found one and now Stop Looking.
                }
            }

            if (FreeBusSLotMethod == -1)
            {
                cout << "Error: No Space Left! ALL 6 Buses are Full." << endl;
            }
            else
            {
                // We have a Temporary Bus Slot which is Empty so now lets fill it up.
                int TemporaryBusID;
                cout << "Enter New Bus ID -- Eg.(501): ";
                cin >> TemporaryBusID;

                // Process of Checking Duplicate Bus IDs.
                bool BusIDExists = false;
                for (int busIDExistsCounter = 0; busIDExistsCounter < 6; busIDExistsCounter++)
                {
                    if (BusID[busIDExistsCounter] == TemporaryBusID)
                    {
                        // Meaning  Bus Id Found its Duplicate.
                        BusIDExists = true;
                        break;
                    }
                }

                if (BusIDExists)
                {
                    // Duplicate Found, So Pop up of ERROR Message.
                    cout << "Error: Bus ID " << TemporaryBusID << " already exits!. Please Try Again." << endl;
                }
                else
                {
                    // Now Route ID Work and Its Validation and its Job is that if the route ID Exists 
                    // Then the Bus can finally go there.

                    int TemporaryAssignedRouteID;
                    cout << "Enter Assigned Route ID -- Eg.(101): ";
                    cin >> TemporaryAssignedRouteID;

                    // Check: Does this route already exist?
                    bool AssignedRouteFound = false;
                    for (int assignedRouteFoundCounter = 0; assignedRouteFoundCounter < 6; assignedRouteFoundCounter++)
                    {
                        if (RouteID[assignedRouteFoundCounter] == TemporaryAssignedRouteID)
                        {
                            // We found the Route which does Exists! Good News.
                            AssignedRouteFound = true;
                            break;
                        }
                    }

                    if (AssignedRouteFound == false)
                    {
                        // We couldn't find the Route to go to.
                        cout << "Error: Assigned Route ID " << TemporaryAssignedRouteID << " not found! Please create the route first." << endl;
                        cout << endl;

                    }
                    else
                    {
                        // We have the Desired route for the Bus to go so we will save it.
                        BusID[FreeBusSLotMethod] = TemporaryBusID;
                        // Saving Bus ID.
                        BusRouteID[FreeBusSLotMethod] = TemporaryAssignedRouteID;
                        // Saving Bus Route ID.


                        // Now Bus Seat Capacity
                        cout << "Enter Bus Capacity (Seats): ";
                        cin >> BusCapacity[FreeBusSLotMethod];

                        // Reset Bus Seats because like you know New Bus Always Starts Empty
                        BusSelectedSeats[FreeBusSLotMethod] = 0;

                        cout << "Bus " << TemporaryBusID << " added successfully!" << endl;
                        // Hence New Bus Created Successfully
                        cout << endl;
                    }
                }
            }
        }
        break;
        case 4:
        {
            cout << "Display Routes & Bus Seat Status selected." << endl;
            cout << endl;

            // This case is all about displaying things.
            /*
            Header: Print a nice table header (Route ID | Bus ID | Status | etc.).

Loop through Buses: Since buses are the main thing that carry people, we usually iterate through the BusID array (0 to 5).

Check Empty Slots: If a bus slot is -1 (empty), we skip it.

Find Matching Route Info:

The Bus array has the BusRouteID (e.g., 101).

We need to find the Name of Route 101 (e.g., "Red Line").

Challenge: We have to search the RouteID array to find which index matches 101, then grab the name from that same index.

Calculate Availability: Available = Capacity - SelectedSeats.

Print Row: Show all the details in one line.
            */

            cout << "==========================================================================================" << endl;
            cout << "                          CURRENT BUS STATUS REPORT                                       " << endl;
            cout << "==========================================================================================" << endl;
            // Using tabs (\t) to space things out
            cout << "Bus ID\tRoute ID\tRoute Name\t\tCapacity\tBooked\tAvailable" << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;

            // First we will check if the system is completely empty.
            bool FoundAnyBus = false;
            // Basically we are finding Bus

            for (int foundBusCounter = 0; foundBusCounter < 6; foundBusCounter++)
            {
                if (BusID[foundBusCounter] != -1)
                {
                    FoundAnyBus = true;

                    // Logic of Printing the Details out.

                    int CurrentRouteID = BusRouteID[foundBusCounter];
                    // Get Bus Route ID this Bus is Assigned to.

                    int RouteIndex = -1;
                    // Find the Index where the Route Name LIVE.
                    // Deafult it will be equal to -1, meaning not found.

                    // Searching the Route List.
                    for (int routeListCounter = 0; routeListCounter < 6; routeListCounter++)
                    {
                        if (RouteID[routeListCounter] == CurrentRouteID)
                        {
                            // We saved the location.
                            RouteIndex = routeListCounter;
                            break;
                        }
                    }

                    // Now Calculating Seats
                    int AvailableSeats = BusCapacity[foundBusCounter] - BusSelectedSeats[foundBusCounter];

                    // Printing
                    cout << BusID[foundBusCounter] << "\t" << CurrentRouteID << "\t\t";

                    if (RouteIndex != -1)
                    {
                        // Route Name Printing If Found.
                        cout << &RouteNames[RouteIndex * 30];
                    }
                    else
                    {
                        // Route might have been Deleted.
                        cout << "N/A";
                    }

                    if (RouteIndex != -1)
                    {
                        cout << "\t\t";
                    }
                    else
                    {
                        cout << "\t\t";
                    }


                    cout << BusCapacity[foundBusCounter] << "\t\t" << BusSelectedSeats[foundBusCounter] << "\t" << AvailableSeats << endl;
                }
            }

            if (!FoundAnyBus)
            {
                cout << "\t\t\t( No Bus Registered )" << endl;
            }
            cout << "------------------------------------------------------------------------------------------" << endl;
            cout << endl;

        }
        break;          //z
        case 5: // allocate seats to student  //Z
        {
            cout << "Allocate Seat to Student selected." << endl;
            cout << endl;
            cout << "Student Seat Allocation" << endl;
            // route exists or not? if not then we will ask to add the route
            bool hasRoute = false;
            for (int routecheck = 0; routecheck < 6; routecheck++)
            {
                if (RouteID[routecheck] != -1)  
                {
                    hasRoute = true;        // means it has route
                    break;
                }
            }

            if (!hasRoute)  //if there is no route available 
            {
                cout << "No routes are available . first add the routes." << endl;
                break; // no route r there so we will break
            }

            //now we will find the empty slots and max are 200 allocation
            int alocationIndex = -1;
            



        }//Z
        break;
        case 6:
        {
            cout << "Update Student Allocation Record selected." << endl;
        }
        break;
        case 7:
        {
            cout << "Cancel Seat Allocation selected." << endl;
        }
        break;
        case 8:
        {
            cout << "Search / Listings selected." << endl;
        }
        break;
        case 9:
        {
            cout << "Display Bus Seat Occupancy View selected." << endl;
        }
        break;
        case 10:
        {
            cout << "Validate Records & Detect Conflicts selected." << endl;
        }
        break;
        case 11:
        {
            cout << "Generate Reports / Summaries selected." << endl;
        }
        break;
        case 0:
        {
            cout << "Exiting program. Goodbye." << endl;
        }
        break;
        default:
            cout << "Invalid Choice.Please Try Again." << endl;
        }
    } while (choice != 0); // Repeats till user enters 0


    return 0;
}
