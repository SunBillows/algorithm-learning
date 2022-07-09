//面试题12：打印 1 到最大的 n 位数
//题目：输入数字 n ，按顺序打印出从 1 到最大的 n 位十进制数


#include<iostream>
#include <vector>
using namespace std;

//当数据很大时，该解法会导致溢出
void Print1ToMaxOfNDigits_1(int n)
{
	if (n <= 0)
	{
		cout << "输入的位数不符合条件" << endl;
		return;
	}
	long long max = 1;
	for (int i = 0; i < n; i++)
	{
		max *= 10;
	}

	for (long long i = 1; i < max; i++)
	{
		cout << i << " ";
	}
	cout << endl;
}



//写出一个函数，实现在表示数字的字符串 number 上增加 1 ,同时判断该字符串是否达到最大值
bool Increment(char* number)
{
	int isOverflow = false;
	int length = strlen(number);
	//定义一个进位标志
	int carry = 0;

	for (int i = length - 1; i >= 0; i--)
	{
		//求出该字符串表示的数值
		int temp = number[i] - '0' + carry;

		//最后一位进行自增操作
		if (i == length - 1)
		{
			temp++;
		}
		if (temp >= 10)
		{
			if (i == 0)
			{
				isOverflow = true;
			}
			else
			{
				temp -= 10;
				carry = 1;
				number[i] = '0' + temp;
			}
		}
		else
		{
			number[i] = '0' + temp;
			break;
		}

	}
	return isOverflow;

}

void PrintfNumber(char* number)
{
	char* cur = number;
	while (*cur == '0')
	{
		cur++;
	}
	cout << cur << " ";	
}

//利用字符串来表达较大的数，并实现逐步增加
void Print1ToMaxOfNDigits_2(int n)
{
	if (n <= 0)
	{
		cout << "输入的位数不符合条件" << endl;
		return;
	}

	//创建一个大小为 n + 1 的字符串
	//该字符串所有为全部赋值为 0 ，且最后一位要为 \0 字符；
	char* number = new char[n + 1];
	//利用 memset 对数组赋初值
	memset(number, '0', n);
	number[n] = '\0';
	
	while (!Increment(number))
	{
		PrintfNumber(number);
	}

	delete[] number;
}





// ====================测试代码====================
void Test(int n)
{
	printf("Test for %d begins:\n", n);

	Print1ToMaxOfNDigits_1(n);
	Print1ToMaxOfNDigits_2(n);

	printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
	Test(1);
	Test(2);
	Test(3);
	Test(0);
	Test(-1);

	return 0;
}

