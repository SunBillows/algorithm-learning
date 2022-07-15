//题目描述：102、二叉树的层序遍历
/*
	给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

	示例1：
	输入：root = [3,9,20,null,null,15,7]
	输出：[[3],[9,20],[15,7]]

	示例 2：
	输入：root = [1]
	输出：[[1]]

	示例 3：
	输入：root = []
	输出：[]
*/

//解题思路：
/*
	广度优先搜索：
		步骤1：首先创建一个队列，将根节点入队，找到队列的大小，并进行步骤二操作size次
		步骤2：弹出头结点，将头结点的子结点进行入队操作，将弹出的头结点插入vector数组中
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        //创建一个队列
        queue<TreeNode*> q;

        //首先将根节点入队
        q.push(root);

        //当队列不为空时，进入循环
        while(!q.empty())
        {
            //首先找到队列的大小
            int size = q.size();
            //队列中有多少数据，则进行多少次以下操作
            vector<int> v;
            while(size--)
            {
                //先将队首元素的不为空的子节点入队
                if(q.front()->left != NULL)
                    q.push(q.front()->left);
                if(q.front()->right != NULL)
                    q.push(q.front()->right);
                //再将队首结点的元素插入到数组中
                v.push_back(q.front()->val);
                //最后弹出队首元素
                q.pop();
            }
            ans.push_back(v);
        }
        return ans;
    }
};

