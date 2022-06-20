//题目描述：
/*
删除给出链表中的重复元素（链表中元素从小到大有序），使链表中的所有元素都只出现一次
例如：
给出的链表为1→1→2,返回1→2.
给出的链表为1→1→2→3→3,返回1→2→3.
*/

//解题思路：
/*
遍历删除
核心思想：
        遍历链表，并判断当前节点值是否与下一个节点值相等。当前节点值与下一个节点值相等则直接删除下一个节点值；否则指针继续后移，直到遍历完成。
边界条件：空链表或者只有一个节点的链表直接返回
循环条件：当前节点存在下一个节点时（因为每次循环都需要将当前节点与下一个节点相比较）
*/

ListNode* deleteDuplicates(ListNode* head) 
{
	//当该链表为NULL或者该链表只有一个结点时，直接返回头结点
    if(head == NULL || head->next == NULL)
		return head;
        
    //创建两个指针
    ListNode* pre = head;
    ListNode* cur = head->next;
        
    //对链表进行遍历
    while(cur)
    {
    	//当两数相等时，后面的指针指向后面一个结点并和前面的结点再次进行比较
        if(pre->val == cur->val)
        {
            pre->next = cur->next;
            cur = cur->next;
        }
        //当两数不相等时，两个指针都向后移动重新比较
        else
        {
            pre = pre->next;
            cur = cur->next;
        }
    }
        return head;
}
