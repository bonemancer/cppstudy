#include <iostream>
#include <iomanip>
using namespace std;

void array_print(int arr[], int Size)
{
	for (int i = 0; i < Size; i++)
		cout << setw(4) << arr[i];
	cout << endl;
}



void fill_array(int arr[], int Size)
{
	for (int i = 0; i < Size;)
	{
		int val = rand() % 100;
		bool found = false;

		for (int j = 0; j < i; j++)
			if (arr[j] == val)
			{
				found = true;
				break;
			}

		if (found == false)
			arr[i++] = val;
	}
}


int main()
{

	const int Size = 10;
	int arr[Size];
	int summ = 0;

	srand(time(NULL));
	fill_array(arr, Size);

	cout << "Array :" << endl;
	array_print(arr, Size);

	/*for (int i = 0; i < Size; i += 2)
	{
		arr[i] ++;
	}*/


	for (int i = 1; i < Size; i += 2)
	{
		summ += arr[i];

	}

	cout << "Array summ:" << endl;
	/*array_print(arr, Size);*/
	cout << summ << endl;


	system("pause");
	return 0;
}
