#include <iostream>

int main() {

	// Variable declaration
	double 
		sizeOfArr, // A number of items in an array
		* arr; // A pointer to the array
	int
		minRandom, // The lower limit for random number generator
		maxRandom; // The higher limit for random number generator
	// Variable declaration

	std::cout << "Project: One-dimensional array." << std::endl << "Description: This algorithm will randomly generate a user-defined amount of numbers to an array, sorts them and show statistic for every number occured." << std::endl << "Made by Nikita DOVHAN dovhan.o.nikita22@stud.rau.ro" << std::endl << std::endl; // Intro
	
	do {

		std::cout << "Please enter the amount of number you want to generate and go through, please enter only positive non-null numbers: ";
		std::cin >> sizeOfArr >> minRandom >> maxRandom;

	} while (sizeOfArr <= 0 || minRandom <= 0 || maxRandom <= 0); // Repeat unless you enter a valid input

	arr = new double[sizeOfArr]; // Declare an array with a previously specified size using a pointer

	srand((unsigned)time(NULL)); // Give a seed to a random number generator

	for (int i = 0; i < sizeOfArr; i++) // Generate a random array
		arr[i] = (rand() % (maxRandom + 1)) + minRandom;

	// Ouput the unsorted array
	std::cout << "The unsorted array: ";
	for (int i = 0; i < sizeOfArr; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	// \/\/\/ Bubble sort algorithm
	for (int i = 0; i < sizeOfArr - 1; i++) // The main loop that goes through the array
		for (int a = i + 1; a < sizeOfArr; a++) // The inside loop that goes through the array starting from the point next to the point of main loop
			if (arr[a] < arr[i]) { // Check if one number on the position of main array is bigger or smaller than the number on the position of the inside loop

				//Perform a swap
				double temp = arr[a];
				arr[a] = arr[i];
				arr[i] = temp;

			}

	// Ouput the already sorted array
	std::cout << "The sorted array: ";
	for (int i = 0; i < sizeOfArr; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	// Calculate the amount of occurances for each number
	for (int i = 0; i < sizeOfArr; i++) {

		int counter = 0, number = arr[i];

		for (counter = 0; number == arr[i + counter]; counter++); // Calculate the number of occurances for number at arr[i]
		i = i + counter - 1; // Set the main array iteration counter to the next number

		std::cout << "The number " << number << " occured " << counter << " times." << std::endl;

	}

	delete arr;
	arr = NULL;

	std::cin.ignore();
	std::cin.get();
	return 0;

}