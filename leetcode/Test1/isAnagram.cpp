//题目描述：
/*
	给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
	注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
*/

//解题思路1：
/*
	t 是 s 的异位词等价于「两个字符串排序后相等」。
	因此我们可以对字符串 ss 和 tt 分别排序，看排序后的字符串是否相等即可判断。
	此外，如果 ss 和 tt 的长度不同，tt 必然不是 ss 的异位词。
*/

//解题思路2：
/*
	
*/

class Solution 
{
public:
    bool isAnagram_1(string s, string t) 
    {
        //1、排序法

        //当两个字符串长度不相等时，返回 false
        if(s.size() != t.size())
            return false;

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s == t;

   }

	bool isAnagram_2(string s, string t) 
    {
        //2、哈希表法
        if(s.length() != t.length())
            return false;

        //建立哈希表
        unordered_map<char ,int> map;

        //遍历字符串，将字符串 s 中的字符放入哈希表中
        for(auto ch : s)
        {
        	//key 为存储的字符类型，没存放相同类型的字符，value 便 +1
            ++map[ch];
        }
		//遍历字符串，将字符串 t 中的字符与哈希表中的相同字符进行对比
        for(auto ch : t)
        {
        	//当 key 值相同时，value 值 -1 。
            --map[ch];
        }
		//最后遍历整个哈希表，若其中有个key中的value不为零，则表示该两个数组不是有效的字母异位词
        for(auto it = map.begin();it!=map.end();it++)
        {
            if((*it).second != 0)
                return false;
        }
        return true;
   }
};

