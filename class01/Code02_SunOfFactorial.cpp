#include <iostream>

//����һ������N����1��+2��+3��+.....+N��

int test(int N)
{
	int sum = 0;
	int jiecheng = 1;

	for (int i = 1; i <= N; i++)
	{
		jiecheng = jiecheng * i;		//��ǰ���Ľ׳� = ǰһ�����Ľ׳� * ��ǰ����
		sum += jiecheng;				//�ٽ��ý׳˼����ܺ�
	}
	return sum;
}

int main()
{
	int num = 10;
	std::cout << test(num) << std::endl;


	return 0;
}