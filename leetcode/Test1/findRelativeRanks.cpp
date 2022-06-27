//题目描述：相对名词
/*
	给你一个长度为 n 的整数数组 score ，其中 score[i] 是第 i 位运动员在比赛中的得分。所有得分都 互不相同 。
	运动员将根据得分 决定名次 ，其中名次第 1 的运动员得分最高，名次第 2 的运动员得分第 2 高，依此类推。运动员的名次决定了他们的获奖情况：

	名次第 1 的运动员获金牌 "Gold Medal" 。
	名次第 2 的运动员获银牌 "Silver Medal" 。
	名次第 3 的运动员获铜牌 "Bronze Medal" 。
	从名次第 4 到第 n 的运动员，只能获得他们的名次编号（即，名次第 x 的运动员获得编号 "x"）。
	
	使用长度为 n 的数组 answer 返回获奖，其中 answer[i] 是第 i 位运动员的获奖情况。
*/

//解题思路1：
/*
	除了使用 HashMap 以外，还有种巧妙的方法（挺常用），就是把元素和下标放在一个 pair 里，在排序之后， pair 的第一个值就是数组中的元素， 
	pair 的第二个值就是其在原数组中的下标。
​

	这种方法常用于保存元素出现的位置，当顺序打乱的时候，仍能找到每个元素的原始下标。
*/

class Solution 
{
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
    	//定义一个字符串数组
        string str[3] = {"Gold Medal","Silver Medal","Bronze Medal"};

		//创建一个数组用于存储运动员所得的分数以及其所在数组的下标位置
        vector<pair<int,int>> v;

        int size = score.size();

		//遍历数组 score 将该数组的元素及下标按顺序插入到数组 v 中
        for(int i = 0;i<size;i++)
        {
            v.push_back(make_pair(score[i],i));
        }

		//对数组 v 按照 first 进行从大到小的排序
        sort(v.begin(),v.end(),greater());

		//创建一个 string 类型的数组用于存放成绩信息
        vector<string> vec(size);

        for(int j = 0;j < size;j++)
        {
        	//当遍历到数组 v 的第三个元素后的位置时
            if(j > 2)
            {
                vec[v[j].second] = to_string(j+1);
            }
            else
            {
                vec[v[j].second] = str[j];
            }
        }
        return vec;
    }
};

