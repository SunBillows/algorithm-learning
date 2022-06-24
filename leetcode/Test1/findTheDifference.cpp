//题目描述：找不同
/*
	给定两个字符串 s 和 t ，它们只包含小写字母。
	字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
	请找出在 t 中被添加的字母。
*/

//解题思路1：
/*
	先将两个字符串进行排序，然后通过迭代器访问每个字串，当两个字符串中存在不相同的字符时，此时字符串 t 中该位置的字符就是被添加的字符
*/

//解题思路2：
/*
	首先遍历字符串 ss，对其中的每个字符都将计数值加 11；然后遍历字符串 tt，对其中的每个字符都将计数值减 11。当发现某个字符计数值为负数时，
	说明该字符在字符串 tt 中出现的次数大于在字符串 ss 中出现的次数，因此该字符为被添加的字符。
*/


//解题思路3：
/*
	异或运算：定义一个整型，赋初值为 0；将其与两个字符串中的每个字符进行异或，最后找到出现奇数次的那个字符就是新加入的字符；
*/



class Solution 
{
public:
    char findTheDifference_1(string s, string t) 
    {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        auto it1 = s.begin();
        auto it2 = t.begin();

        while(it1 != s.end())
        {
            if(*it1 != *it2)
                return *it2;
            it1++;
            it2++;
        }
        return *it2;
    }

	char findTheDifference_2(string s, string t) 
    {
        vector<int> v(26,0);
        for(auto i : s)
        {
            v[i - 'a']++;
        }
        for(auto j : t)
        {
            if(--v[j - 'a'] < 0)
                return j;
        }
        return ' ';
    }

	char findTheDifference_3(string s, string t) 
    {
        int ret = 0;
        for(auto x : s)
            ret ^= x;

        for(auto x : t)
            ret ^= x;

        return ret;

    }
};

