#include <iostream>

int main() {

	unsigned int amountOfNumbers,
		minRandom,
		maxRandom,
		maxOccurance = 1,
		minOccurance = 1,
		min,
		max;

	std::cout << "Project: Repetitive strucutues." << std::endl << "Description: This algorithm will randomly generate a user-defined amount of numbers and defines the smallest and biggest number. ONLY POSITIVE NUMBERS ALLOWED, NEGATIVE NUMBERS LEAD TO UNEXPECTED BEHAVIOR" << std::endl << "Made by Nikita DOVHAN dovhan.o.nikita22@stud.rau.ro" << std::endl << std::endl << "Please enter the amount of number you want to generate and go through: ";
	std::cin >> amountOfNumbers;
	std::cout << "Please enter the minimal number and maximal number for random number generator: ";
	std::cin >> minRandom >> maxRandom;

	srand((unsigned)time(NULL));

	min = (rand() % maxRandom) + minRandom;
	max = min;
	//std::cout << min << std::endl;

	for (int i = 1; i < amountOfNumbers; i++) {

		int number = (rand() % maxRandom) + minRandom;
		//std::cout << number << std::endl;

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

	std::cout << "The minimal number- " << min << " occured " << minOccurance << " times." << std::endl << "The maximal number- " << max << " occured " << maxOccurance << " times." << std::endl;

	std::cin.ignore();
	std::cin.get();
	return 0;

}