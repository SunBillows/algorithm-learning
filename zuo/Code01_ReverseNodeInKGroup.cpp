//题目：K个结点的组内逆序调整
/*
	给定一个单链表的头结点 head ，和一个正数 k
	实现 k 个结点的小组内部逆序，如果最后一组不够 k 个就不调整
	例子：
		调整前：1->2->3->4->5->6->7->8->NULL, k = 3
		调整后：3->2->1->6->5->4->7->8->NULL
*/

#include <iostream>
using namespace std;

typedef struct Node
{
	int value;
	struct Node* next;
}ListNode;


//首先写出一个函数，找到 k Group 中的末尾结点
ListNode* GetKGroupEnd(ListNode* start, int k)
{
	while(--k != 0 && start != NULL)
	{
		start = start->next;
	}
	return start;
}

//再写出一个函数，用于反转 k Group 中的元素
void reverse(ListNode* start, ListNode* end)
{
	end = end->next;

	//进行链表的反转
	ListNode* pre = NULL;
	ListNode* cur = start;
	ListNode* next = NULL;
	while (cur != end)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	start->next = end;
}


ListNode* reverseKGroup(ListNode* head, int k)
{
	ListNode* start = head;
	ListNode* end = GetKGroupEnd(start, k);

	//如果第一组数据未满足 k 个元素，则直接返回该链表的头结点
	if (end == NULL)
		return head;

	//反转第一组链表，并将该链表头结点进行更改
	head = end;
	reverse(start, end);
	ListNode * lastEnd = start;
	while (lastEnd->next != NULL)
	{
		start = lastEnd->next;
		end = GetKGroupEnd(start, k);
		if (NULL == end)
			return head;
		reverse(start, end);
		lastEnd->next = end;
		lastEnd = start;
	}
	return head;
}

int main()
{
}