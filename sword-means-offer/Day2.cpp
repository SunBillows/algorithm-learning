#include <iostream>
#include <vector>
#include <stack>
#include <time.h>
using namespace std;

//链表结点的定义
typedef struct ListNode
{
	int m_Value;
	struct ListNode* m_pNext;
}ListNode;

//在链表中添加结点
void AddToTail(ListNode** pHead,int value)
{
	ListNode* pNode = new ListNode;
	pNode->m_Value = value;
	pNode->m_pNext = NULL;

	if (*pHead == NULL)
		* pHead = pNode;
	else
	{
		ListNode* cur = *pHead;
		while (cur->m_pNext)
		{
			cur = cur->m_pNext;
		}
		cur->m_pNext = pNode;
	}
}

//打印链表各结点
void PrintListNode(ListNode* pHead)
{
	ListNode* cur = pHead;
	while (cur)
	{
		cout << cur->m_Value << "->";
		cur = cur->m_pNext;
	}
	cout << "NULL";
}


//有两个排序的数组A1 A2,内存在 A1 的末尾有足够多的空余空间容纳 A2 。请实现一个函数，把 A2 中的所有数字插入到 A1 中并且所有数字都是排序的
void MergeArray(int arr1[], int arr2[],int sizearr1,int sizearr2)
{
	int MergeIndex = sizearr1 + sizearr2;
	//当两个数组中有其中一个数组已遍历至最前面的位置则结束循环
	while (sizearr1 > 0 && sizearr2 > 0)
	{
		//如果数组1的最后一个数小于数组2的最后一个数
		if (arr1[sizearr1 - 1] < arr2[sizearr2 - 1])
		{
			arr1[MergeIndex - 1] = arr2[sizearr2 - 1];
			sizearr2--;
			MergeIndex--;
		}
		else
		{
			arr1[MergeIndex - 1] = arr1[sizearr1 - 1];
			sizearr1--;
			MergeIndex--;
		}
	}
	if (sizearr1 > 0)
	{
		for (int i = sizearr1; i >= 0; i--)
		{
			arr1[MergeIndex - 1] = arr1[i - 1];
			MergeIndex--;
		}
	}
	if (sizearr2 > 0)
	{
		for (int i = sizearr2; i >= 0; i--)
		{
			arr1[MergeIndex - 1] = arr1[i - 1];
			MergeIndex--;
		}
	}
}

void test1()
{
	int arr1[20] = { 1,4,5,6,9,22 };
	int arr2[10] = { 2,6,7,12,13,20 };
	MergeArray(arr1, arr2, 6, 6);
	for (int i = 0; i < 12; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;
}




//面试题5：输入一个链表的头结点，从尾到头反过来打印出每个结点的值

//反转链表的方式
void ReverseListPrint_1(ListNode** pHead)
{
	if (pHead == NULL || *pHead == NULL)
		return;

	ListNode* pre = NULL;
	ListNode* cur = *pHead;
	while (cur)
	{
		ListNode* next = cur->m_pNext;
		cur->m_pNext = pre;
		pre = cur;
		cur = next;
	}
	*pHead = pre;
}
//利用栈的方式实现反转打印
void ReverseListPrint_2(ListNode* pHead)
{
	//创建一个栈
	stack<int> st;
	ListNode* cur = pHead;
	//对链表进行遍历，每遍历一个数据就将其插入栈中
	while (cur)
	{
		st.push(cur->m_Value);
		cur = cur->m_pNext;
	}
	//如果该栈不为空，则弹出栈顶元素
	while(!st.empty())
	{
		cout << st.top() << "->";
		st.pop();
	}
	cout << "NULL";
}

void test2()
{
	ListNode* pHead = NULL;
	for (int i = 0; i < 10; i++)
	{
		AddToTail(&pHead, rand()%20 + 1);
	}
	//AddToTail(&pHead, rand() % 20 + 1);
	PrintListNode(pHead);

	cout << endl;
	ReverseListPrint_1(&pHead);
	PrintListNode(pHead);

	cout << endl;
	ReverseListPrint_2(pHead);
	
}



//面试题6：重建二叉树。输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
//假如输入的前序遍历和中序遍历的结果中都不含重复的数字。
typedef struct BinaryTree
{
	int m_Value;
	BinaryTree* m_pLeft;
	BinaryTree* m_pRight;
}BTnode;


int main()
{
	srand((unsigned int)time(NULL));
	//test1();
	test2();

	return 0;
}