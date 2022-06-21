//题目描述：给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false。

//解题思路1：
/*
	先将数组进行排序，遍历数组，如果数组中相邻元素存在同样的值，则返回true，否则返回false
*/

//解题思路2：
/*
	利用哈希表：遍历数组中各元素，当哈希表中能查找到该元素时，返回true，并将该元素插入哈希表中；若数组遍历完成还没有找到相同元素，则返回false。
*/


class Solution 
{
public:
    bool containsDuplicate_1(vector<int>& nums) 
    {
        //采用先排序，再遍历的算法
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;

    }

	bool containsDuplicate_2(vector<int>& nums) 
    {
        //采用哈希表
        //创建一个哈希表
        unordered_set<int> set;
        //遍历数组
        for(int i = 0 ; i < nums.size() ; i++)
        {
            //如果能在哈希表中找到该值，则说明该数组存在重复元素
            if(set.find(nums[i]) != set.end())					//该语句的意思是：如果能找到该元素，则返回该元素所在迭代器位置，否则返回set.end();
                return true;

            //如果没有找到该值，则将该值插入哈希表中
            set.insert(nums[i]);
        }
        return false;
    }
};