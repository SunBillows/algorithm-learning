//������10���������� 1 �ĸ���
//��Ŀ����ʵ��һ������������һ��������������������Ʊ�ʾ�� 1 �ĸ�����

#include <iostream>
using namespace std;

//����λ����
int NumberOf1InBinary_1(int n)
{
	int count = 0;
	while (n)
	{
		//�ж��������������ұ�һλ�ǲ��� 1 �������� count++
		if (n & 1)
			count++;
		//���Ű������������������һλ
		n = n >> 1;
	}
	return count;
}

int NumberOf1InBinary_2(int n)
{
	int count = 0;
	int flag = 0;
	while (n)
	{
		//�ж��������������ұ�һλ�ǲ��� 1 �������� count++
		if (n & flag)
			count++;
		//���Ű� 1 �����ƶ�һλ�Ӷ����������ֵ���ұߵڶ�λ����������
		flag = flag << 1;
	}
	return count;
}

//˼·������һ��������ȥ 1 ,�������ұߵ� 1 ���� 0 ���� 1 ����߱��ֲ��䣬�ұ�ȡ����
//			����������� -1 ��λ������ʱ���Ὣ�� 1 �ұߵ�����������ȫ����Ϊ 0 ��ÿ����һ�ξ��ܼ��� 1 �ĸ�����ֱ��Ϊ 0��
int NumberOf1InBinary_3(int n)
{
	int count = 0;

	while (n)
	{
		n = n & (n - 1);
		count++;
	}

	return count;
}


// ====================���Դ���====================
void Test(int number, unsigned int expected)
{
	int actual = NumberOf1InBinary_3(number);
	if (actual == expected)
		printf("Solution1: Test for %p passed.\n", number);
	else
		printf("Solution1: Test for %p failed.\n", number);

	actual = NumberOf1InBinary_3(number);
	if (actual == expected)
		printf("Solution2: Test for %p passed.\n", number);
	else
		printf("Solution2: Test for %p failed.\n", number);

	printf("\n");
}

int main(int argc, char* argv[])
{
	// ����0���ڴ��������0
	Test(0, 0);

	// ����1���ڴ��������1
	Test(1, 1);

	// ����10���ڴ��������2
	Test(10, 2);

	// ����0x7FFFFFFF���ڴ��������31
	Test(0x7FFFFFFF, 31);

	// ����0xFFFFFFFF�����������ڴ��������32
	Test(0xFFFFFFFF, 32);

	// ����0x80000000�����������ڴ��������1
	Test(0x80000000, 1);

	return 0;
}
