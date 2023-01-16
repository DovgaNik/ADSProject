#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv) {

	if (argc != 4) {

		cout << "Input is invalid, please try again." << endl;
		return 0;

	}
	else
	{
		if (strcmp(argv[2], "+") == 0)
		{
			cout << *argv[1] + *argv[3] << endl;
		}
		else
		{
			if (strcmp(argv[2], "-") == 0)
			{

			}
			else
			{
				if (strcmp(argv[2], "*") == 0)
				{

				}
				else
				{
					if (strcmp(argv[2], "/") == 0)
					{

					}
					else
					{
						if (strcmp(argv[2], "^") == 0)
						{

						}
					}
				}
			}
		}
	}
	
	cin.get();
	return 0;

}