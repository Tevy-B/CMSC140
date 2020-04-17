/*Class: CMSC140 CRN

		* Instructor : Koorosh Azhandeh
		* Project2:
		* Description : Write a program that shows the following menu options and lets the user to convert from Metric to Imperial system.
		* Due Date : 10 / 13 / 2019
		* I pledge that I have completed the programming assignment independently.
		I have not copied the code from a student or any source.
		I have not given my code to any student.
		Print your Name here : __SETHATEVY BONG________
		* Pseudocode or Algorithm for the program :
		   (be sure to indent items with control structure)
			   (need to match flow chart submitted in documentation)
			   1. prompt and ask user to input the country
			   2. display menu and ask user to choose the converter of temperature, distance, and weight or quit
			   3. user input the value
			   4. display dialogue with converted measurement of choice to Imperial system
			   5. display farewell and student information
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
	string country; //String for country name (spaces allowed)
	int choice; // user inputs for menu (1-4 only)
	double temp; //Temperature user inputs (Celsius)
	double distance; //Distance user inputs (Positive Kilometers)
	double weight; //Distance user inputs (Positive Kilograms)
	const double TEMP_1 = 1.8; //Constant needed for converting Celsius to Fahrenheit
	const double TEMP_2 = 32; //constant needed for converting Celsius to Fahrenheit
	const double DISTANCE_CONVERTOR = 0.6; //Constant used for converting Kilometers to Miles
	const double WEIGHT_CONVERTOR = 2.2; //Constant used for converting Kilograms to Pounds

	//user's country, and menu
	
	cout << "Enter a country name: ";
	getline(cin, country);
	cout << endl << endl;
	cout << "Converter Toolkit: " << endl;
	cout << "------------------------" << endl;
	cout << "1. Temperature Convertor " << endl;
	cout << "2. Distance Convertor " << endl;
	cout << "3. Weight Convertor " << endl;
	cout << "4. Quit " << endl;
	cout << endl;
	cout << "Enter your choice (1-4): ";
	cin >> choice;

	//switch statement
	switch (choice) {
	case 1:								//Option 1: finds temperature in Celsius
		cout << "Please enter a temperature in Celsius (Example: 24): ";
		cin >> temp;
		cout << "It is " << setprecision(0) << fixed << (temp * TEMP_1) + TEMP_2
			<< " degrees Fahrenheit." << endl; //calculations for temperature
		break;

	case 2:								//Option 2: finds distance from Kilometers to Miles
		cout << "Enter a distance in Kilometers (Example: 18.54): ";
		cin >> distance;
		if (distance >= 0)
			cout << "The distance is " << setprecision(2) << showpoint << fixed  //two digits after decimal point -- setprecision(2)
			<< (distance * DISTANCE_CONVERTOR) << " in Miles. " << endl; //calculations for distance
		else							//if the user enters a number not greater than 0 (negative number) then error is displayed.
			cout << "ERROR! Program cannot compute negative distance! " << endl;
		break;

	case 3:								//Option 3: finds weight from Kilogram to Pounds.
		cout << "Enter a weight in Kilograms (Example: 50): ";
		cin >> weight;
		if (weight >= 0)
			cout << "The weight is " << setprecision(1) << showpoint << fixed //one digit after decimal point -- setprecision(1)
			<< weight * WEIGHT_CONVERTOR <<" in Pounds."<< endl; //calculations for weight
		else							//if the user enters a number not greater than 0 (negative number) then error is displayed.
			cout << "ERROR! Program cannot compute negative weight! " << endl;
		break;

	case 4:								 //Option 4: Quits program.
		cout << "Quiting program..." << endl;
		break;

	default:							//Automatically sends error if number is not between 1-4 when selecting from the menu.
		cout << "ERROR! Restart program and enter numbers 1-4 only. " << endl;
	}

	cout << endl << country << " sounds fun!" << endl << endl;

	cout << "Thank you for testing my program!!" << endl;
	cout << "PROGRAMMER: Sethatevy Bong " << endl;
	cout << "CMSC140 Common Project 2" << endl;
	cout << "Due Date : 10 / 13 / 2019" << endl << endl;

	system("pause");
	return 0;
}