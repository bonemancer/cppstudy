#include <iostream>
#include <iomanip>

using namespace std;

void array_print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << i;
	cout << endl;

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
	const int arr_size = 21;
	int arr[arr_size];

	fill_array(arr, arr_size);

	cout << "Initial array:" << endl;
	array_print(arr, arr_size);
	cout << endl;

#if 0
	/* print array vice versa */
	/* variant 1 */
	/* first we output indexes */
	cout << "Variant1:" << endl;
	for (int i = 0; i < arr_size; i++)
		cout << setw(4) << arr_size - i - 1;
	cout << endl;

	for (int i = 0; i < arr_size; i++)
		cout << setw(4) << arr[arr_size - i - 1];
	cout << endl << endl;

	/* variant 2 */
	cout << "Variant2:" << endl;
	for (int i = arr_size; i > 0; i--)
		cout << setw(4) << i - 1;
	cout << endl;

	for (int i = arr_size; i > 0; i--)
		cout << setw(4) << arr[i - 1];
	cout << endl << endl;

	/* variant 3 */
	cout << "Variant3:" << endl;
	for (int i = arr_size - 1; i >= 0; i--)
		cout << setw(4) << i;
	cout << endl;

	for (int i = arr_size - 1; i >= 0; i--)
		cout << setw(4) << arr[i];
	cout << endl << endl;

	/* output each second array element */
	cout << "Each second element starting from 0:" << endl;
	for (int i = 0; i < arr_size; i += 2)
		cout << setw(4) << i;
	cout << endl;

	for (int i = 0; i < arr_size; i += 2)
		cout << setw(4) << arr[i];
	cout << endl << endl;

	/* output each third array element */
	cout << "Each third element starting from 0:" << endl;
	for (int i = 0; i < arr_size; i += 3)
		cout << setw(4) << i;
	cout << endl;

	for (int i = 0; i < arr_size; i += 3)
		cout << setw(4) << arr[i];
	cout << endl << endl;

	/* output second part of array */
	cout << "Second part of array:" << endl;
	for (int i = arr_size / 2; i < arr_size; i++)
		cout << setw(4) << i;
	cout << endl;

	for (int i = arr_size / 2; i < arr_size; i++)
		cout << setw(4) << arr[i];
	cout << endl << endl;
#endif

	/* output first part of array vice versa */
	/* identical to variant 2 */
	cout << "First part of array vice versa:" << endl;
	for (int i = arr_size / 2; i > 0; i--)
		cout << setw(4) << i - 1;
	cout << endl;

	for (int i = arr_size / 2; i > 0; i--)
		cout << setw(4) << arr[i - 1];
	cout << endl << endl;

	/* array reverse */
	for (int i = 0; i < arr_size / 2; i++)
	{
		int tmp = arr[i];
		arr[i] = arr[arr_size - i - 1];
		arr[arr_size - i - 1] = tmp;
	}

	cout << "Reversed array:" << endl;
	array_print(arr, arr_size);
	cout << endl;

	/* array reverse */
	for (int i = 0; i < arr_size / 2; i++)
	{
		int tmp = arr[i];
		arr[i] = arr[arr_size / 2 + i + 1];
		arr[arr_size / 2 + i + 1] = tmp;
	}

	cout << "Reversed array2:" << endl;
	array_print(arr, arr_size);
	cout << endl;

	system("pause");
	return 0;
}