//题目描述：链表中两数相加
/*
	给定两个 非空链表 l1和 l2 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
	可以假设除了数字 0 之外，这两个数字都不会以零开头。

	示例：
		示例1：
		输入：l1 = [2,4,3], l2 = [5,6,4]
		输出：[8,0,7]

		示例3：
		输入：l1 = [0], l2 = [0]
		输出：[0]
*/

//解题思路1：
/*
	首先反转两个链表，然后从第一个结点开始相加，若有进位则进位标志位置 1 ；若最后一个结点相加结束后进位为 1 ；则新增一个结点用于保存进位；
*/

//解题思路2：
/*
	利用栈：
		先将两个链表元素压入两个栈中，然后对两个栈顶元素进行相加，将结果保存在新建的链表中，直至两个栈为空，且进位标志为 0 ；
		
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
    ListNode* addTwoNumbers_1(ListNode* l1, ListNode* l2) 
    {
        int len1 = ListLength(l1);
        int len2 = ListLength(l2);

        ListNode* head1 = len1 >= len2 ? l1 : l2;
        ListNode* head2 = head1 ==  l1 ? l2 : l1;

        //首先反转两个链表
        head1 = Reverse(head1);
        head2 = Reverse(head2);

        //再存储当前的两个头结点
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;
        ListNode* last = cur1;

        //设置进位标志
        int flag = 0;
        int sum = 0;

        //进行遍历相加操作
        while(cur2 != NULL)
        {
            //先求出两个结点和进位标志相加后的数据
            sum = cur1->val + cur2->val + flag;
            cur1->val = sum % 10;
            flag = sum / 10;
            last = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        while(cur1 != NULL)
        {
            sum = cur1->val + flag;
            cur1->val = sum % 10;
            flag = sum / 10;
            last = cur1;
            cur1 = cur1->next;
        }

        if(flag != 0)
        {
            last->next = new ListNode(1);
        }

        return Reverse(head1);
    }

    //反转链表函数
    ListNode* Reverse(ListNode* head)
    {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* next = NULL;
        while(cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    //求出链表长度
    int ListLength(ListNode* head)
    {
        int count  = 0;
        while(head)
        {
            head = head->next;
            count++;
        }
        return count;
    }


	ListNode* addTwoNumbers_2(ListNode* l1, ListNode* l2) 
		{
			//定义两个栈
			stack<int> s1;
			stack<int> s2;
	
			//进行压栈操作
			while(l1)
			{
				s1.push(l1->val);
				l1 = l1->next;
			}
			while(l2)
			{
				s2.push(l2->val);
				l2 = l2->next;
			}
	
			int carry = 0;
			ListNode* ans = NULL;
			while(!s1.empty() || !s2.empty() || carry != 0)
			{
				int s1num = s1.empty() ? 0 : s1.top();
				int s2num = s2.empty() ? 0 : s2.top();
				if(!s1.empty())
					s1.pop();
				if(!s2.empty())
					s2.pop();
	
				int sum = s1num + s2num + carry;
				carry = sum / 10;
				ListNode* temp = new ListNode(sum % 10);
				temp->next = ans;
				ans = temp;
			}
	
			 return ans;
		}

	
};


