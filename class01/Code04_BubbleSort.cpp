#include <iostream>
using namespace std;
#include <vector>
#include <time.h>


void Swap(int* x, int* y)
{
	int temp = *y;
	*y = *x;
	*x = temp;
}

void Printf(vector<int> arr)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//√∞≈›≈≈–Ú
void BubbleSort(vector<int>& arr)
{
	//±ﬂΩÁÃıº˛
	int n = arr.size();
	if (arr.empty() || n < 1)
		return;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n-1; j++)
		{
			if (arr[j] > arr[j + 1])
				Swap(&arr[j], &arr[j + 1]);
		}
	}
}

//≤Â»Î≈≈–Ú
void InsertSort(vector<int>& arr)
{
	int size = arr.size();
	if (arr.empty() || size < 2)
		return;

	//0~i ∑∂Œßƒ⁄”––Ú
	for (int i = 1; i < size; i++)
	{
		int numarrIndex = i;
		while (numarrIndex - 1 >= 0 && arr[numarrIndex] > arr[numarrIndex - 1])
		{
			Swap(&arr[numarrIndex], &arr[numarrIndex - 1]);
			numarrIndex--;
		}
	}
}

int main()
{
	srand((int)time(NULL));

	vector<int> arr;
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(rand() % 50 + 1);
	}

	Printf(arr);

	//BubbleSort(arr);
	InsertSort(arr);

	Printf(arr);

	return 0;
}