//é¢è¯•é¢˜8ï¼šæ—‹è½¬æ•°ç»„çš„æœ€å°æ•°å­—
//æŠŠä¸€ä¸ªæ•°ç»„æœ€å¼€å§‹çš„è‹¥å¹²ä¸ªå…ƒç´ æ¬åˆ°æ•°ç»„çš„æœ«å°¾ï¼Œæˆ‘ä»¬ç§°ä¹‹ä¸ºæ•°ç»„çš„æ—‹è½¬ã€‚
//è¾“å…¥ä¸€ä¸ªé€’å¢çš„æ’åºæ•°ç»„çš„ä¸€ä¸ªæ—‹è½¬ï¼Œè¾“å‡ºæ—‹è½¬æ•°ç»„çš„æœ€å°å…ƒç´ 


#include <iostream>
using namespace std;

int FindMinNumInRotateArr(int* arr,int length)
{
	//ÕÒµ½×óÓÒ±ß½çÊı¾İµÄÊı×éÏÂ±ê left ºÍ right
	int left = 0;
	int right = length - 1;
	//³õÊ¼»¯ÖĞ¼ä½áµãÎª 0£»
	int mid = 0;

	//Ñ­»·ÅĞ¶ÏµÄ½áÊøÌõ¼şÎª×ó±ßÊı¾İ´óÓÚµÈÓÚÓÒ±ßÊı¾İ£¬Èô²»ÄÜÂú×ã´ËÌõ¼şÔòËµÃ÷´ËÇøÓòÎªµİÔöÇøÓò£¬Ö±½ÓÊä³ö×ó±ß½çÊı¾İ
	while (arr[left] >= arr[right])
	{
		//µ±Á½¸öÏÂ±êÏàÁÚÊ±£¬ÓÒ±ßµÄÏÂ±êËùÖ¸ÏòµÄÊı×éÔªËØÔòÎª×îĞ¡Öµ
		if (right - left == 1)
		{
			int mid = right;
			break;
		}

		mid = left + ((right - left) >> 1);
		//µ±ÈıÕßÏàµÈÊ±£¬ÔòĞèÒª²ÉÓÃË³Ğò²éÕÒ·½Ê½ÕÒµ½×îĞ¡Öµ
		if (arr[mid] == arr[left] && arr[mid] == arr[right])
		{
			int min = arr[left];
			for (int i = left; i <= right; i++)
			{
				if (arr[i] < min)
					min = arr[i];
			}
			return min;
		}
		//µ±ÖĞ¼äµÄÔªËØ´óÓÚµÈÓÚ×î×ó±ßÔªËØÊ±£¬ËµÃ÷[left£¬mid]ÇøÓòÄÚÎªµİÔöĞòÁĞÇÒ¶¼±È×îĞ¡Öµ´ó
		if (arr[mid] >= arr[left])
		{
			left = mid;
		}
		else if (arr[mid] <= arr[right])
		{
			right = mid;
		}
		
	}

	//×îºóÊä³öÕÒµ½µÄ×îĞ¡Öµ
	return arr[mid];
}

void Test(int* numbers, int length, int expected)
{
	int result = 0;
	try
	{
		result = FindMinNumInRotateArr(numbers, length);

		for (int i = 0; i < length; ++i)
			printf("%d ", numbers[i]);

		if (result == expected)
			printf("\tpassed\n");
		else
			printf("\tfailed\n");
	}
	catch (...)
	{
		if (numbers == nullptr)
			printf("Test passed.\n");
		else
			printf("Test failed.\n");
	}
}

int main(int argc, char* argv[])
{
	// µäĞÍÊäÈë£¬µ¥µ÷ÉıĞòµÄÊı×éµÄÒ»¸öĞı×ª
	int array1[] = { 3, 4, 5, 1, 2 };
	Test(array1, sizeof(array1) / sizeof(int), 1);

	// ÓĞÖØ¸´Êı×Ö£¬²¢ÇÒÖØ¸´µÄÊı×Ö¸ÕºÃµÄ×îĞ¡µÄÊı×Ö
	int array2[] = { 3, 4, 5, 1, 1, 2 };
	Test(array2, sizeof(array2) / sizeof(int), 1);

	// ÓĞÖØ¸´Êı×Ö£¬µ«ÖØ¸´µÄÊı×Ö²»ÊÇµÚÒ»¸öÊı×ÖºÍ×îºóÒ»¸öÊı×Ö
	int array3[] = { 3, 4, 5, 1, 2, 2 };
	Test(array3, sizeof(array3) / sizeof(int), 1);

	// ÓĞÖØ¸´µÄÊı×Ö£¬²¢ÇÒÖØ¸´µÄÊı×Ö¸ÕºÃÊÇµÚÒ»¸öÊı×ÖºÍ×îºóÒ»¸öÊı×Ö
	int array4[] = { 1, 0, 1, 1, 1 };
	Test(array4, sizeof(array4) / sizeof(int), 0);

	// µ¥µ÷ÉıĞòÊı×é£¬Ğı×ª0¸öÔªËØ£¬Ò²¾ÍÊÇµ¥µ÷ÉıĞòÊı×é±¾Éí
	int array5[] = { 1, 2, 3, 4, 5 };
	Test(array5, sizeof(array5) / sizeof(int), 1);

	// Êı×éÖĞÖ»ÓĞÒ»¸öÊı×Ö
	int array6[] = { 2 };
	Test(array6, sizeof(array6) / sizeof(int), 2);

	// ÊäÈënullptr
	Test(nullptr, 0, 0);

	return 0;
}
