//题目描述: 105、从前序与中序遍历序列构造二叉树
/*
	给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

	示例1：
		输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
		输出: [3,9,20,null,null,15,7]

	示例2：
		输入: preorder = [-1], inorder = [-1]
		输出: [-1]
*/

class Solution 
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int sizePre = preorder.size();
        int sizeIn = inorder.size();

        if(preorder.empty() || inorder.empty() ||sizePre != sizeIn)
            return NULL;

        return constructTree(preorder,0,sizePre - 1,inorder,0,sizeIn - 1);;
    }

    TreeNode* constructTree(vector<int>& preorder,int left1,int right1,vector<int>& inorder,int left2,int right2)
    {
        if(left1 > right1)
            return NULL;

        //首先创建头结点
        TreeNode* root = new TreeNode(preorder[left1]);

		//当该区间只有一个数时，直接返回该结点
        if(left1 == right1)
        {
            return root;
        }

        int index = left2;
        //找到中序数组中根节点的位置
        for(int i = left2;i <= right2;i++)
        {
            if(inorder[i] == preorder[left1])
            {
                index = i;
            }
        }

		//进行递归补全该树
        root->left = constructTree(preorder , left1 + 1 , left1 + index - left2 , inorder , left2 , index - 1);
        root->right = constructTree(preorder , left1 + index - left2 + 1 , right1 , inorder , index + 1 , right2);

		//将补全的树的根节点返回
        return root;
    }
};

