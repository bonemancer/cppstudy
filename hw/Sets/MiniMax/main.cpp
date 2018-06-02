#include <iostream>
#include <iomanip>

using namespace std;

void array_print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << arr[i];
	cout << endl;
}

void fill_array(int arr[], int size)
{
	for (int i = 0; i < size;)
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
	const int arr1_size = 40;

	/* initial arrays */
	int arr1[arr1_size];

	srand(time(NULL));

	/* init arrays with unique values */
	fill_array(arr1, arr1_size);

	/* output initialized arrays */
	cout << "Array 1:" << endl;
	array_print(arr1, arr1_size);

	int min = arr1[0];
	int max = arr1[0];

	for (int a = 1; a < arr1_size; a++)
	{
		if (min > arr1[a])
			min = arr1[a];

		if (max < arr1[a])
			max = arr1[a];
	}

	cout << "minimum: " << min << endl;
	cout << "maximum: " << max << endl;
	cout << "first:  " << arr1[0] << endl;
	cout << "last:   " << arr1[arr1_size - 1] << endl;
	cout << "middle: " << arr1[(arr1_size /2)- 1] << endl;


	int x1 = 234;
	int x2 = 67;

	int x3;

	x3 = x1 > x2 ? x1 : x2;

	cout << "x3: " << x3 << endl;

	system("pause");
	return 0;
}
