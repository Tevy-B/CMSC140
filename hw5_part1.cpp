# include <iostream>
using namespace std;
int main()
{

	int i, j;

		cout << "(i)" << endl;
		for (j = 1; j <= 10; j++)
		{
			cout << "*";
		}
		cout << "\n\n";

		cout << "(ii)" << endl;
		
		for (j = 1; j <= 20; j++)
		{
			cout << "*";
		}
		cout << "\n\n";
		cout << "(iii)" << endl;
		for (i = 1; i <= 10; i++)
		{
			for (j = 1; j <= i; j++)
			{
				cout << "*";
			}
			cout << "\n";
		}
		cout << "\n";
		cout << "(iv)" << endl;
		for (i = 1; i <= 20; i++)
		{
			for (j = 1; j <= i; j++)
			{
				cout << "*";
			}
			cout << "\n";
		}
		cout << "\n";
		cout << "(v)" << endl;
		for (i = 10; i >= 1; i--)
		{
			//print * equal to row number
			for (j = 1; j <= i; j++)
			{
				cout << "*";
			}
			cout << "\n";
		}
		cout << "\n";
		
		cout << "(vi)" << endl;
		for (i = 20; i >= 1; i--)
		{
			//print * equal to row number
			for (j = 1; j <= i; j++)
			{
				cout << "*";
			}
			cout << "\n";
		}
		cout << "\n";

	system("pause");
	return 0;
}