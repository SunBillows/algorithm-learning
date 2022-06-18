//题目描述

/*
给定一个链表，请判断该链表是否为回文结构。
回文是指该字符串正序逆序完全一致。
*/

struct ListNode 
{
	int val;
 	struct ListNode *next;
};


//解题思路1：数组复制反转法
/*
即然回文结构正序遍历和逆序遍历结果都是一样的，我们是不是可以尝试将正序遍历的结果与逆序遍历的结果一一比较，如果都是对应的，那很巧了！它就是回文结构！
这道题看起来解决得如此之快，但是别高兴太早，链表可没有办法逆序遍历啊。链表由前一个节点的指针指向后一个节点，指针是单向的，只能从前面到后面，我们不能任意访问，也不能从后往前。
但是，另一个容器数组，可以任意访问，我们把链表中的元素值取出来放入数组中，然后判断数组是不是回文结构，这不是一样的吗？
*/

bool isPail_1(ListNode* head)
{
	//当该链表为空或者该链表只有一个元素时，该链表是回文结构
	if(head == NULL || head->next ==NULL)
		return true;
	
	vector<int> ans;
	//将链表元素复制至数组中
	while(head)
	{
		ans.push_back(head->val);
		head = head->next;
	}

	//创建一个临时数组，并反转
	vector<int> temp = ans;
	reverse(temp.begin(),temp.end());

	//再遍历两个数组，相同则返回true，不同则返回false
	for(int i = 0;i < ans.size(); i++)
	{
		if(ans[i] != temp[i])
			return false;
	}
	return true;
	
}

//解题思路2：数组复制双指针
/*
知识点：双指针
双指针指的是在遍历对象的过程中，不是普通的使用单个指针进行访问，而是使用两个指针（特殊情况甚至可以多个），两个指针或是同方向访问两个链表、
或是同方向访问一个链表（快慢指针）、或是相反方向扫描（对撞指针），从而达到我们需要的目的。

思路：
既然方法一我们已经将链表的值放入了数组中，数组是可以按照下标直接访问的，那干啥还要傻乎乎地用另一个数组来表示反转后的数组呢？
我们直接从后往前遍历与从前往后遍历一同比较，利用两个指针对撞访问，不就少了很多额外的时间了吗？
*/

bool isPail_2(ListNode* head) 
{
	if(head == NULL || head->next == NULL)
		return true;
	vector<int> v;
	while(head)
	{
		v.push_back(head->val);
		head = head->next;
	}
	//创建两个指针，分别指向数组的头部和尾部
	int *cur1 = &v[0],*cur2 = &v[v.size()-1];

	//当cur1指针小余cur2指针时，进入循环
	while(cur1 < cur2)
	{
		//两个指针指向的值不相同时，证明该结构不是回文结构，返回false
		if(*cur1 != *cur2)
			return false;
		cur1++;
		cur2--;
	}
	return true;
}

//解题思路3：反转链表双指针
/*
可以使用快慢指针，快指针的速度为慢指针的两倍，当快指针到达链表尾部时，慢指针到达中间位置，将中间结点之后的部分进行反转，再与前半部分通过双指针进行比较。
*/

//创建链表反转函数
class Solution 
{
public:
    //反转链表函数
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        while(head != NULL)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    bool isPail_3(ListNode* head) 
    {
        //使用快慢指针找到链表的中点
        ListNode* slow = head,*fast = head;
        while(fast->next != NULL && fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
		
        //循环遍历结束，找到链表的中间结点slow;
        ListNode* ans = reverseList(slow);
        while(ans)
        {
            if(ans->val != head->val)
                return false;
            ans = ans->next;
            head = head->next;
        }
        return true;
    }
};