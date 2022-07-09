//������12����ӡ 1 ������ n λ��
//��Ŀ���������� n ����˳���ӡ���� 1 ������ n λʮ������


#include<iostream>
#include <vector>
using namespace std;

//�����ݺܴ�ʱ���ýⷨ�ᵼ�����
void Print1ToMaxOfNDigits_1(int n)
{
	if (n <= 0)
	{
		cout << "�����λ������������" << endl;
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



//д��һ��������ʵ���ڱ�ʾ���ֵ��ַ��� number ������ 1 ,ͬʱ�жϸ��ַ����Ƿ�ﵽ���ֵ
bool Increment(char* number)
{
	int isOverflow = false;
	int length = strlen(number);
	//����һ����λ��־
	int carry = 0;

	for (int i = length - 1; i >= 0; i--)
	{
		//������ַ�����ʾ����ֵ
		int temp = number[i] - '0' + carry;

		//���һλ������������
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

//�����ַ��������ϴ��������ʵ��������
void Print1ToMaxOfNDigits_2(int n)
{
	if (n <= 0)
	{
		cout << "�����λ������������" << endl;
		return;
	}

	//����һ����СΪ n + 1 ���ַ���
	//���ַ�������Ϊȫ����ֵΪ 0 �������һλҪΪ \0 �ַ���
	char* number = new char[n + 1];
	//���� memset �����鸳��ֵ
	memset(number, '0', n);
	number[n] = '\0';
	
	while (!Increment(number))
	{
		PrintfNumber(number);
	}

	delete[] number;
}





// ====================���Դ���====================
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

