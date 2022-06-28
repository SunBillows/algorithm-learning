//题目描述：628. 三个数的最大乘积
/*
	给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
*/

//解题思路：
/*
	对数组进行排序，三个数的乘积最大值有两种情况，一种是全为正数或全为数组，最大的乘积就是数组最后三个数的乘积；第二种是有负有正，最小的两个负数的乘积与最大的正数乘积之和；
	用两个方式求出乘积，取最大的那个数就是三个数的最大乘积
*/

class Solution 
{
public:
    int maximumProduct(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size() - 1;

        return max(nums[0] * nums[1] * nums[n] , nums[n] * nums[n - 1] * nums[n - 2]);   
    }
};