#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	//strings for ofstream
	string name;
	string phoneNum; //string for phone number
	string address1; //string for street address
	string address2; //string for city, state, and zip code

	ofstream outfile;
	outfile.open("list.txt");

	//prompt and asks users to input data
	cout << "Enter user's name: ";
	getline(cin, name);
	cout << "Enter user's phone numbers: ";
	getline(cin, phoneNum);
	cout << "Enter the user's street address: ";
	getline(cin, address1);
	cout << "Enter the user's city, state, and zip code: ";
	getline(cin, address2);
	cout << endl;

	//puts info into file
	outfile << name << endl;
	outfile << phoneNum << endl;
	outfile << address1 << endl;
	outfile << address2 << endl;
	outfile.close();

	ifstream infile;
	string name2; //name used for ifstream
	string phoneNumber;
	string street;
	string stateZip; //string used for zipcode in ifstream

	infile.open("list.txt");
	getline(infile, name2);
	cout << "Name: " << name2 << endl;
	getline(infile, phoneNumber);
	cout << "Phone Number: " << phoneNumber << endl;
	getline(infile, street);
	cout << "Address: " << street << endl;
	getline(infile, stateZip);
	cout << "\t" << stateZip << endl;

	infile.close();

	system("pause");
	return 0;
}