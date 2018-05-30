#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const int arr1_size = 10;
	const int arr2_size = 30;

	/* initial arrays */
	int arr1[arr1_size];
	int arr2[arr2_size];

	/* interception array */
	int arr3[20];

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
	
	for (int j = 0; j < arr2_size; j++)
		arr2[j] = rand() % 50;
	
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

	cout << "Array 3:" << endl;
	for (int j = 0; j < k; j++)
		cout << setw(4) << arr3[j];

	cout << endl;


	system("pause");
	return 0;
}
