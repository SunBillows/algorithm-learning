#include <iostream>

//输入一个整数，输出其二进制数
void PrintBinary(int num)
{
	for (int i = 31; i >= 0; i--)
	{
		std::cout << ((num & (1 << i)) == 0 ? "0" : "1");
	}
	std::cout << std::endl;
}

int main()
{
	/*int num = 32767;
	PrintBinary(num);

	int a = 5;
	int b = -a;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << (~a + 1) << std::endl;*/

	std::cout << INT_MIN << std::endl;
	std::cout << -INT_MIN << std::endl;



	return 0;
}