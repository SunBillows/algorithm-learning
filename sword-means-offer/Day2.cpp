#include <iostream>
#include <vector>
#include <stack>
#include <time.h>
using namespace std;

//������Ķ���
typedef struct ListNode
{
	int m_Value;
	struct ListNode* m_pNext;
}ListNode;

//����������ӽ��
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

//��ӡ��������
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


//���������������A1 A2,�ڴ��� A1 ��ĩβ���㹻��Ŀ���ռ����� A2 ����ʵ��һ���������� A2 �е��������ֲ��뵽 A1 �в����������ֶ��������
void MergeArray(int arr1[], int arr2[],int sizearr1,int sizearr2)
{
	int MergeIndex = sizearr1 + sizearr2;
	//������������������һ�������ѱ�������ǰ���λ�������ѭ��
	while (sizearr1 > 0 && sizearr2 > 0)
	{
		//�������1�����һ����С������2�����һ����
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




//������5������һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ

//��ת����ķ�ʽ
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
//����ջ�ķ�ʽʵ�ַ�ת��ӡ
void ReverseListPrint_2(ListNode* pHead)
{
	//����һ��ջ
	stack<int> st;
	ListNode* cur = pHead;
	//��������б�����ÿ����һ�����ݾͽ������ջ��
	while (cur)
	{
		st.push(cur->m_Value);
		cur = cur->m_pNext;
	}
	//�����ջ��Ϊ�գ��򵯳�ջ��Ԫ��
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



//������6���ؽ�������������ĳ��������ǰ���������������Ľ�������ؽ����ö�������
//���������ǰ���������������Ľ���ж������ظ������֡�
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