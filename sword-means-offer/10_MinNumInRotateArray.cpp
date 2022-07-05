

#include <iostream>
using namespace std;

int FindMinNumInRotateArr(int* arr,int length)
{
	//�ҵ����ұ߽����ݵ������±� left �� right
	int left = 0;
	int right = length - 1;
	//��ʼ���м���Ϊ 0��
	int mid = 0;

	//ѭ���жϵĽ�������Ϊ������ݴ��ڵ����ұ����ݣ������������������˵��������Ϊ��������ֱ�������߽�����
	while (arr[left] >= arr[right])
	{
		//�������±�����ʱ���ұߵ��±���ָ�������Ԫ����Ϊ��Сֵ
		if (right - left == 1)
		{
			int mid = right;
			break;
		}

		mid = left + ((right - left) >> 1);
		//���������ʱ������Ҫ����˳����ҷ�ʽ�ҵ���Сֵ
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
		//���м��Ԫ�ش��ڵ��������Ԫ��ʱ��˵��[left��mid]������Ϊ���������Ҷ�����Сֵ��
		if (arr[mid] >= arr[left])
		{
			left = mid;
		}
		else if (arr[mid] <= arr[right])
		{
			right = mid;
		}
		
	}

	//�������ҵ�����Сֵ
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
	// �������룬��������������һ����ת
	int array1[] = { 3, 4, 5, 1, 2 };
	Test(array1, sizeof(array1) / sizeof(int), 1);

	// ���ظ����֣������ظ������ָպõ���С������
	int array2[] = { 3, 4, 5, 1, 1, 2 };
	Test(array2, sizeof(array2) / sizeof(int), 1);

	// ���ظ����֣����ظ������ֲ��ǵ�һ�����ֺ����һ������
	int array3[] = { 3, 4, 5, 1, 2, 2 };
	Test(array3, sizeof(array3) / sizeof(int), 1);

	// ���ظ������֣������ظ������ָպ��ǵ�һ�����ֺ����һ������
	int array4[] = { 1, 0, 1, 1, 1 };
	Test(array4, sizeof(array4) / sizeof(int), 0);

	// �����������飬��ת0��Ԫ�أ�Ҳ���ǵ����������鱾��
	int array5[] = { 1, 2, 3, 4, 5 };
	Test(array5, sizeof(array5) / sizeof(int), 1);

	// ������ֻ��һ������
	int array6[] = { 2 };
	Test(array6, sizeof(array6) / sizeof(int), 2);

	// ����nullptr
	Test(nullptr, 0, 0);

	return 0;
}