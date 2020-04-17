/*
 * Class: CMSC140 CRN
 * Instructor: Khoorosh
 * Project3
 * Description: write a program that calculates the occupancy rate and the total hotel income (based on the room type and its rate),
 the total number of occupied rooms, the total number of the uncopied rooms, floor number with the minimum number of rooms,
 and a message to improve the occupancy rate for the occupancy rate of less than 60%.
 * Due Date: 11/04/2019
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: _____Sethatevy Bong_____


 * Pseudocode or Algorithm for the program:
	
  1. Print welcome menu of the hotel
  2. initialize the values for four different rooms
  2. prompt and read the location where this hotel chain is located and the number of floors in the hotel 
  (the total number of rooms on each floor may not exceed 30, continuously ask for the correct number of rooms within the range of 1 and 30)
  3. Prompt and read the number of occupied rooms for each room type on this floor 
  (the total number of rooms on each floor may not exceed 30, continuously ask for the correct number of rooms within the range of 1 and 30)
  4. check that the total number of occupied rooms on each floor does not exceed the total of rooms on that floor
  5. print the rates of room types and calculate hotel income based on the room type and its rate
  6. calculate the total number of rooms, total number of occupied and unoccupied rooms, and rate of occupancy.
  7. print the results and find the Floor number with the minimum number of rooms
  (if the occupancy rate is less than 60%, then print a message)
  8.Print programmer's and project's information
 
*/

#include <iostream>

#include <string>

#include <iomanip>

using namespace std;

int main()

{
	string location;
	int i, floors, rooms[30], singleRoom[10], doubleRoom[10], king[10], suite[10];
	//initailze the values for four different rooms
	int singleRRate = 60, doubleRRate = 75, kingRRate = 100, stroom = 150;
	int unoccupied, min;
	double totalRooms = 0, occupied_rooms = 0, income = 0.0, occupancy_rate;
	int sum = 0;

	cout << fixed << setprecision(2);

	cout << "-------------------------------------------------------------\n";

	cout << right << setw(40) << "BlueMount Hotel\n";

	cout << "-------------------------------------------------------------\n";

	
	cout << "Enter the Location of this hotel chain: ";
	cin >> location;

	cout << "Enter total number of floors of the hotel: ";
	cin >> floors;

	// The number of floors may not exceed 5, continuously ask for the correct floor number if it is not within the range of 1 and 5.
	while (floors <= 0 || floors > 5)

	{
		cout << "number of floors should be between 1 and 5 !! please try again.\n";
		cout << "\nEnter total number of floors of the hotel: ";
		cin >> floors;
	}

	// iterate a loop to read the total number of rooms for each floor.
	for (i = 1; i <= floors; i++)
	{
		cout << "\n\nEnter total number of rooms in the " << i << "th floor: ";
		cin >> rooms[i];
		
		//The total number of rooms on each floor may not exceed 30, continuously ask for the correct number of rooms within the range of 1 and 30.
		while (rooms[i] <= 0 || rooms[i] > 30)
		{
			cout << "number of rooms should be between 1 and 30 !! please try again.\n\n";
			cout << "Enter total number of rooms in the " << i << "th floor : ";
			cin >> rooms[i];
		}

		//prompt and read the number of occupied rooms for each room type on this floor.
		cout << "How many SINGLE rooms are occupied in the " << i << "th floor : ";
		cin >> singleRoom[i];

		cout << "How many DOUBLE rooms are occupied in the " << i << "th floor : ";
		cin >> doubleRoom[i];

		cout << "How many KING rooms are occupied in the " << i << "th floor : ";
		cin >> king[i];

		cout << "How many SUITE rooms are occupied in the " << i << "th floor : ";
		cin >> suite[i];

		sum = singleRoom[i] + doubleRoom[i] + king[i] + suite[i];

		//check that the total number of occupied rooms on each floor does not exceed the total of rooms on that floor.
		while (sum > rooms[i])
		{
			cout << "Total number of occupied rooms exceeds the total number of " << "rooms on this floor. Please try again!!\n\n";
			sum = 0;
			cout << "Enter total number of rooms in the " << i << "th floor : ";
			cin >> rooms[i];

			while (rooms[i] <= 0 || rooms[i] > 30)
			{
				cout << "number of rooms should be between 1 and 30 !! please try again.\n\n";
				cout << "Enter total number of rooms in the " << i << "th floor : ";
				cin >> rooms[i];
			}

			cout << "How many SINGLE rooms are occupied in the " << i << "th floor : ";

			cin >> singleRoom[i];

			cout << "How many DOUBLE rooms are occupied in the " << i << "th floor : ";

			cin >> doubleRoom[i];

			cout << "How many KING rooms are occupied in the " << i << "th floor : ";

			cin >> king[i];

			cout << "How many SUITE rooms are occupied in the " << i << "th floor : ";

			cin >> suite[i];

			sum = singleRoom[i] + doubleRoom[i] + king[i] + suite[i];

		}

	}

	//print the rates of room types

	cout << "\n\n-------------------------------------------------------------------------------\n";
	cout << right << setw(40) << "BlueMont Hotel located in " << location << endl << endl;
	cout << right << setw(47) << "TODAY'S ROOM RATES<US$/night>" << endl << endl;
	cout << right << setw(20) << "Single Room" << setw(20) << "Double Room" << setw(20) << "King Room" << setw(20) << "Suite Room";

	cout << endl << endl;
	cout << right << setw(20) << singleRRate << setw(20) << doubleRRate << setw(20) << kingRRate << setw(20) << stroom;
	cout << "\n-------------------------------------------------------------------------------\n";

	for (i = 1; i <= floors; i++)
	{
		//calculate hotel income based on the room type and its rate.
		income = income + (singleRoom[i] * singleRRate) + (doubleRoom[i] * doubleRRate) + (king[i] * kingRRate) + (suite[i] * stroom);
		//The total number of rooms.
		totalRooms = totalRooms + rooms[i];
		//The total number of occupied rooms.
		occupied_rooms = occupied_rooms + singleRoom[i] + doubleRoom[i] + king[i] + suite[i];
	}

	//The total number of unoccupied rooms.
	unoccupied = totalRooms - occupied_rooms;

	//The rate of occupancy
	occupancy_rate = (occupied_rooms / totalRooms) * 100;

	// print the data
	cout << "\n" << right << setw(35) << "Hotel Income: " << right << setw(10) << "$" << income;
	cout << "\n" << right << setw(35) << "Total # of rooms: " << right << setw(10) << totalRooms;
	cout << "\n" << right << setw(35) << "Total # Occupied Rooms: " << right << setw(10) << occupied_rooms;
	cout << "\n" << right << setw(35) << "Total # Unoccupied Rooms: " << right << setw(10) << unoccupied;
	cout << "\n" << right << setw(35) << "Occupancy rate: " << right << setw(10) << occupancy_rate << "%";

	//find the Floor number with the minimum number of rooms.
	int m = 1;
	min = rooms[1];
	for (i = 2; i <= floors; i++)
	{
		if (rooms[i] < min)
		{
			min = i;
			m = i;
		}

	}

	cout << "\n\n" << m << "th Floor with " << rooms[m] << " rooms, has the least # of rooms.";

	//if the occupancy rate is less than 60%, then print a message.
	if (occupancy_rate < 60)
	{
		cout << "\nNeed to improve Hotel occupancy rate!!";
	}


	cout << "\n\nThank you for testing my program!!";
	cout << "\nPROGRAMEER : Sethatevy Bong";
	cout << "\nCMSC140 Common Project 3";
	cout << "\nDue Date: 11/04/2019 \n";

	system("pause");
	return 0;

}