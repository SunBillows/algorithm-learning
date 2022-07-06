//面试题10：二进制中 1 的个数
//题目：请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。

#include <iostream>
using namespace std;

//采用位运算
int NumberOf1InBinary_1(int n)
{
	int count = 0;
	while (n)
	{
		//判断整数二进制最右边一位是不是 1 ，若是则 count++
		if (n & 1)
			count++;
		//接着把输入的整数整体右移一位
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
		//判断整数二进制最右边一位是不是 1 ，若是则 count++
		if (n & flag)
			count++;
		//接着把 1 向左移动一位从而与输入的数值的右边第二位进行与运算
		flag = flag << 1;
	}
	return count;
}

//思路分析：一个整数减去 1 ,它的最右边的 1 会变成 0 ，该 1 的左边保持不变，右边取反。
//			当该数与该数 -1 做位与运算时，会将该 1 右边的数与它本身全部置为 0 ；每操作一次就能计算 1 的个数，直至为 0；
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


// ====================测试代码====================
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
	// 输入0，期待的输出是0
	Test(0, 0);

	// 输入1，期待的输出是1
	Test(1, 1);

	// 输入10，期待的输出是2
	Test(10, 2);

	// 输入0x7FFFFFFF，期待的输出是31
	Test(0x7FFFFFFF, 31);

	// 输入0xFFFFFFFF（负数），期待的输出是32
	Test(0xFFFFFFFF, 32);

	// 输入0x80000000（负数），期待的输出是1
	Test(0x80000000, 1);

	return 0;
}
