#include <iostream>
#include <iomanip>

using namespace std;

void array_print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
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
	const int size = 20;
	int arr[size];

	const int shift = 3;

	srand(time(NULL));
	fill_array(arr, size);

	cout << "Array :" << endl;
	array_print(arr, size);
	cout << endl;

	int* shiftArr = new int[shift];
	
	for (int i = 0; i < shift; i++)
		shiftArr[i] = arr[i];
	/*
	for (int i = 0; i < size; i++)
	{
		if (i < size - shift)
			arr[i] = arr[i + shift];
		else {
//			arr[i] = 0;
			arr[i] = shiftArr[i + shift - size];
		}
	}
	*/

	for (int i = shift; i < size; i++)
	{
		arr[i - shift] = arr[i];
//		arr[i] = 0;
	}

	for (int i = size - shift; i < size; i++)
	{
		arr[i] = shiftArr[i + shift - size];
	}

	delete shiftArr;

	cout << "Array :" << endl;
	array_print(arr, size);
	cout << endl;

	system("pause");
	return 0;
}