#include <iostream>
#include <time.h> // Required to create a seed for random number generator
#include <string.h>

using namespace std;

int main(int argc, char** argv) {

	int amountOfEmployees,
		amountOfDays;
	bool verboseMode = true, displayTable = true;

	// Check if the program should run in verbose mode
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "--not-verbose") == 0)
			verboseMode = false;
		if (strcmp(argv[i], "--no-table") == 0)
			displayTable = false;
		if (strcmp(argv[i], "--help") == 0) {
			cout << "--not-verbose for not showing output of random number generator" << endl << "--no-table to not display the table of enployees and days" << endl;
			return 0;
		}
	}
	// Ask for employee and day amount input
	cout << "Two dim arr" << endl << "Please enter the amount of employees and days: ";
	cin >> amountOfEmployees >> amountOfDays;

	// Dynamically creating a 2d array in the heap
	int** a = new int*[amountOfDays]; // Create a pointer to an array of pointers
	for (int i = 0; i < amountOfDays; i++) // Loop that will run for the whole array of pointers
		a[i] = new int[amountOfEmployees]; // Creating an array in each position in the array of pointers
	
	// Ask how user prefer to input the data
	char choice;
	cout << "Would youprefer to generate amount of hours randomly(R) or enter manually(M): ";
	cin >> choice;

	if (choice == 'M')
		// For manual input the user must input a number per each position in the 2d array
		for (int i = 0; i < amountOfEmployees; i++) {
			for(int j = 0; j < amountOfDays; j++) {
		
				cout << "Please enter the amount of hours for an employee number " << i + 1 << " for the day " << j + 1 << ": ";
				cin >> a[j][i];

			}
		}
	else
		if (choice == 'R') {
			//For random input, the program will do exactly the same as manual input does, except using a random function instead of cin
			srand((unsigned)time(NULL));

			for (int i = 0; i < amountOfEmployees; i++) {
				for (int j = 0; j < amountOfDays; j++) {

					a[j][i] = 4 + (rand() % 6);

					if(verboseMode)
						cout << "The amount of hours for an employee number " << i + 1 << " for the day " << j + 1 << " is " << a[j][i] << endl;

				}
			}
		}

	cout << endl << endl;

	for (int j = 0; j < amountOfDays; j++) {
		for (int i = 0; i < amountOfEmployees; i++) {

			cout << "|" << a[j][i] << "|";

		}

		cout << endl;

	}

	cout << "Do you want to calculate total amount for an employee (E) or a day (D) or an employee that worked the most (M)" << endl;
	cin >> choice;

	if (choice == 'E') {

		int empl;
		cout << "Which employee do you want to look for?: ";
		cin >> empl; 
		int sum = 0; 

		for (int j = 0; j < amountOfDays; j++) {
			sum = sum + a[j][empl - 1];
		}
		cout << sum << endl;

	} else
		if (choice == 'D') {

			int day;
			cout << "Which day do you want to look for?: ";
			cin >> day;
			int sum = 0;

			for (int j = 0; j < amountOfEmployees; j++) {
				sum = sum + a[day - 1][j];
			}
			cout << sum << endl;

		}else
			if (choice == 'M') {
				int * arr;
				arr = new int[amountOfEmployees];

				for (int i = 0; i < amountOfEmployees; i++) {
					int sum = 0;

					for (int j = 0; j < amountOfDays; j++) {
						
						sum = sum + a[j][i];

					}
					arr[i] = sum;
				}
				
				int indexMax = 0, max = arr[0];
				for (int i = 1; i < amountOfEmployees; i++) {

					if (arr[i] > max) {

						indexMax = i;
						max = arr[i];

					}
				}

				cout << "empl " << indexMax + 1 << " worked the most with " << max << " hours" << endl;

			}

	//Finishing execution
	cout << "Press enter to finish the exection of current algorithm...";
	cin.ignore();
	cin.get();
	return 0;

}