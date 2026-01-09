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

    // Module 3 
    // Student Registration for Transport (for 200 students)
    int AllocationID[200];
    int StudentID[200];
    // 50*200 bcz we will take 0 to 50
    char StudentName[10000];
    // 50*200 bcz we will take 0 to 50
    char StudentDepartment[10000];
    int Semester[200];
    char StudentContactNumber[4000];
    // 200 student contact no with 11 char is 4000 ie 200*20
    int RouteIDAllocation[200];
    int BusIDAllocation[200];
    int SeatNumber[200];
    int FeeStatus[200];

    //inizializing allocations variables of module3 
    for (int studentallocations = 0; studentallocations < 200; studentallocations++)
    {
        AllocationID[studentallocations] = -1;
        StudentID[studentallocations] = -1;
        Semester[studentallocations] = 0;
        RouteIDAllocation[studentallocations] = -1;
        BusIDAllocation[studentallocations] = -1;
        SeatNumber[studentallocations] = 0;
        FeeStatus[studentallocations] = 0;
    }
    for (int studentNameAndDepartment = 0; studentNameAndDepartment < 10000; studentNameAndDepartment++)
    {
        StudentName[studentNameAndDepartment] = '\0';
        StudentDepartment[studentNameAndDepartment] = '\0';
    }
    for (int contactsOfStudents = 0; contactsOfStudents < 4000; contactsOfStudents++)
    {
        StudentContactNumber[contactsOfStudents] = '\0';
    }
    //Z

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



    cout << "--------------------------------------------" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  Bus Route & Seat Allocation System" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    do
    {
        cout << "----------------------------------------------------------------------------------------" << endl;
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
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << endl;

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

            //inizializing allocations variables of module3 
            for (int studentallocations = 0; studentallocations < 200; studentallocations++)
            {
                AllocationID[studentallocations] = -1;
                StudentID[studentallocations] = -1;
                Semester[studentallocations] = 0;
                RouteIDAllocation[studentallocations] = -1;
                BusIDAllocation[studentallocations] = -1;
                SeatNumber[studentallocations] = 0;
                FeeStatus[studentallocations] = 0;
            }
            for (int studentNameAndDepartment = 0; studentNameAndDepartment < 2000; studentNameAndDepartment++)
            {
                StudentName[studentNameAndDepartment] = '\0';
                StudentDepartment[studentNameAndDepartment] = '0';
            }
            for (int contactsOfStudents = 0; contactsOfStudents < 2200; contactsOfStudents++)
            {
                StudentContactNumber[contactsOfStudents] = '\0';
            }

            cout << "All Routes and Bus Records have been Successfully Cleared." << endl;
            cout << "All Student Information has been cleared" << endl;
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
        break; //z
        case 5: // allocate seats to student  //Z
        {
            cout << "Allocate Seat to Student selected." << endl;
            cout << endl;
            cout << "Student Seat Allocation" << endl;
            cout << endl;


            // Now we will find the empty slots and max are 200 allocations
            int AllocationIndex = -1;
            for (int emptySlotCounter = 0; emptySlotCounter < 200; emptySlotCounter++)
            {
                if (AllocationID[emptySlotCounter] == -1)
                    // This will check if any allocation id is free
                {
                    AllocationIndex = emptySlotCounter;
                    //this is to check empty allocation
                    //and it will store available slot 
                    break;
                }
            }
            if (AllocationIndex == -1)
                //this means that there is no empty slot available
            {
                cout << "All are full! Error." << endl;
                break;
            }

            // Now we will take allocation ID and it will be unique not same as another
            cout << "Enter the Allocation ID (unique ID) Eg.(20): ";
            cin >> AllocationID[AllocationIndex];

            // check if the user will enter the duplicate ID
            for (int duplicateIDCounter = 0; duplicateIDCounter < 200; duplicateIDCounter++)
            {
                if (duplicateIDCounter != AllocationIndex && AllocationID[duplicateIDCounter] == AllocationID[AllocationIndex])
                {
                    cout << "Id already exists!" << endl;
                    AllocationID[AllocationIndex] = -1;
                    break;
                }
            }

            if (AllocationID[AllocationIndex] == -1)
            {
                break;
            }

            // Now we will get the id of student
            cout << "Enter the student ID: ";
            cin >> StudentID[AllocationIndex];

            //now we will check if student has already allocated slot ..
            for (int activeAllocationCounter = 0; activeAllocationCounter < 200; activeAllocationCounter++)
            {
                if (activeAllocationCounter != AllocationIndex && AllocationID[activeAllocationCounter] != -1 && StudentID[activeAllocationCounter] == StudentID[AllocationIndex])
                {
                    cout << " Student already has a seat allocated. " << endl;
                    AllocationID[AllocationIndex] = -1;
                    break;
                }
            }
            if (AllocationID[AllocationIndex] == -1)
            {
                break;
            }

            // Now student details
            int NameStudent = AllocationIndex * 50;
            int DepartmentStudent = AllocationIndex * 50;
            int ContactStudent = AllocationIndex * 20;
            //bcz we took 11 no for contact

             /*

             this is bcz
             if allocation index is 0 then
             0*10 = 0 means start from 0
             and if 1*10=10 that means we start
             from position 10

             */

            cout << "Enter Student Name (0 to 50): ";
            cin.ignore();
            cin.getline(&StudentName[NameStudent], 50);

            cout << "Enter Department of student (0 to 50): ";
            cin.getline(&StudentDepartment[DepartmentStudent], 50);

            cout << "Enter the semester (1 to 8): ";
            cin >> Semester[AllocationIndex];

            cout << "Enter contact no: ";
            cin.ignore();
            cin.getline(&StudentContactNumber[ContactStudent], 20);

            cout << "Enter the Route ID: ";
            cin >> RouteIDAllocation[AllocationIndex];

            // Route exists or not? if not then we will ask to add the route
            bool hasRoute = false;
            for (int routeCheckCounter = 0; routeCheckCounter < 6; routeCheckCounter++)
            {
                if (RouteID[routeCheckCounter] == RouteIDAllocation[AllocationIndex])
                {
                    hasRoute = true;
                    // means it has route
                    break;
                }
            }

            if (!hasRoute)
                // If there is no route available 
            {
                cout << "No routes are available, First add the routes." << endl;
                AllocationID[AllocationIndex] = -1;
                break;
                // No route r is there so we will break
            }

            cout << "Enter Bus ID: ";
            cin >> BusIDAllocation[AllocationIndex];

            // Now this will chech bus is there or not
            bool busExist = false;
            int BusIndex = -1;
            for (int busAssignmentCounter = 0; busAssignmentCounter < 6; busAssignmentCounter++)
            {
                if (BusID[busAssignmentCounter] == BusIDAllocation[AllocationIndex])
                {
                    if (BusRouteID[busAssignmentCounter] == RouteIDAllocation[AllocationIndex])
                        // Check that is bus existes dor this route
                    {
                        busExist = true;
                        BusIndex = busAssignmentCounter;
                        break;
                    }
                    else {
                        cout << "Bus is not assigned for this route." << endl;
                        AllocationID[AllocationIndex] = -1;
                        break;
                    }
                }
            }

            if (!busExist)
            {
                if (AllocationID[AllocationIndex] != -1)
                {
                    cout << "Bus do not exists." << endl;
                    AllocationID[AllocationIndex] = -1;
                }
                break;
            }

            // Now we will check if seats are full..
            if (BusSelectedSeats[BusIndex] >= BusCapacity[BusIndex])
            {
                cout << " Bus seats are full. ";
                AllocationID[AllocationIndex] = -1;
                break;

            }
            //..

            cout << "Enter Seat number: ( 1 - " << BusCapacity[BusIndex] << "): ";
            cin >> SeatNumber[AllocationIndex];

            // Now we will check if user user invalid number of seat..
            if (SeatNumber[AllocationIndex] < 1 || SeatNumber[AllocationIndex]>BusCapacity[BusIndex])
            {
                cout << "Invalid seat number bcz each bus has 30 seats." << endl;
                AllocationID[AllocationIndex] = -1;
                break;
            }

            // Now we will check if seat is already assigned on bus
            for (int seat = 0; seat < 200; ++seat)
            {
                if (seat != AllocationIndex && AllocationID[seat] != -1 && BusIDAllocation[seat] == BusIDAllocation[AllocationIndex] && SeatNumber[seat] == SeatNumber[AllocationIndex])
                {
                    cout << "Seat is already occupied by another student." << endl;
                    AllocationID[AllocationIndex] = -1;
                    break;
                }
            }
            if (AllocationID[AllocationIndex] == -1)
            {
                break;
            }

            cout << "Enter Fee Status (0 for unpaid and 1 for paid): ";
            cin >> FeeStatus[AllocationIndex];

            if (FeeStatus[AllocationIndex] != 0 && FeeStatus[AllocationIndex] != 1)
            {
                cout << "Invalid status! We will assume unpaid." << endl;
                FeeStatus[AllocationIndex] = 0;
            }

            BusSelectedSeats[BusIndex]++;
            cout << endl;

            cout << "==================================================" << endl;
            cout << "          Seat  Alocated Succesfully!             " << endl;
            cout << "==================================================" << endl;

            cout << "Alocation ID: " << AllocationID[AllocationIndex] << endl;

            cout << "Student ID: " << StudentID[AllocationIndex] << endl;

            cout << "Route: " << RouteIDAllocation[AllocationIndex] << endl;

            cout << "Bus: " << BusIDAllocation[AllocationIndex] << endl;

            cout << "Seat: " << SeatNumber[AllocationIndex] << endl;

            if (FeeStatus[AllocationIndex] == 1)
            {
                cout << "Fee Status: Paid " << endl;
            }
            else
            {
                cout << "Fee Status: UnPaid " << endl;
            }

            cout << endl;
        }
        //Z
        break;
        case 6:
        {
            cout << "Update Student Allocation Record selected." << endl;
            cout << endl;

            int FoundIndex = -1; // Temporary Variable
            // Prepares a variable to store where (which array index 0–199) the allocation record exists; -1 means “not found yet”.

            int SearchAllocationID;
            // Store Allocation ID that user wants to Update.

            cout << "Enter Allocation ID to update: ";
            cin >> SearchAllocationID;
            // Asking user to enter Allocation ID to update.

            for (int searchAllocationIDCounter = 0; searchAllocationIDCounter < 200; searchAllocationIDCounter++)
            {
                // Checking if it matched the Allocation ID he wants to change
                if (AllocationID[searchAllocationIDCounter] == SearchAllocationID)
                {
                    FoundIndex = searchAllocationIDCounter;
                    break;
                }
            }

            if (FoundIndex == -1)
                // If no match found stop case 6
            {
                cout << "Error: Allocation Record not found! :(" << endl;
                break;
            }

            int OldBusIndex = -1;
            // Which bus was the student previously in.

            for (int oldBusIndexCounter = 0; oldBusIndexCounter < 6; oldBusIndexCounter++)
            {
                //  is the bus ID stored in the student’s allocation record.
                // This loop finds which bus slot oldBusIndexCounter has that bus ID.
                if (BusID[oldBusIndexCounter] == BusIDAllocation[FoundIndex])
                {
                    OldBusIndex = oldBusIndexCounter;
                    break;
                }
            }

            cout << "Record Found! Enter new details below." << endl;
            cout << "--------------------------------------" << endl;

            // Temporary Variables for Validation
            // We are using temporary variables because so we dont corrupt the database if 
            // the validation fails.

            int TempRouteID;
            int TempBusID;
            int TempSeatNumber;
            int TempFeeStatus;

            // New Route
            cout << "Enter New Route ID -- Eg.(101): ";
            cin >> TempRouteID;

            bool RouteFound = false;

            for (int temporaryRouteIDFoundCounter = 0; temporaryRouteIDFoundCounter < 6; temporaryRouteIDFoundCounter++)
            {
                // Check if there 
                if (RouteID[temporaryRouteIDFoundCounter] == TempRouteID)
                {
                    RouteFound = true;
                    break;
                }
            }

            if (!RouteFound)
            {
                cout << "Error: Invalid Route ID. Update has been Cancelled." << endl;
            }

            // New Bus
            cout << "Enter New Bus ID: ";
            cin >> TempBusID;

            int NewTempBusIndex = -1;
            for (int tempBusIDCounter = 0; tempBusIDCounter < 6; tempBusIDCounter++)
            {
                // Check if Buses exist and it matches the new route.
                if (BusID[tempBusIDCounter] == TempBusID)
                {
                    if (BusRouteID[tempBusIDCounter] == TempRouteID)
                    {
                        NewTempBusIndex = tempBusIDCounter;
                        break;
                    }
                    else
                    {
                        cout << "Error: Bus " << TempBusID << " is not assigned to Route " << TempRouteID << "." << endl;
                        break;
                    }
                }
            }

            if (NewTempBusIndex == -1)
            {
                cout << "Invalid Bus ID and Invalid Route. Update has been Cancelled." << endl;
                break;
            }

            // Check Capacity (Only if changing to a Different Bus).
            // If on the same bus, no need to check the capacity as we are already occupying a seat.

            if (NewTempBusIndex != OldBusIndex && BusSelectedSeats[NewTempBusIndex] >= BusCapacity[NewTempBusIndex])
            {
                cout << "Error! New Bus is Full." << endl;
                break;
            }

            // New Seat Number.

            cout << "Enter New Seat Number: ";
            cin >> TempSeatNumber;

            if (TempSeatNumber < 1 || TempSeatNumber > BusCapacity[NewTempBusIndex])
            {
                cout << "Error: Invalid Seat Number. Update has been Cancelled." << endl;
                break;
            }

            // Check if Seat has been taken by someone else.
            
                bool SeatTaken = false;
                for (int seatTakenCounter = 0; seatTakenCounter < 200; seatTakenCounter++)
                {
                    if (seatTakenCounter != FoundIndex && AllocationID[seatTakenCounter] != -1 && BusIDAllocation[seatTakenCounter] == TempBusID && SeatNumber[seatTakenCounter] == TempSeatNumber)
                    {
                        SeatTaken = true;
                        break;
                    }
                }

                if (SeatTaken)
                {
                    cout << "Error: Seat " << TempSeatNumber << " is already occupied on Bus " << TempBusID << "." << endl;
                    break;
                }

                // Fee Status

                cout << "Enter Fee Status ( 0 = Unpaid, 1 = Paid ): ";
                cin >> TempFeeStatus;

                if (TempFeeStatus != 0 && TempFeeStatus != 1)
                {
                    TempFeeStatus = 0;
                }

                // Now Saving Record.

                if (OldBusIndex != -1)
                {
                    // Remove from Old bus.
                    BusSelectedSeats[OldBusIndex]--;
                    
                }
            
                // Add to new Bus.
                BusSelectedSeats[OldBusIndex]++;

                // Updating database

                RouteIDAllocation[FoundIndex] = TempRouteID;
                BusIDAllocation[FoundIndex] = TempBusID;
                SeatNumber[FoundIndex] = TempFeeStatus;
                FeeStatus[FoundIndex] = TempFeeStatus;

                cout << endl;
                cout << "==========================================================" << endl;
                cout << "         Allocation Record Updated Successfully!          " << endl;
                cout << "==========================================================" << endl;
                cout << endl;


        }
        break;
        case 7:
        {
            cout << "Cancel Seat Allocation selected." << endl;
            cout << endl;

            int SearchAllocationID;
            cout << "Enter Allocation ID to cancel: ";
            cin >> SearchAllocationID;

            // Finding the Allocation Record Index 
            int FoundIndex = -1;
            for (int allocationIDCancelCounter = 0; allocationIDCancelCounter < 6; allocationIDCancelCounter++)
            {
                if (AllocationID[allocationIDCancelCounter] == SearchAllocationID)
                {
                    FoundIndex = allocationIDCancelCounter;
                    break;
                }
            }

            if (FoundIndex == -1)
            {
                cout << "Error: Allocation ID not found!" << endl;
            }

            // Now finding the bus index to decrease the booked seat count.

            int BusIndex = -1;
            for (int busIndexCounter = 0; busIndexCounter < 6; busIndexCounter++)
            {
                if (BusID[busIndexCounter] == BusIDAllocation[FoundIndex])
                {
                    BusIndex = busIndexCounter;
                    break;
                }
            }

            // Confirming the Cancellation.

            char ConfirmCancellation;
            cout << "Are you sure you want to cancel Allocation ID " << SearchAllocationID << " (y/n): ";
            cin >> ConfirmCancellation;

            if (ConfirmCancellation == 'y' || ConfirmCancellation == 'Y')
            {
                // Decrease Bus Seat Count
                if (BusIndex != -1)
                {
                    if (BusSelectedSeats[BusIndex] > 0)
                    {
                        BusSelectedSeats[BusIndex]--;
                    }
                }


                // Clear the Allocation Record to Default.
                AllocationID[FoundIndex] = -1;
                StudentID[FoundIndex] = -1;
                RouteIDAllocation[FoundIndex] = -1;
                BusIDAllocation[FoundIndex] = -1;
                SeatNumber[FoundIndex] = 0;
                FeeStatus[FoundIndex] = 0;
                Semester[FoundIndex] = 0;

                // Clear Strings (Name, Department, Contact)

                int NameStart = FoundIndex * 50;
                int DepartmentStart = FoundIndex * 50;
                int ContactNumberStart = FoundIndex * 20;

                // Empty string is \0.
                StudentName[NameStart] = '\0';
                StudentDepartment[DepartmentStart] = '\0';
                StudentContactNumber[ContactNumberStart] = '\0';

                cout << endl;
                cout << "Allocation Cancelled Successfully." << endl;
            }

            else
            {
                cout << "Cancellation Aborted." << endl;
            }
            cout << endl;
        }
        break;
        case 8:
        {
            cout << "Search / Listings selected." << endl;
            cout << endl;

            // Sub menu for search types

            cout << "1. Search by Allocation ID" << endl;
            cout << "2. Search by Student ID" << endl;
            cout << "3. List all Students on a specific Bus" << endl;
            cout << endl;
            int SearchType;
            cout << "Enter Search Type: ";
            cin >> SearchType;

            // First by Allocation ID.
            if (SearchType == 1)
            {
                int TargetID;
                cout << "Enter Allocation ID: ";
                cin >> TargetID;

                bool FoundAllocationID = false;
                
                for (int searchAllocationIDCounter = 0; searchAllocationIDCounter < 200; searchAllocationIDCounter++)
                {
                    if (AllocationID[searchAllocationIDCounter] != -1 && AllocationID[searchAllocationIDCounter] == TargetID)
                    {
                        FoundAllocationID = true;

                        // Calculating String Starting Positions
                        int StartingNamesIndex = searchAllocationIDCounter * 50;
                        int DepartmentNamesIndex = searchAllocationIDCounter * 50;

                        cout << "---- Record Found ----" << endl;
                        
                        cout << "Allocation ID: " << AllocationID[searchAllocationIDCounter] << endl;
                        cout << "Student ID: " << StudentID[searchAllocationIDCounter] << endl;
                        cout << "Name: " << &StudentName[StartingNamesIndex] << endl;
                        cout << "Department: " << &StudentDepartment[DepartmentNamesIndex] << endl;
                        cout << "Bus ID: " << BusIDAllocation[searchAllocationIDCounter] << endl;
                        cout << "Seat Number: " << SeatNumber[searchAllocationIDCounter] << endl;
                        cout << "Fee Status: " << (FeeStatus[searchAllocationIDCounter] ? "Paid" : "Unpaid") << endl;

                        break;
                        // IDS are Unique, so we stopped once they are found.
                    }
                }

                if (!FoundAllocationID)
                {
                    cout << "Record not Found." << endl;
                }
            }
            else if (SearchType == 2)
                // Search by Student ID.
            {
                int TargetID;
                cout << "Enter Student ID: ";
                cin >> TargetID;

                // Now Just checking Student ID
                bool FoundStudentID = false;
                for (int searchStudentIDCounter = 0; searchStudentIDCounter < 200; searchStudentIDCounter++)
                {
                    if (AllocationID[searchStudentIDCounter] != -1 && StudentID[searchStudentIDCounter] == TargetID)
                    {
                        FoundStudentID = true;
                        int NameIndex = searchStudentIDCounter * 50;
                        cout << "Found Allocation ID: " << AllocationID[searchStudentIDCounter] << " for Student: " << &StudentName[NameIndex] << endl;
                    }
                }
                if (!FoundStudentID)
                {
                    cout << "Student ID not found in records." << endl;
                }
            }
            else if (SearchType == 3) // List Students on a Bus.
            {
                int TargetBus;
                cout << "Enter Bus ID: ";
                cin >> TargetBus;

                cout << "Students on Bus " << TargetBus << ":" << endl;
                cout << "Seat\tStudent ID\tName" << endl;
                cout << "-----------------------------------" << endl;

                bool FoundAny = false;
                for (int foundAnyCounter = 0; foundAnyCounter < 200; foundAnyCounter++)
                {
                    // Check if the Record is valid and matches the Bus ID.
                    if (AllocationID[foundAnyCounter] != -1 && BusIDAllocation[foundAnyCounter] == TargetBus)
                    {
                        FoundAny = true;
                        int NameIndex = foundAnyCounter * 50;
                        cout << SeatNumber[foundAnyCounter] << "\t" << StudentID[foundAnyCounter] << "\t\t" << &StudentName[NameIndex] << endl;
                    }
                }
                if (!FoundAny)
                {
                    cout << "No Students have been found in this bus." << endl;
                }
                
            }
            else
            {
                cout << "Invalid Search Type." << endl;
            }
        }
        break;
        case 9:
        {
            cout << "Display Bus Seat Occupancy View selected." << endl;
            cout << endl;
            int TargetBus;
            cout << "Enter the Bus ID to view: ";
            cin >> TargetBus;

            //Now we will 1st fine the capacity of bus
            int Capacity = -1;
            for (int capacityCounter = 0; capacityCounter < 6; ++capacityCounter)
            {
                if (BusID[capacityCounter] == TargetBus)
                {
                    Capacity = BusCapacity[capacityCounter];//that will make sure that the bus we r searching exists or not
                    break;
                }
            }
            if (Capacity == -1)//means that no bus is assigned
            {
                cout << "Bus not found!" << endl;
                break;
            }
            cout << endl;
            cout << "--Seat Map for Bus " << TargetBus << " --" << endl;
            cout << " [XX] = occupied, [No] = Available" << endl;
            cout << endl;

            // Now we will check all the seats
            for (int seatCounter = 1; seatCounter <= Capacity; seatCounter++)
            {
                bool SeatOccupied = false;
                for (int allocationCounter = 0; allocationCounter < 200; allocationCounter++)
                {
                    if (AllocationID[allocationCounter] != -1 && BusIDAllocation[allocationCounter] == TargetBus && SeatNumber[allocationCounter] == seatCounter)
                    {
                        SeatOccupied = true;
                        break;
                    }
                }
                if (SeatOccupied)
                {
                    cout << "[XX] ";//that means its occupied
                }
                else
                {
                    if (seatCounter < 10)
                    {
                        cout << "[0" << seatCounter << "] ";//Will print 03 insted of 3
                    }
                    else {
                        cout << "[" << seatCounter << "] ";
                    }
                }

                if (seatCounter % 4 == 0) // 4 seats per row with space that means 2 seats then walking path then again 2 seats
                {
                    cout << endl; // new row after every 4 seats
                }
                else if (seatCounter % 2 == 0) 
                {  // space after 2 seats
                    cout << "   ";
                }
            }
            cout << endl;
           
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



