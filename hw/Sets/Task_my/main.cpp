#include <iostream>
#include <iomanip>
#include <list>
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
	int cycle = arr[0];

	srand(time(NULL));
	fill_array(arr, Size);

	cout << "Array :" << endl;
	array_print(arr, Size);

	/*for (int i = 0; i < Size; i += 2)
	{
		arr[i] ++;
	}*/


	//for (int i = 1; i < Size; i += 2)
	//{
	//	summ += arr[i];

	//}

	//cout << "Array summ:" << endl;
	//array_print(arr, Size);
	//cout << summ << endl;

	/*for (int i(2); i < Size; i++)
	{
		arr[i - 2] = arr[i];
		arr[i] = 0;
	}*/

	list<int> tmp;
	for (int i(3); i < Size; i++)
	{
		if ((i - 3) < 4)
		{
			tmp.push_back(arr[i - 3]);
		}

		arr[i - 3] = arr[i];
		if (i + 3 >= Size)
		{
			arr[i] = tmp.front();
			tmp.pop_front();
		}
	}

	array_print(arr, Size);

	system("pause");
	return 0;
}
