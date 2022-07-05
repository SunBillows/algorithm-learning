

#include <iostream>
using namespace std;

int FindMinNumInRotateArr(int* arr,int length)
{
	//找到左右边界数据的数组下标 left 和 right
	int left = 0;
	int right = length - 1;
	//初始化中间结点为 0；
	int mid = 0;

	//循环判断的结束条件为左边数据大于等于右边数据，若不能满足此条件则说明此区域为递增区域，直接输出左边界数据
	while (arr[left] >= arr[right])
	{
		//当两个下标相邻时，右边的下标所指向的数组元素则为最小值
		if (right - left == 1)
		{
			int mid = right;
			break;
		}

		mid = left + ((right - left) >> 1);
		//当三者相等时，则需要采用顺序查找方式找到最小值
		if (arr[mid] == arr[left] && arr[mid] == arr[right])
		{
			int min = arr[left];
			for (int i = left; i <= right; i++)
			{
				if (arr[i] < min)
					min = arr[i];
			}
			return min;
		}
		//当中间的元素大于等于最左边元素时，说明[left，mid]区域内为递增序列且都比最小值大
		if (arr[mid] >= arr[left])
		{
			left = mid;
		}
		else if (arr[mid] <= arr[right])
		{
			right = mid;
		}
		
	}

	//最后输出找到的最小值
	return arr[mid];
}

void Test(int* numbers, int length, int expected)
{
	int result = 0;
	try
	{
		result = FindMinNumInRotateArr(numbers, length);

		for (int i = 0; i < length; ++i)
			printf("%d ", numbers[i]);

		if (result == expected)
			printf("\tpassed\n");
		else
			printf("\tfailed\n");
	}
	catch (...)
	{
		if (numbers == nullptr)
			printf("Test passed.\n");
		else
			printf("Test failed.\n");
	}
}

int main(int argc, char* argv[])
{
	// 典型输入，单调升序的数组的一个旋转
	int array1[] = { 3, 4, 5, 1, 2 };
	Test(array1, sizeof(array1) / sizeof(int), 1);

	// 有重复数字，并且重复的数字刚好的最小的数字
	int array2[] = { 3, 4, 5, 1, 1, 2 };
	Test(array2, sizeof(array2) / sizeof(int), 1);

	// 有重复数字，但重复的数字不是第一个数字和最后一个数字
	int array3[] = { 3, 4, 5, 1, 2, 2 };
	Test(array3, sizeof(array3) / sizeof(int), 1);

	// 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
	int array4[] = { 1, 0, 1, 1, 1 };
	Test(array4, sizeof(array4) / sizeof(int), 0);

	// 单调升序数组，旋转0个元素，也就是单调升序数组本身
	int array5[] = { 1, 2, 3, 4, 5 };
	Test(array5, sizeof(array5) / sizeof(int), 1);

	// 数组中只有一个数字
	int array6[] = { 2 };
	Test(array6, sizeof(array6) / sizeof(int), 2);

	// 输入nullptr
	Test(nullptr, 0, 0);

	return 0;
}