//������7��������ջʵ�ֶ���
//������ջʵ�ֶ��С����е��������£���ʵ�������������� appendTail �� deleteHead��
//�ֱ�����ڶ���β����������ڶ���ͷ��ɾ����㹦��
#include <iostream>
using namespace std;
#include <stack>

template<typename T>
class CQueue
{
public:
	CQueue(void);
	~CQueue(void);
	void appendTail(const T& data);
	T deleteHead();

private:
	stack<T> s1;
	stack<T> s2;
};

//���캯��
template<typename T>
CQueue<T>::CQueue(void)
{
	
}

//��������
template<typename T>
CQueue<T>::~CQueue(void)
{

}

//���뺯��
template<typename T>	
void CQueue<T>::appendTail(const T& data)
{
	this->s1.push(data);
}

//ɾ������
template<typename T>
T CQueue<T>::deleteHead()
{
	//�� s2 Ϊ��ʱ���� s1 �е�Ԫ�ز����� s2 ��
	if (s2.empty())
	{
		//�� s1 ��Ԫ�ز�Ϊ��ʱ����������� s2 ��
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}

	//��ջ s2 Ϊ��ʱ��ֱ�ӷ��ؿ�
	if (s2.empty())
		return NULL;

	//ȡ�� s2 ��ջ��Ԫ��
	T temp = s2.top();
	s2.pop();
	return temp;
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
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	Test(head, 'a');

	head = queue.deleteHead();
	Test(head, 'b');

	queue.appendTail('d');
	head = queue.deleteHead();
	Test(head, 'c');

	queue.appendTail('e');
	head = queue.deleteHead();
	Test(head, 'd');

	head = queue.deleteHead();
	Test(head, 'e');

	return 0;
}