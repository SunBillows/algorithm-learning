//题目描述：两个数组的交集 II
/*
	给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
*/


//解题思路1：
/*
	方法一：哈希表
	由于同一个数字在两个数组中都可能出现多次，因此需要用哈希表存储每个数字出现的次数。对于一个数字，其在交集中出现的次数等于该数字在两个数组中出现次数的最小值。

	首先遍历第一个数组，并在哈希表中记录第一个数组中的每个数字以及对应出现的次数，然后遍历第二个数组，对于第二个数组中的每个数字，如果在哈希表中存在这个数字，则将该数字添加到答案，
	并减少哈希表中该数字出现的次数。

	为了降低空间复杂度，首先遍历较短的数组并在哈希表中记录每个数字以及对应出现的次数，然后遍历较长的数组得到交集。
*/

//解题思路2：
/*
	方法二：排序 + 双指针
	如果两个数组是有序的，则可以使用双指针的方法得到两个数组的交集。

	首先对两个数组进行排序，然后使用两个指针遍历两个数组。

	初始时，两个指针分别指向两个数组的头部。每次比较两个指针指向的两个数组中的数字，如果两个数字不相等，
	则将指向较小数字的指针右移一位，如果两个数字相等，将该数字添加到答案，并将两个指针都右移一位。当至少有一个指针超出数组范围时，遍历结束。
*/

class Solution
{
public:
	vector<int> intersect_1(vector<int>& nums1, vector<int>& nums2)
	{
		//为了降低空间复杂度，首先遍历较短的数组并在哈希表中记录每个数字以及对应出现的次数，然后遍历较长的数组得到交集。
		if(nums1.size() > nums2.size())
		{
			return intersect_1(nums2,nums1);
		}

		//构建哈希表，key为数组出现的元素，value为该元素在数组中出现的个数
		unordered_map<int,int> map;
		
		//将较短数组中的元素进行遍历放入到哈希表中
		for(auto x : nums1)
		{
			++map[x];
		}

		vector<int> v;
		//再遍历较长数组，每出现一个和另一个数组相交的元素，便插入到数组中，且哈希表中该 key 位置的 value 减 1
		for(auto i : nums2)
		{
			//如果在 map 中能找到该值，则该 key 的 value 减1，并插入到新数组中
			if(map.count(i) && map[i]-- > 0)
			{
				v.push_back(i);
			}
		}
		return v;
	}

	vector<int> intersect_2(vector<int>& nums1, vector<int>& nums2)
	{
		sort(nums1.begin(),nums1.end());
		sort(nums2.begin(),nums2.end());

        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        vector<int> v;
        while(it1 != nums1.end() && it2 != nums2.end())
        {
            if(*it1 < *it2)
            {
                it1++;
            }
            else if(*it1 == *it2)
            {
                v.push_back(*it1);
                it1++;
                it2++;
            }
            else
            {
                it2++;
            }
        }
        return v;
	}
}


//独立完成代码
class Solution 
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> map1,map2;

        for(auto x : nums1)
        {
            ++map1[x];
        }

        for(auto i : nums2)
        {
            ++map2[i];
        }

        return getIntersect(map1,map2);
    }

    vector<int> getIntersect(unordered_map<int,int> map1,unordered_map<int,int> map2)
    {
        if(map1.size() > map2.size())
        {
            return getIntersect(map2,map1);
        }

        vector<int> v;
        for(auto [i,j] : map1)
        {
            //当哈希表2 中有关键字j 时
            if(map2.count(i))
            {
                //将该关键字插入到数组中，
                for(int k = 0;k < min(map1[i],map2[i]); k++)
                {
                    v.push_back(i);
                }
            }
        }
        return v;
    }
};