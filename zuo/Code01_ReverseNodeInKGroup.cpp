//��Ŀ��K�����������������
/*
	����һ���������ͷ��� head ����һ������ k
	ʵ�� k ������С���ڲ�����������һ�鲻�� k ���Ͳ�����
	���ӣ�
		����ǰ��1->2->3->4->5->6->7->8->NULL, k = 3
		������3->2->1->6->5->4->7->8->NULL
*/

#include <iostream>
using namespace std;

typedef struct Node
{
	int value;
	struct Node* next;
}ListNode;


//����д��һ���������ҵ� k Group �е�ĩβ���
ListNode* GetKGroupEnd(ListNode* start, int k)
{
	while(--k != 0 && start != NULL)
	{
		start = start->next;
	}
	return start;
}

//��д��һ�����������ڷ�ת k Group �е�Ԫ��
void reverse(ListNode* start, ListNode* end)
{
	end = end->next;

	//��������ķ�ת
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

	//�����һ������δ���� k ��Ԫ�أ���ֱ�ӷ��ظ������ͷ���
	if (end == NULL)
		return head;

	//��ת��һ����������������ͷ�����и���
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