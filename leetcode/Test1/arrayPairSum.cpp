//题目描述：数组拆分 I
/*
	给定长度为 2n 的整数数组 nums ，你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从 1 到 n 的 min(ai, bi) 总和最大。
	返回该 最大总和 。
*/

//解题思路：
/*
	我们先对数组进行排序。
	由于每两个数，我们只能选择当前小的一个进行累加。
	因此我们猜想应该从第一个位置进行选择，然后隔一步选择下一个数。这样形成的序列的求和值最大。
*/

class Solution 
{
public:
    int arrayPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int ans = 0;

        for(int i = 0;i < nums.size();i += 2)
        {
            ans += nums[i];
        }
        return ans;
    }
};