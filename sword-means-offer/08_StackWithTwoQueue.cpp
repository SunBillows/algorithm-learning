//������7(��)������������ʵ��ջ
//����������ʵ��ջ��ջ���������£���ʵ�������������� appendTail �� deleteHead��
//�ֱ������ջ����ɲ���ɾ������
#include <iostream>
using namespace std;
#include <queue>

template<typename T>
class CStack
{
public:
	CStack();
	~CStack();
	void appendTail(const T& data);
	T deleteHead();

private:
	queue<T> q1;
	queue<T> q2;
};

//���캯��
template<typename T>
CStack<T>::CStack(void)
{

}

//��������
template<typename T>
CStack<T>::~CStack(void)
{

}

//����Ԫ��
template<typename T>
void CStack<T>::appendTail(const T& data)
{
	q1.push(data);
}

//����Ԫ��
template<typename T>
T CStack<T>::deleteHead()
{
	//�� q1 Ϊ��ʱ���� q2 �е����ƶ��� q1 ���������һ����
	if (q1.empty())
	{
		while (q2.size() > 1)
		{
			q1.push(q2.front());
			q2.pop();
		}
		T temp = q2.front();
		q2.pop();
		return temp;
	}
	else
	{
		while(q1.size() > 1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		T temp = q1.front();
		q1.pop();
		return temp;
	}
}


void Test(char actual, char expected)
{
	if (actual == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main()
{
	CStack<char> stack;

	stack.appendTail('a');
	stack.appendTail('b');
	stack.appendTail('c');

	char head = stack.deleteHead();
	Test(head, 'c');

	head = stack.deleteHead();
	Test(head, 'b');

	stack.appendTail('d');
	head = stack.deleteHead();
	Test(head, 'd');

	stack.appendTail('e');
	head = stack.deleteHead();
	Test(head, 'e');

	head = stack.deleteHead();
	Test(head, 'a');

	return 0;
}