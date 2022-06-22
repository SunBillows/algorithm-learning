//题目描述：给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。

//解题思路1：
/*
	利用哈希表，将数组中的数插入到哈希表中。然后遍历 [0,n] ，查找哈希表中 [0,n] 中的数是否存在，若不存在则此数为丢失的数
*/

//解题思路2：
/*
	利用排序，将数组中的数进行排序，便利 [0,n] ，若该数组中的数与下标不匹配，则该下标则是丢失的数。遍历完成后，若没有出线丢失的数，则最后一个数为丢失的数
*/


//解题思路3：
/*
	利用数学知识，先求出[0,n]的总和 total，再求出数组的总和 sum，total - sum 就为丢失的数
*/


class Solution 
{
public:
    int missingNumber_1(vector<int>& nums) 
    {
    
        //1.哈希表
        int missing = -1;
        int size = nums.size();

        unordered_set<int> set;
        for(auto x : nums)
        {
            set.insert(x);
        }

        //便是哈希表找到数值为0的元素
        for(int i = 0;i <= size;i++)
        {
            if(set.find(i) == set.end())
            {
                missing = i;
            }
        }
        return missing;   
    }

	int missingNumber_2(vector<int>& nums) 
    {
    
        //2.排序
        int missing = -1;
        int size = nums.size();

        sort(nums.begin(),nums.end());
        for(int i = 0; i < size; i++)
        {
            if(nums[i] != i)
                return i;
        }
        return size;
    }

	int missingNumber_3(vector<int>& nums) 
    {
    
        //3.数学方法
        int size = nums.size();
		
        //总和
        int sum = size*(size + 1) / 2;
		
        //求数组和
        int arrsum = 0;
        for(auto x : nums)
        {
            arrsum += x;
        }

        return sum - arrsum;
    }
};

