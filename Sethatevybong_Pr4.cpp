/*
* Class: CMSC140 CRN
* Instructor: Koorosh
* Project 4
* Description: Write a program that calculates the average number of days a company's employees
				are absent during the year and outputs a report on a file named "employeeAbsences.txt".
* Due Date: 11/18/19

* I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: ____Sethatevy Bong______


* Pseudocode:

  1. PRINT title "Calculate the average number of days a company's employees are absent."

  2. CALL NumOfEmployees() function

  3. PROMPT "Please enter the number of employee in the company: "

  4. WHILE number of employees < 1

  5. PRINT error "Please re-enter the number of employees: "

  6. PROMPT "Please re-enter the number of employees: "

  7. END WHILE

  8. RETURN number of employees

  9. CALL TotDaysAbsent() function. PASS number of employees.

  10. FOR i < number of employees

  11. PROMPT "Please enter an employee ID: "

  12. PROMPT "Please enter the number of days this employee was absent: "

  13. WHILE days absent < 0

  14. PRINT error "The number of days must not be negative"

  15. PROMPT "Please re-enter the number of days this employee was absent: "

  16. END WHILE

  17. CALCULATE total absent

  18. WRITE employee ID and days absent to file.

  19. RETURN total absent.

  20. CALL AverageAbsent() function, PASS number of employee and total absent

  21. CALCULATE average numbers of absent

  22. COVERT total absent to double by static_cast <double>

  23. RETURN average absent

  24. CALL main function

  25. PRINT introduction "Calculate the average number of days a company's employees are absent."

  26. CALL outfile ("employeeAbsences.txt")

  27. WRITE "EMPLOYEE ABSENCE REPORT" to file

  28. WRITE "employee id" and  "days absent" in file

  29. PASS the number of employee and CALL NumOfEmployees() function

  30. CALCULATE total days absent

  31. PASS average days absent and CALL AverageAbsent() function

  32. WRITE number of employee and total days absent to file

  33. WRITE average days Absent to file

  34. PROMPT programmer's name
*/

# include <fstream> 
# include <iostream>  
# include <iomanip> 
using namespace std;

//defining global variable  
ofstream outfile;

int NumOfEmployees();
int TotDaysAbsent(int);
double AverageAbsent(int, int);

// first function NumOfEmployees 

int NumOfEmployees()
{
	int num_employee;
	cout << "Please enter the number of employee in the company: ";
	cin >> num_employee;

	while (num_employee < 1)
	{
		cout << "Please re-enter the number of employees: ";
		cin >> num_employee;
	}
	return num_employee;
}


//second function Total days that each employee absent 
int TotDaysAbsent(int num_employee)

{
	int id, absent, totalabsent = 0;
	for (int i = 1; i <= num_employee; i++)
	{
		cout << "Please enter an employee ID: ";
		cin >> id;
		cout << "Please enter the number of days this employee was absent: ";
		cin >> absent;

		//Input validation
		while (absent < 0)
		{
			cout << "The number of days must not be negative" << endl << "Please re-enter the number of days this employee was absent: ";
			cin >> absent;
		}
		totalabsent += absent;
		outfile << setw(8) << id << setw(10) << absent << endl;
	}
	return totalabsent;
}



//third function calculate the average absent days 
double AverageAbsent(int num_employee, int totalabsent)

{
	double avgAbsent;
	avgAbsent = static_cast <double>(totalabsent) / num_employee;
	return avgAbsent;
}

int main()



{
	int num_employee, totalabsent;
	double avgAbsent;

	cout << "Calculate the average number of days a company's employees are absent." << endl << endl;

	outfile.open("employeeAbsences.txt");
	outfile << "EMPLOYEE ABSENCE REPORT" << endl;
	outfile << setw(11) << "employee id" << setw(14) << "days absent" << endl;
	num_employee = NumOfEmployees();
	totalabsent = TotDaysAbsent(num_employee);
	avgAbsent = AverageAbsent(num_employee, totalabsent);
	outfile << setw(4) << endl << "The " << num_employee << " employees were absent a total of " << totalabsent << " days." << endl;
	outfile << setw(4) << "The average number of days absent is " << fixed << showpoint << setprecision(1) << avgAbsent << " days." << endl << endl;
	outfile << setw(4) << "Programmer: Sethatevy Bong" << endl;

	cout << "Programmer: Sethatevy Bong" << endl;
	system("pause");
	return 0;

}