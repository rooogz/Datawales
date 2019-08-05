#include "Array.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

//问题说明：两个有序数组A1，A2，把A2合并到A1去仍然有序

//假定两数组都是升序的哈哈,返回为Arr1
bool Arr_Merge_asc(Array * Arr1, const Array * Arr2)
{
	int len1, len2;
	int ptr1, ptr2, ptr;//游标
	len1 = Arr1->len;
	len2 = Arr2->len;
	//边界处理
	if(len2 == 0)
		return true;
	else if(len1 ==0)
	{
		int i;
		for(i = 0; i < len2; i++)
			if(false == Arr_Append(Arr1, Arr2->elem[i]) )
				return false;
		return true;
	}
	//一般情况,最终数组长度肯定是len1+len2从右边开始插入
	else
	{

		ptr1 = Arr1->len - 1;
		ptr2 = Arr2->len - 1;
		ptr = Arr1->len + Arr2->len - 1; //插入位置游标

		//数组一扩大到m+n
		if(false == Arr_Expand(Arr1, Arr2->len) )
			return false;

		while(ptr1 >=0 && ptr2 >= 0)
		{
			//从右边开始,较大的值放入数组1最右
			if(Arr1->elem[ptr1] >= Arr2->elem[ptr2])//从arr1取
			{
				Arr_SetElem(Arr1, Arr1->elem[ptr1], ptr);
				ptr1--;
			}
			else//从arr2取
			{
				Arr_SetElem(Arr1, Arr2->elem[ptr2], ptr);
				ptr2--;
			}
			ptr--;
		}
		assert(ptr1 <0 || ptr2 < 0);
		//数组1取完了，则剩下的数组2直接放入(此时逻辑上必然ptr == ptr2否则程序是没按逻辑走)
		if(ptr1<0)
		{
			assert(ptr2 == ptr);
			while(ptr2 >= 0)
			{
				Arr_SetElem(Arr1, Arr2->elem[ptr2], ptr);
				ptr2--;
				ptr--;
			}
		}
		//数组2取完了，完事
		else if(ptr2<0)
		{
			return true;
		}
		else 
		{
			return false;
		}


	}

}

int main ()
{
	Array a1,a2;
	int n;
	Arr_Create(&a1, 20);
	Arr_Create(&a2, 20);
	while(scanf("%d", &n))
	{
		Arr_Append(&a1, n);

	}
	Arr_Print(&a1);

	Arr_Append(&a2, 2);
	Arr_Append(&a2, 4);
	Arr_Append(&a2, 5);
	Arr_Append(&a2, 22);
	Arr_Append(&a2, 100);
		
	Arr_Print(&a2);
	if(false == Arr_Merge_asc(&a1, &a2) )
	{
		printf("Wrong!!");
		return -1;
	}
	else
		Arr_Print(&a1);

	return 1;


}




