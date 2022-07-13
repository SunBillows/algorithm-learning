//使用位运算实现加减乘除
#include <iostream>
using namespace std;

int BitAdd(int a,int b)
{
	int sum = 0;
	//当进位为 0 （没有产生进位时）
	while (b != 0)
	{
		sum = a ^ b;		//sum 变量存储无进位相加的值
		b = (a & b) << 1;	// b 变量存储进位值
		a = sum;			// a 存储无进位相加的值
	}
	//返回无进位相加
	return a;
}

int BitMinus(int a, int b)
{
	return BitAdd(a, BitAdd(~b, 1));
}

int BitMulti(int a, unsigned int b)
{
	int ans = 0;
	while (b != 0)
	{
		//若 b 的最右边上的位的值不为 1 ，则 a<<1 b>>1;
		if ((b & 1) != 0)
			ans = BitAdd(ans, a);

		a <<= 1;
		b >>= 1;		//无符号右移动
	}
	return ans;
}


//判断该数值是否为负数
bool isNeg(int a)
{
	return a < 0;
}
//将该数进行取反
int negNum(int a)
{
	return (~a + 1);
}
int BitDiv(int a, int b)
{
	//将传入的参数变为正数
	int x = isNeg(a) ? negNum(a) : a;
	int y = isNeg(b) ? negNum(b) : b;
	int ans = 0;
	
	//当除数右移移动到与被除数接近时，执行操作
	for (int i = 30; i >= 0; i = BitMinus(i, 1))
	{
		if ((x >> i) >= y)
		{
			ans |= (1 << i);
			x = BitMinus(x, y << i);
		}
	}
	return isNeg(a) ^ isNeg(b) ? negNum(ans) : ans;
}


int main()
{
	cout << BitAdd(38, 12) << endl;
	cout << BitMinus(38, 12) << endl;
	cout << BitMulti(-20, -20) << endl;
	cout << BitDiv(-22,-7) << endl;

	return 0;
}