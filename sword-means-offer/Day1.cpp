#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
using namespace std;

//面试题1：赋值运算符函数
//如下为类型 CMyString 的声明，请为该类型添加赋值运算符函数

class CMyString
{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	CMyString& operator=(const CMyString& str);
	~CMyString(void);

private:
	char* m_pData;
};



CMyString& CMyString::operator=(const CMyString& str)
{
	//判断该对象是否是所需赋值的类本身
	if(this == &str)
	{
		return *this;
	}

	//判断该实例是否含有空间，有的话则进行释放
	if(this != NULL)
	{
		delete []m_pData;
		m_pData = NULL;
	}

	//为该类开辟内存空间
	this->m_pData = new char[strlen(str.m_pData) + 1];

	//进行赋值
	strcpy(m_pData,str.m_pData);
	
	return *this;
}





//面试题3：二维数组中的查找
//在一个二维数组中，每一行都按照从左到右递增的循序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数吗，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数

//该函数中，array 为传入此函数的二维数组，rows 为行数，columns 为列数，number 为需要查找的数
bool Find(int* array[],int rows,int columns,int number)
{
	if(array != NULL && rows > 0 && columns > 0)
	{
		int i = 0;
		int j = columns - 1;
		
		//当横坐标值大于rows - 1 或者纵坐标值小于 0 时
		while(i < rows - 1 && j >= 0)
		{
			//当右上角的数大于要查找的数时，删除该列
			if(array[i][j] > number)
			{
				j--;
			}
			//当右上角的数小于要查找的数时，删除该行
			else if(array[i][j] < number)
			{
				i++;
			}
			else
			{
				return true;
			}
		}
	}
	return false;	
}


//面试题4：替换空格
//请实现一个函数，把字符串中的每个空格替换成“%20”。例如输入“We are happy.”，则输出“We%20are%20happy.”。
void replaceblank(char* str,int length)
{
	int numberOfBlank = 0;		//该字符串中空格的数目
	char* cur = str;			//遍历指针

	//首先找到空格的个数
	while (*cur != '\0')
	{
		if (*cur == ' ')
			numberOfBlank++;
		cur++;
	}

	int OriginalLength = strlen(str);						//当前字符串的实际长度
	int newLength = OriginalLength + 2 * numberOfBlank;		//扩充后的新字符串长度

	//判断空间容量
	if (newLength > length)
		return;

	//创建两个指针，一个指向数组尾部，一个指向‘\0’处
	char* p1 = &str[OriginalLength];
	char* p2 = &str[newLength];
	
	while (p1 != p2)
	{
		//当 p1 指针没碰到空格时，将 p1 处的字符赋值到 p2 处
		if (*p1 != ' ')
		{
			*p2 = *p1;
			p2--;
			p1--;
		}
		//碰到空格后，则从 p2 处开始将 “%20” 赋值进 p2 位置
		else
		{
			*(p2--) = '0';
			*(p2--) = '2';
			*(p2--) = '%';
			p1--;
		}
	}
}

int main()
{
	char str[23] = " We are happy. ";
	int size = sizeof(str);
	replaceblank(str,size);
	cout << str << endl;

	return 0;
}