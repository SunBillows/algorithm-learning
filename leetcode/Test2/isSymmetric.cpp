//题目描述：101、对称二叉树
/*
	给你一个二叉树的根节点 root ， 检查它是否轴对称。

	示例1：
		输入：root = [1,2,2,3,4,4,3]
		输出：true

	示例2：
		输入：root = [1,2,2,null,3,null,3]
		输出：false
*/

//解题思路：
/*
	递归：
		可以将一棵树看成两棵树来进行判断，如果一棵树的左子树与另一个棵树的右子树相同，则判断正确，调用递归进行对称树的判断

	迭代：
		首先我们引入一个队列，这是把递归程序改写成迭代程序的常用方法。初始化时我们把根节点入队两次。每次提取两个结点并比较它们的值（队列中每两个连续的结点应该是相等的，
		而且它们的子树互为镜像），然后将两个结点的左右子结点按相反的顺序插入队列中。当队列为空时，或者我们检测到树不对称（即从队列中取出两个不相等的连续结点）时，该算法结束。
*/


Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution 
{
public:

    bool isMirrorTree_1(TreeNode* left,TreeNode* right)
    {
    	//两个结点都为空，则说明该部分为对称结点
        if(left == NULL && right == NULL)
            return true;
        if(left == NULL ^ right == NULL)
            return false;

		//若该结点的值相同且左子树各结点和右子树各结点都为对称结点，则说明该树为对称树
        return left->val == right->val && isMirrorTree(left->left,right->right) &&isMirrorTree(left->right,right->left);
    }

	bool isMirrorTree_2(TreeNode* left,TreeNode* right)
    {
        queue<TreeNode*> queue;
        //先将两个根节点插入至队列中
        queue.push(left);
        queue.push(right);

        while(!queue.empty())
        {
            //找到即将出队列的结点
            TreeNode* x = queue.front();
            queue.pop();
            TreeNode* y = queue.front();
            queue.pop();
            
            //判断出栈的两个结点
            //若两个结点都为空，则跳出此次循环，进入下一个循环
            if(x == NULL && y == NULL)            
                continue;
            //若两个结点不相等，则直接返回false
            if(x == NULL ^ y == NULL || x->val != y->val) 
                return false;
            
            //插入出队列的结点的相反结点
            queue.push(x->left);
            queue.push(y->right);
            queue.push(x->right);
            queue.push(y->left);
        }
        return true;
    }
	

    bool isSymmetric(TreeNode* root) 
    {
        return isMirrorTree(root,root);
    }

};

