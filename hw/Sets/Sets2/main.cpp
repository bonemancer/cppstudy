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
		int val = rand() % 50;
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

void intercept_arrays(int arr1[], int arr1_size,
	int arr2[], int arr2_size, int arr3[], int &arr3_size)
{
	arr3_size = 0;
	for (int i = 0; i < arr1_size; i++)
	{
		for (int j = 0; j < arr2_size; j++)
		{
			if (arr1[i] == arr2[j])
			{
				arr3[arr3_size++] = arr1[i];
				break;
			}
		}
	}
}

void arrays_disjunction(int arr1[], int arr1_size,
	int arr2[], int arr2_size, int arr4[], int &arr4_size)
{
	arr4_size = 0;

	for (int i = 0; i < arr1_size; i++)
	{
		bool found = false;
		for (int j = 0; j < arr2_size; j++)
			if (arr1[i] == arr2[j])
			{
				found = true;
				break;
			}

		if (found == false)
			arr4[arr4_size++] = arr1[i];
	}

	for (int i = 0; i < arr2_size; i++)
	{
		bool found = false;
		for (int j = 0; j < arr1_size; j++)
			if (arr2[i] == arr1[j])
			{
				found = true;
				break;
			}

		if (found == false)
			arr4[arr4_size++] = arr2[i];
	}
}

void arrays_disjunction_intercept(int arr1[], int arr1_size,
	int arr2[], int arr2_size, int arr3[], int arr3_size,
	int arr5[], int &arr5_size)
{
	arr5_size = 0;

	for (int i = 0; i < arr1_size; i++)
	{
		bool found = false;
		for (int j = 0; j < arr3_size; j++)
			if (arr1[i] == arr3[j])
			{
				found = true;
				break;
			}

		if (found == false)
			arr5[arr5_size++] = arr1[i];
	}

	for (int i = 0; i < arr2_size; i++)
	{
		bool found = false;
		for (int j = 0; j < arr3_size; j++)
			if (arr2[i] == arr3[j])
			{
				found = true;
				break;
			}

		if (found == false)
			arr5[arr5_size++] = arr2[i];
	}

}

int main()
{
	const int arr1_size = 40;
	const int arr2_size = 30;

	/* initial arrays */
	int arr1[arr1_size];
	int arr2[arr2_size];

	/* interception array */
	int arr3_size = (arr2_size < arr1_size) ? arr2_size : arr1_size;

#if 0
	int arr3_size = 0;
	if (arr2_size < arr1_size)
		arr3_size = arr2_size;
	else
		arr3_size = arr1_size;
#endif	

	int* arr3 = new int[arr3_size];

	/* disjunction array */
	int arr4_size = arr1_size + arr2_size;
	int* arr4 = new int[arr4_size];

	int arr5_size = arr1_size + arr2_size;
	int* arr5 = new int[arr5_size];

	srand(time(NULL));

	/* init arrays with unique values */
	fill_array(arr1, arr1_size);
	fill_array(arr2, arr2_size);

	/* output initialized arrays */
	cout << "Array 1:" << endl;
	array_print(arr1, arr1_size);

	cout << "Array 2:" << endl;
	array_print(arr2, arr2_size);

	/* find sets interception */
	int k = 0;
	intercept_arrays(arr1, arr1_size, arr2, arr2_size, arr3, k);

	/* find sets disjunction */
	/* we do not use interception array */
	int l = 0;
	arrays_disjunction(arr1, arr1_size, arr2, arr2_size, arr4, l);

	/* find sets disjunction */
	/* we do use interception array */
	int m = 0;
	arrays_disjunction_intercept(arr1, arr1_size,
		arr2, arr2_size, arr3, k, arr5, m);
	
	/* output result arrays */
	/* setw(4) задает ширину поля для вывода значения */
	cout << "Array 3:" << endl;
	array_print(arr3, k);

	/* sets disjunction - first variant */
	cout << "Array 4:" << endl;
	array_print(arr4, l);

	/* sets disjunction - second variant */
	cout << "Array 5:" << endl;
	array_print(arr5, m);

	delete arr3;
	delete arr4;
	delete arr5;

	system("pause");
	return 0;
}
