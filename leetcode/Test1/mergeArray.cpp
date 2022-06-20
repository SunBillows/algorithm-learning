//题目描述：
/*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，
应忽略。nums2 的长度为 n 。
*/

//解题思路1：
/*
方法1：双指针
算法
为了利用这一性质，我们可以使用双指针方法。这一方法将两个数组看作队列，每次从两个数组头部取出比较小的数字放到结果中。
将结果中的数组放入数组1中
*/

//解题思路2：
/*
方法2：逆向双指针
方法1中，之所以要使用临时变量，是因为如果直接合并到数组nums1中，nums1中的元素可能会在取出之前被覆盖。那么如何直接避免覆盖nums1中的元素呢？观察可知，nums1的后半部分是空的，
可以直接覆盖而不会影响结果。因此可以指针设置为从后向前遍历，每次取两者之中的较大者放进nums1的最后面。
*/


class Solution
{
public:
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        //创建一个存储数组
        int arr[m + n];
        int p1 = 0,p2 = 0;
        int cur;

        //遍历整个数组，将两个数组中小的数放入新创建的数组中
        while(p1 < m || p2 < n)
        {
        	//当数组2已经遍历完全时，将数组1中剩余的数赋值至新数组中
            if(p2 == n)
            {
                cur = nums1[p1];
                p1++;
            }
			//当数组1中的当前数大于等于数组2中的当前数时，将数组2中的当前数赋值至新数组中
            else if(nums1[p1] >= nums2[p2])
            {
                cur = nums2[p2];
                p2++;
            }
			//当数组1已经遍历完全时，将数组2中剩余的数赋值至新数组中
            else if(p1 == m)
            {
                cur = nums2[p2];
                p2++;
            }
            else
            {
                cur = nums1[p1];
                p1++;
            }

            arr[p1 + p2 - 1] = cur;
        }

        //将新创建的数组中的数存放至num1中
        for(int i = 0 ; i != m+n;i++)
        {
            nums1[i] = arr[i];
        }
    }


	void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
    	//逆向双指针
        int p1 = m - 1 , p2 = n - 1;
        int last = m + n - 1;
        int cur;

        while(p1 >= 0 || p2 >= 0)
        {
            if(p1 < 0)
            {
                cur = nums2[p2];
                p2--;
            }
            else if(p2 < 0)
            {
                cur = nums1[p1];
                p1--;
            }
            else if(nums2[p2] > nums1[p1])
            {
                cur = nums2[p2];
                p2--;
            }
            else
            {
                cur = nums1[p1];
                p1--;
            }
            nums1[last--] = cur;
        }
    }
    	
	
};

