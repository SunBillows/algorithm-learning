#include <iostream>
using namespace std;
#include <time.h>

//交换函数
void MySwap(int* a1, int* a2)
{
	int temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}

//快速排序，找到关键字，将小于该关键字的数据放入该关键字左边，大于该关键字的数据放入该关键字的右边
int FindKeyValue(int* arr,int start,int end)
{
	//key用于存储关键字
	int key = arr[start];
	while (start < end)
	{
		//当左边界小于右边界且右边界的值大于 key 值时，end 往前移动
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

	//将该关键字在数组中的下标赋值给key
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