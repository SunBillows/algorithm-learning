//������11����ֵ�������η�
//��Ŀ��ʵ�ֺ��� double Power(double base,int exponent),�� base �� exponent �η���


#include <iostream>
using namespace std;


bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

//ֻ����ָ�� exponent �����������
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

//����ָ�� exponent �� 0 ���������
double Power_2(double base, int exponent)
{
	//������Ҫ�жϣ��� base Ϊ 0 ���� exponent Ϊ����ʱ�������׳��쳣
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

////���� double ���;��Ȳ���ԭ���޷�ֱ������ == �������ж�
////����дһ���������ж����������͵����������Ƿ����
//bool equal_float(double num1, double num2)
//{
//
//}


// ====================���Դ���====================
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
	// ������ָ����Ϊ����
	Test("Test1", 2, 3, 8, false);

	// ����Ϊ������ָ��Ϊ����
	Test("Test2", -2, 3, -8, false);

	// ָ��Ϊ����
	Test("Test3", 2, -3, 0.125, false);

	// ָ��Ϊ0
	Test("Test4", 2, 0, 1, false);

	// ������ָ����Ϊ0
	Test("Test5", 0, 0, 1, false);

	// ����Ϊ0��ָ��Ϊ����
	Test("Test6", 0, 4, 0, false);

	// ����Ϊ0��ָ��Ϊ����
	Test("Test7", 0, -4, 0, true);

	return 0;
}
