#include <iostream>
#include <time.h> // Required to create a seed for random number generator

using namespace std;

void intro() {

	cout << "Project: Repetitive strucutues." << endl << "Description: This algorithm will randomly generate a user-defined amount of numbers and defines the smallest and biggest number." << endl << "Made by Nikita DOVHAN dovhan.o.nikita22@stud.rau.ro" << endl << endl << "Please enter the amount of number you want to generate and go through (only positive numbers): ";

}

void finish() {

	cout << "Press enter to finish execution...";
	cin.get();
	exit(0);

}

int main() {

	unsigned int amountOfNumbers,
		minRandom,
		maxRandom,
		maxOccurance = 1,
		minOccurance = 1,
		min,
		max;
	
	do {

		cin >> amountOfNumbers;
		cout << "Please enter the minimal number and maximal number for random number generator: ";
		cin >> minRandom >> maxRandom;

	} while (!amountOfNumbers > 0 && !minRandom > 0 && !amountOfNumbers > 0);
	
	srand((unsigned)time(NULL));

	min = (rand() % maxRandom) + minRandom;
	max = min;

	for (int i = 1; i < amountOfNumbers; i++) {

		int number = (rand() % maxRandom) + minRandom;

		if (max < number) {

			max = number;
			maxOccurance = 1;

		}
		else {

			if (min > number) {

				min = number;
				minOccurance = 1;

			}
			else
				if (max == number)
					maxOccurance++;
				else
					if (min == number)
						minOccurance++;
		}
	}

	cout << "The minimal number- " << min << " occured " << minOccurance << " times." << endl << "The maximal number- " << max << " occured " << maxOccurance << " times." << endl;

	finish();

}