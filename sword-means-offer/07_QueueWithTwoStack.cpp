//面试题7：用两个栈实现队列
//用两个栈实现队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead，
//分别完成在队列尾部插入结点和在队列头部删除结点功能
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

//构造函数
template<typename T>
CQueue<T>::CQueue(void)
{
	
}

//析构函数
template<typename T>
CQueue<T>::~CQueue(void)
{

}

//插入函数
template<typename T>	
void CQueue<T>::appendTail(const T& data)
{
	this->s1.push(data);
}

//删除函数
template<typename T>
T CQueue<T>::deleteHead()
{
	//当 s2 为空时，将 s1 中的元素插入至 s2 中
	if (s2.empty())
	{
		//当 s1 中元素不为空时，将其插入至 s2 中
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}

	//当栈 s2 为空时，直接返回空
	if (s2.empty())
		return NULL;

	//取出 s2 的栈顶元素
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