//ʹ��λ����ʵ�ּӼ��˳�
#include <iostream>
using namespace std;

int BitAdd(int a,int b)
{
	int sum = 0;
	//����λΪ 0 ��û�в�����λʱ��
	while (b != 0)
	{
		sum = a ^ b;		//sum �����洢�޽�λ��ӵ�ֵ
		b = (a & b) << 1;	// b �����洢��λֵ
		a = sum;			// a �洢�޽�λ��ӵ�ֵ
	}
	//�����޽�λ���
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
		//�� b �����ұ��ϵ�λ��ֵ��Ϊ 1 ���� a<<1 b>>1;
		if ((b & 1) != 0)
			ans = BitAdd(ans, a);

		a <<= 1;
		b >>= 1;		//�޷������ƶ�
	}
	return ans;
}


//�жϸ���ֵ�Ƿ�Ϊ����
bool isNeg(int a)
{
	return a < 0;
}
//����������ȡ��
int negNum(int a)
{
	return (~a + 1);
}
int BitDiv(int a, int b)
{
	//������Ĳ�����Ϊ����
	int x = isNeg(a) ? negNum(a) : a;
	int y = isNeg(b) ? negNum(b) : b;
	int ans = 0;
	
	//�����������ƶ����뱻�����ӽ�ʱ��ִ�в���
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