//题目描述：23、合并 K 个升序链表
/*
	给你一个链表数组，每个链表都已经按升序排列。
	请你将所有链表合并到一个升序链表中，返回合并后的链表。

	示例 1：
	输入：lists = [[1,4,5],[1,3,4],[2,6]]
	输出：[1,1,2,3,4,4,5,6]

	示例 2：
	输入：lists = []
	输出：[]

	示例 3：
	输入：lists = [[]]
	输出：[]
*/

//解题思路：
/*
	利用优先队列，先将数组中的每个头结点插入到优先队列中，然后将顶部结点链接到最终的链表中。同时插入该结点指向的下一个结点到优先队列中
*/

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

    //重写仿函数，用来比较链表的各结点大小  -------实现链表的升序
    struct comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        //当这个数组里面没有值时，直接返回 NULL
        if(lists.size() == 0)
            return NULL;

        //创建一个优先队列
        priority_queue<ListNode*,vector<ListNode*>,comp> p;

        //将每个链表的第一个结点插入到优先队列中
        for(int i = 0;i < lists.size(); i++)
        {
            //当链表不为空时，则将该结点插入优先队列中
            if(lists[i] != NULL)
                p.push(lists[i]);
        }
        //如果优先队列为空，则返回 NULL
        if(p.empty())
            return NULL;

        //创建头结点为优先队列的头部结点
        ListNode* head = p.top();
        //创建一个迭代结点
        ListNode* pre = head;
        if(pre->next != NULL)
            p.push(pre->next);
        p.pop();

        //当优先队列中元素不为空时 
        while(!p.empty())
        {
            //得到顶部结点
            ListNode* cur = p.top();

            //若顶部结点的下一个结点不为空，则将下一个结点插入到优先队列中
            if(cur->next != NULL)
                p.push(cur->next);

            //将该顶部结点连接到最终链表中
            pre->next = cur;
            pre = cur;

            //将该结点 pop 出优先结点
            p.pop();
        }

        return head;
    }
};