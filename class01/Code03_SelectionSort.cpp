#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void Swap(int* x, int* y)
{
	int temp = *y;
	*y = *x;
	*x = temp;
}

//升序排序
void SelectionSort(vector<int>& v)
{
	int size = v.size();
	if (v.empty() || size < 2)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			//遍历i ~ size范围，并找到该范围内的最小数
			int* min = &v[i];
			if (v[j] < v[i])
			{
				min = &v[j];
			}
			//将i ~ size范围内最小的数与第i的数进行交换
			Swap(&v[i], min);
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	vector<int> v;


	/*for (int i = 0; i < 10; i++)
	{
		v.push_back((rand() % 50 + 1));
	}*/
	v.push_back(10);
	v.push_back(5);


	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	SelectionSort(v);

	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}