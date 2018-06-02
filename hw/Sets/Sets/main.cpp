#include <iostream>
#include <iomanip>

using namespace std;

void array_print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << arr[i];
	cout << endl;
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
	for (int i = 0; i < arr1_size;)
	{
		int val = rand() % 50;
		bool found = false;

		for (int j = 0; j < i; j++)
			if (arr1[j] == val)
			{
				found = true;
				break;
			}
			
		if (found == false)
			arr1[i++] = val;
	}
	
	for (int i = 0; i < arr2_size;)
	{
		int val = rand() % 50;
		bool found = false;

		for (int j = 0; j < i; j++)
			if (arr2[j] == val)
			{
				found = true;
				break;
			}

		if (found == false)
			arr2[i++] = val;
	}

	
	/* output initialized arrays */
	cout << "Array 1:" << endl;
	for (int i = 0; i < arr1_size; i++)
		cout << setw(4) << arr1[i];

	cout << endl;

	cout << "Array 2:" << endl;
	for (int j = 0; j < arr2_size; j++)
		cout << setw(4) << arr2[j];

	cout << endl;

	/* find sets interception */
	int k = 0;
	for (int i = 0; i < arr1_size; i++)
	{
		for (int j = 0; j < arr2_size; j++)
		{
			if (arr1[i] == arr2[j])
			{
				arr3[k++] = arr1[i];
				break;
			}
		}
	}

	/* find sets disjunction */
	/* we do not use interception array */
	int l = 0;
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
			arr4[l++] = arr1[i];
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
			arr4[l++] = arr2[i];
	}

	/* find sets disjunction */
	/* we do use interception array */
	int m = 0;
	for (int i = 0; i < arr1_size; i++)
	{
		bool found = false;
		for (int j = 0; j < k; j++)
			if (arr1[i] == arr3[j])
			{
				found = true;
				break;
			}

		if (found == false)
			arr5[m++] = arr1[i];
	}

	for (int i = 0; i < arr2_size; i++)
	{
		bool found = false;
		for (int j = 0; j < k; j++)
			if (arr2[i] == arr3[j])
			{
				found = true;
				break;
			}

		if (found == false)
			arr5[m++] = arr2[i];
	}

	/* output result arrays */
	/* setw(4) задает ширину поля для вывода значения */
	cout << "Array 3:" << endl;
	array_print(arr3, k);

#if 0
	for (int j = 0; j < k; j++)
		cout << setw(4) << arr3[j];

	cout << endl;
#endif

	/* sets disjunction - first variant */
	cout << "Array 4:" << endl;
	for (int j = 0; j < l; j++)
		cout << setw(4) << arr4[j];

	cout << endl;

	/* sets disjunction - second variant */
	cout << "Array 5:" << endl;
	for (int j = 0; j < m; j++)
		cout << setw(4) << arr5[j];

	cout << endl;

	delete arr3;
	delete arr4;
	delete arr5;

	system("pause");
	return 0;
}
