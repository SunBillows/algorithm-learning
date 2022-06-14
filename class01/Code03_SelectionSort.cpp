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

//��������
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
			//����i ~ size��Χ�����ҵ��÷�Χ�ڵ���С��
			int* min = &v[i];
			if (v[j] < v[i])
			{
				min = &v[j];
			}
			//��i ~ size��Χ����С�������i�������н���
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