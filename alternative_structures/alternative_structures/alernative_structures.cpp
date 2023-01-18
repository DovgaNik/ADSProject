#include <iostream>
#include <cstring>

using namespace std;

void intro() {

	cout << "Project: Alternative strucutues." << endl << "Description: This algorithm will act as a calculator receiving operator and values from comman line interface arguments." << endl << "Made by Nikita DOVHAN dovhan.o.nikita22@stud.rau.ro dovgan.nik.2005@gmail.com" << endl;

}

void finish() {

	cout << "Press enter to finish execution...";
	cin.get();
	exit(0);

}

int main(int argc, char** argv) {

	intro();

	if (argc != 4)
		cout << "Input is invalid, please try again." << endl;
	else
		if (strcmp(argv[2], "+") == 0)
			cout << atof(argv[1]) + atof(argv[3]) << endl;
		else
			if (strcmp(argv[2], "-") == 0)
				cout << atof(argv[1]) - atof(argv[3]) << endl;
			else
				if (strcmp(argv[2], "*") == 0)
					cout << atof(argv[1]) * atof(argv[3]) << endl;
				else
					if (strcmp(argv[2], "/") == 0)
						cout << atof(argv[1]) / atof(argv[3]) << endl;
					else
						if (strcmp(argv[2], "^") == 0) {

							double num = atof(argv[1]);

							for (double i = 1; i < atof(argv[3]); i++)
								num = num * atof(argv[1]);

							cout << num << endl;

						}
	
	finish();

}