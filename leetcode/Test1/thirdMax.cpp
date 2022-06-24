//题目描述：第三大的数
/*
	给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
*/

//解题思路1：
/*
	利用 set ，将数组中的元素插入到 set 中，然后知道倒数第三个数就是第三大的数
*/

class Solution 
{
public:
    int thirdMax_1(vector<int>& nums) 
    {
        set<int> set;
        for(auto x : nums)
        {
            if(!set.count(x))
                set.insert(x);
        }

        int n = set.size();
        auto it = set.begin();
        if(n >= 3)
        {
            for(int i = 0;i < n-3;i++)
                it++;
        }
        else if(n == 2)
        {
            it++;
        }

        return *it;
    }

	//优化
	int thirdMax(vector<int>& nums) 
    {
        //创建一个有序集合
        set<int> set;

        //遍历数组，取得数组中的每个元素
        for(int x : nums)
        {
            //将各元素插入到有序集合中
            set.insert(x);
            //当有序集合中的元素超过3个元素时，删除第一个元素
            if(set.size() > 3)
            {
                set.erase(set.begin());
            }
        }

        return set.size() == 3 ? *set.begin() : *set.rbegin();
    }
};

