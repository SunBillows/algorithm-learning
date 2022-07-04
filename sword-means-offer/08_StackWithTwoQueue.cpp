//面试题7(改)：用两个队列实现栈
//用两个队列实现栈。栈的声明如下，请实现它的两个函数 appendTail 和 deleteHead，
//分别完成在栈顶完成插入删除操作
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

//构造函数
template<typename T>
CStack<T>::CStack(void)
{

}

//析构函数
template<typename T>
CStack<T>::~CStack(void)
{

}

//插入元素
template<typename T>
void CStack<T>::appendTail(const T& data)
{
	q1.push(data);
}

//弹出元素
template<typename T>
T CStack<T>::deleteHead()
{
	//当 q1 为空时，将 q2 中的数移动到 q1 并留下最后一个数
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