//题目描述：两个数组的交集
/*
	给定两个数组 nums1 和 nums2 ，返回它们的交集 。输出结果中的每个元素一定是唯一的。我们可以不考虑输出结果的顺序 。
*/

//解题思路1：
/*
	遍历数组1 和数组2 ，将数组1 中的各元素与数组2 中的各元素相比，若该元素与数组2 中的某个元素相等且哈希表中没有该元素，则将之插入新数组和哈希表中
	最后得到的结果就是两个数组的交集。
*/

//解题思路2：
/*
	在思路1 的基础上，分别遍历两个数组将其中的元素存放至两个哈希表中。
	在元素多的哈希表上查找元素少的哈希表上的值，若存在，则表示该元素相交，插入新数组中；若不存在则表示该元素不想交；
*/

//解题思路3；
/*
	
*/

class Solution 
{
public:
    vector<int> intersection_1(vector<int>& nums1, vector<int>& nums2) 
    {
        //1.利用哈希表
        unordered_set<int> set;
        vector<int> v;

        for(auto x : nums1)
        {
            for(auto i : nums2)
            {
                if(x == i && set.find(x) == set.end())
                {
                    v.push_back(x);
                    set.insert(x);
                }
            }
        }
        return v;
    }

	vector<int> intersection_2(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> set1,set2;
		
		for(auto x : nums1)
			set1.insert(x);
		
		for(auto i : nums2)
			set2.insert(i);

		return get_intersection_2(set1, set2);
    }

	vector<int> get_intersection_2(unordered_set<int>& set1, unordered_set<int>& set2 )
	{
		//如果set1 的元素比set2 的元素多，则两者互换
		if(set1.size() > set2.size())
		{
			return get_intersection_2(set2,set1);
		}

		vector<int> v;

		for(auto x : set1)
		{
			//若该元素在set2 上存在，则表示该元素是相交元素
			if(set2.count(x))
				v.push_back(x);
		}

		return v;
	}
};

