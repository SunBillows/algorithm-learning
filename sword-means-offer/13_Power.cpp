//面试题11：数值的整数次方
//题目：实现函数 double Power(double base,int exponent),求 base 的 exponent 次方。


#include <iostream>
using namespace std;


bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

//只考虑指数 exponent 是正数的情况
double Power_1(double base, int exponent)
{
	double ans = 1.0;
	for (int i = 0; i < exponent; i++)
	{
		ans *= base;
	}
	return ans;
}

bool g_InvalidInput = false;

//考虑指数 exponent 是 0 或负数的情况
double Power_2(double base, int exponent)
{
	//首先需要判断，当 base 为 0 ，且 exponent 为负数时，程序抛出异常
	if (equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}

	int absExponent = exponent;
	if (exponent < 0)
		absExponent = -exponent;
	double ans = Power_1(base, absExponent);
	if (exponent < 0)
		ans = 1.0 / ans;

	return ans;	
}

////由于 double 类型精度不等原因，无法直接利用 == 来进行判断
////所以写一个函数来判断两个浮点型的数据类型是否相等
//bool equal_float(double num1, double num2)
//{
//
//}


// ====================测试代码====================
void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
	double result = Power_2(base, exponent);
	if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
		std::cout << testName << " passed" << std::endl;
	else
		std::cout << testName << " FAILED" << std::endl;
}

int main(int argc, char* argv[])
{
	// 底数、指数都为正数
	Test("Test1", 2, 3, 8, false);

	// 底数为负数、指数为正数
	Test("Test2", -2, 3, -8, false);

	// 指数为负数
	Test("Test3", 2, -3, 0.125, false);

	// 指数为0
	Test("Test4", 2, 0, 1, false);

	// 底数、指数都为0
	Test("Test5", 0, 0, 1, false);

	// 底数为0、指数为正数
	Test("Test6", 0, 4, 0, false);

	// 底数为0、指数为负数
	Test("Test7", 0, -4, 0, true);

	return 0;
}
