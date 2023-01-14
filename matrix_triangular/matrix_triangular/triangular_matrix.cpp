#include <iostream>

using namespace std;

int main() {

	// Input the size of matrix
	cout << "Please specify the size of the matrix: ";
	int size;
	cin >> size;

	// Dynamically creating a 2d array in the heap
	int** arr = new int* [size]; // Create a pointer to an array of pointers
	for (int i = 0; i < size; i++) // Loop that will run for the whole array of pointers
		arr[i] = new int[size]; // Creating an array in each position in the array of pointers

	cout << "Please input the data:" << endl;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
	
			//cout << "Please, enter the data for the position (" << i + 1 << ";" << j + 1 << "): " << endl;
			cin >> arr[i][j];

		}

	for (int i = 0; i < size; i++) {
		cout << "|";

		for (int j = 0; j < size; j++)
			cout << " " << arr[i][j] << " ";

		cout << "|" << endl;
	}

	bool isLowerTriangular = true,
		isUpperTriangular = true;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			
			if (i > j && arr[i][j] != 0)
				isLowerTriangular = false;

			if (i < j && arr[i][j] != 0)
				isUpperTriangular = false;

		}
	}

	cout << "Is the triangle lower triangular: " << isLowerTriangular << endl;
	cout << "Is the triangle upper triangular: " << isUpperTriangular << endl;

	if (isLowerTriangular && isUpperTriangular)
		cout << "Diagonal" << endl;

	int row1, row2;
	cout << "Please enter the rows you want to swap: ";
	cin >> row1 >> row2;
	row1--;
	row2--;
	int* arrTemp = new int[size];
	arrTemp = arr[row1];
	arr[row1] = arr[row2];
	arr[row2] = arrTemp;

	for (int i = 0; i < size; i++) {
		cout << "|";

		for (int j = 0; j < size; j++)
			cout << " " << arr[i][j] << " ";

		cout << "|" << endl;
	}

	int min = arr[0][0],
		max = arr[0][0],
		minX = 0, minY = 0,
		maxX = 0, maxY = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{

			if (min > arr[i][j]) {
			
				min = arr[i][j];
				minX = i;
				minY = j;
			
			}
			if (max < arr[i][j])
			{
				max = arr[i][j];
				maxX = i;
				maxY = j;
			}

		}
	}

	cout << "min is " << min << endl << "max is " << max << endl;

	int temp = arr[minX][minY];
	arr[minX][minY] = arr[maxX][maxY];
	arr[maxX][maxY] = temp;

	for (int i = 0; i < size; i++) {
		cout << "|";

		for (int j = 0; j < size; j++)
			cout << " " << arr[i][j] << " ";

		cout << "|" << endl;
	}

	cin.ignore();
	cin.get();
	return 0;

}