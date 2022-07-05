#include <iostream>
using namespace std;
#include <time.h>

//��������
void MySwap(int* a1, int* a2)
{
	int temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}

//���������ҵ��ؼ��֣���С�ڸùؼ��ֵ����ݷ���ùؼ�����ߣ����ڸùؼ��ֵ����ݷ���ùؼ��ֵ��ұ�
int FindKeyValue(int* arr,int start,int end)
{
	//key���ڴ洢�ؼ���
	int key = arr[start];
	while (start < end)
	{
		//����߽�С���ұ߽����ұ߽��ֵ���� key ֵʱ��end ��ǰ�ƶ�
		while (start < end && arr[end] >= key)
		{
			end--;
		}
		MySwap(&arr[start], &arr[end]);
		//arr[start] = arr[end];
		while (start < end && arr[start] <= key)
		{
			start++;
		}
		MySwap(&arr[start], &arr[end]);
		//arr[end] = arr[start];
	}
	arr[start] = key;
	return start;
}

void MyQuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;

	//���ùؼ����������е��±긳ֵ��key
	int Index = FindKeyValue(arr, left,right);
	MyQuickSort(arr, 0, Index - 1);
	MyQuickSort(arr, Index + 1, right);
}

void MyArrPrintf(int* arr,int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 20;
	}

	MyArrPrintf(arr, 10);

	MyQuickSort(arr, 0, 9);
	std::cout << endl;

	MyArrPrintf(arr, 10);

	return 0;
}