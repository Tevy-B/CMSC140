/*
 * Class: CMSC140 CRN
 * Instructor: Koorosh
 * Project 5
 * Description: Write a program that simulates a magic square using 3 one dimensional parallel arrays of integer type. 
 * Due Date: 12/09/2019
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: ____Sethatevy Bong______


 * Pseudocode or Algorithm for the program:
  1.Prompt and ask user to input numbers in each row and column
  2.create Boolean value and check if it is unique using for loop
  3.Test the magic array and display the result
  4.Determine if the array is a Lo Shu Magic Square.
  5.If so, display a message indicating that the array is a magic square.
  6. If not, display a message indicating that the array is not a magic square.
  7.Prompt user by y/n question whether to continue the program or not
  8.If the input is "y", the program will ask user to input the numbers
  9.If the input is "n", the program will proceed to Farwell message
  10.Display Programmer’s name and project's information as the farewell message

 */
 #include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
// Global constants
const int ROWS = 3;
const int COLS = 3;
const int MIN = 1; // The value of the smallest number
const int MAX = 9; // The value of the largest number
// Function prototypes
void showResult(int[][COLS]);
void showArray(int[][COLS]);
bool isMagicSquare(int[][COLS]);
bool checkRange(int[][COLS]);
bool checkUnique(int[][COLS]);
bool checkRowSum(int[][COLS]);
bool checkColSum(int[][COLS]);
bool checkDiagSum(int[][COLS]);
int main()
{

	int magicArray[ROWS][COLS];
	char ch;

	while (true)
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				cout << "Enter the number for row " << i << " and column " << j << " :";
				cin >> magicArray[i][j];
			}
		}
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				cout << magicArray[i][j] << " ";
			}
			cout << endl;
		}

		// Test the magic array and display the result.
		showResult(magicArray);
		cout << "\n\nDo you want to try again :";
		cin >> ch;

		if (ch == 'y' || ch == 'Y')
		{

			continue;

		}
		else
		{
			break;
		}
	}
	cout << "Name : Sethatevy Bong" << endl;
	cout << "Project #: 5" << endl;
	cout << "Due Date: 12/09/2019 " << endl << endl;

	return 0;
}
// ********************************************************
// The showResult function accepts a two-dimensional int *
// array as an argument, tests to determine if it is a *
// Lo Shu Magic Square and displays the result. *
// ********************************************************
void showResult(int values[][COLS])
{
	// Determine if the array is a Lo Shu Magic Square.
	if (isMagicSquare(values)) {
		cout << "This is a Lo Shu magic square.\n\n";
	}
	else {

		cout << "This is not a Lo Shu magic square.\n\n";
	}
}
// ********************************************************
// The showArray function accepts a two-dimensional int *
// array as an argument and displays its contents. *
// ********************************************************
void showArray(int values[][COLS])
{
	// Step through all the values in the array.
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			// Display the values in this row.
			cout << values[row][col] << " ";
		}
		// End the line, so we can display the next row.
		cout << endl;
	}
}
// ********************************************************
// The isMagicSquare function accepts a two-dimensional *
// int array as an argument, and returns true if the *
// array meets all the requirements of a magic square. *
// Otherwise, it returns false. *
// ********************************************************
bool isMagicSquare(int values[][COLS])
{
	// Initialize the status to false.
	bool status = false;
	// Call the functions to check the array.
	bool isInRange = checkRange(values);
	bool isUnique = checkUnique(values);
	bool isEqualRows = checkRowSum(values);
	bool isEqualCols = checkColSum(values);
	bool isEqualDiag = checkDiagSum(values);
	// Determine if the array meets all the requirments.
	if (isInRange && isUnique && isEqualRows && isEqualCols && isEqualDiag) {
		status = true;
	}
	return status;
}
// ********************************************************
// The checkRange function accepts a two-dimensional int *
// array as an argument, and returns true if the values *
// are within the specified range. Otherwise, it returns *
// false. *
// ********************************************************
bool checkRange(int values[][COLS])
{
	// Initialize status to true.
	bool status = true;
	// Step through all the values in the array.
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			// Determine if the value is out of range.
			if (values[row][col] < MIN || values[row][col] > MAX) {
				status = false;
			}
		}
	}
	return status;
}
// ********************************************************
// The checkUnique function accepts a two-dimensional int *
// array as an argument, and returns true if the values *
// in the array are unique. Otherwise, it returns false. *
// ********************************************************
bool checkUnique(int values[][COLS])
{
	int count;
	int num = 1;
	bool status = true;
	for (int i = 0; i < ROWS; i++)
	{
		count = 0;
		for (int j = 0; j < COLS; j++)
		{
			if (values[i][j] == num)
				count++;
		}
		if (count > 1)
			status = false;
		num++;
	}
	// Return the status.
	return status;
}
// ********************************************************
// The checkRowSum function accepts a two-dimensional *
// int array as an argument, and returns true if the sum *
// of the values in each of the array's rows are equal. *
// Otherwise, it returns false. *
// ********************************************************
bool checkRowSum(int values[][COLS])
{
	// Initialize status to true.
	bool status = true;
	// Calculate the sum of the values in the first row.
	int sumRowA = values[0][0] + values[0][1] + values[0][2];
	// Calculate the sum of the values in the second row.
	int sumRowB = values[1][0] + values[1][1] + values[1][2];
	// Calculate the sum of the values in the third row.
	int sumRowC = values[2][0] + values[2][1] + values[2][2];
	// Determine if the sum of the columns is not equal.
	if ((sumRowA != sumRowB) || (sumRowA != sumRowC) || (sumRowB != sumRowC)) {
		// If so, set status to false.
		status = false;
	}
	// Return the status.
	return status;
}
// ********************************************************
// The checkColSum function accepts a two-dimensional *
// int array as an argument, and returns true if the sum *
// of the values in each of the array's columns are *
// equal. Otherwise, it returns false. *
// ********************************************************
bool checkColSum(int values[][COLS])
{
	// Initialize status to true.
	bool status = true;
	// Calculate the sum of the values in the first column.
	int sumColA = values[0][0] + values[1][0] + values[2][0];
	// Calculate the sum of the values in the second column.
	int sumColB = values[0][1] + values[1][1] + values[2][1];
	// Calculate the sum of the values in the third column.
	int sumColC = values[0][2] + values[1][2] + values[2][2];
	// Determine if the sum of the columns is not equal.
	if ((sumColA != sumColB) || (sumColA != sumColC) || (sumColB != sumColC)) {
		status = false;
	}
	return status;
}
// ********************************************************
// The checkDiagSum function accepts a two-dimensional *
// int array as an argument, and returns true if the sum *
// of the values in each of the array's diagonals are *
// equal. Otherwise, it returns false. *
// ********************************************************
bool checkDiagSum(int values[][COLS])
{
	// Initialize status to true;
	bool status = true;
	// Calculate the sum of the values in the first diagonal.
	int sumDiagA = values[0][0] + values[1][1] + values[2][2];
	// Calculate the sum of the values in the second diagonal.
	int sumDiagB = values[2][0] + values[1][1] + values[0][2];
	// Determine if the sum of the diagonals is not equal.
	if (sumDiagA != sumDiagB) {
		status = false;
	}
	return status;
}
