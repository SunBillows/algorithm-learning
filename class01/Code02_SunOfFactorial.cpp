#include <iostream>

//给定一个参数N，求1！+2！+3！+.....+N！

int test(int N)
{
	int sum = 0;
	int jiecheng = 1;

	for (int i = 1; i <= N; i++)
	{
		jiecheng = jiecheng * i;		//当前数的阶乘 = 前一个数的阶乘 * 当前的数
		sum += jiecheng;				//再将该阶乘加入总和
	}
	return sum;
}

int main()
{
	int num = 10;
	std::cout << test(num) << std::endl;


	return 0;
}