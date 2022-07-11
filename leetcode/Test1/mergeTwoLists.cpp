//题目描述：21.合并两个有序链表
/*
	将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

	示例1：
		输入：l1 = [1,2,4], l2 = [1,3,4]
		输出：[1,1,2,3,4,4]
		
	示例 2：
		输入：l1 = [], l2 = []
		输出：[]
		
	示例 3：
		输入：l1 = [], l2 = [0]
		输出：[0]
*/

//解题思路：
/*
	首先找到两个有序链表中的头结点中的数值较小的头结点作为新的头结点 pre
	然后遍历两个链表，将 pre->next 指向较小的那个结点，然后以此进行一次次的遍历，直接结束
*/


 Definition for singly-linked list.
 struct ListNode 
 {
 	int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1 == NULL || list2 == NULL)
        {
            return list1 == NULL ? list2 : list1;
        }

        //将头结点的数值小的数设置为新的头结点
        ListNode* head = list1->val >= list2->val ? list2 : list1;
        ListNode* pre = head;
        ListNode* cur1 = pre->next;
        ListNode* cur2 = head == list1 ? list2 : list1;

        while(cur1 && cur2)
        {
            if(cur1->val > cur2->val)
            {
                pre->next = cur2;
                cur2 = cur2->next;
            }
            else
            {
                pre->next = cur1;
                cur1 = cur1->next;
            }
            pre = pre->next;
        }
        
        pre->next = cur1 == NULL ? cur2 : cur1;

        return head;
    }
};

