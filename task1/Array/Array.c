#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "Array.h"


/***| x | x | x | x | 0 | 0 | 0 | 0 |*****/
/***|_______,_______|                *****/
/***     len = 4                      ****/
/***|_______________,_______________|*****/
/***           size = 8              *****/
/*//整形态动态数组
typedef struct 
{
	//private:
	int  * elem;//空间
	unsigned int size;//总量/元素个数
	unsigned int len;//当前长度/元素个数(也是尾游标)

}Array;*/


//构造函数，外部传入分配好的结构体地址，以便在栈区创建对象
bool Arr_Create(Array * pArry, unsigned int size)
{
	pArry->len = 0;
	if(size == 0)
		pArry->elem =NULL;
	else
	{
		pArry->elem = (int *)malloc(size*sizeof(int));
		if(NULL == pArry->elem)
			return false;//申请失败
	}
	pArry->size = size;
	return true;

}
//销毁函数，当结构体被释放的时候，还需要执行这个函数释放指向的动态空间防止泄露
void Arr_Destroy(Array * pArry)
{
 	if (NULL != pArry->elem )
 	{
 		free(pArry->elem);
 		pArry = NULL;
 		printf("successfully destroyed!");
 	}
}
//插值,插入到pos，后部整体后移
bool Arr_Insert(Array * pArry, int e, int pos)
{
	if(pos < 0 || pos > pArry->len)
		return false;
	//如果已满，则扩容,扩10个
	if(pArry->len >= pArry->size)
	{
		int * newbase;
		newbase = realloc(pArry->elem, (pArry->size + 10)*sizeof(int) );//开辟新空间，返回新地址
		if(NULL == newbase)
			return false;//扩容失败
		pArry->elem = newbase;
		pArry->size +=10;
	}
	int j;
	for(j = pArry->len; j > pos ; j-- )
	{
		pArry->elem[j]  = pArry->elem[j-1];
	}
	pArry->elem[pos] = e;
	pArry->len++;
	return true;

}
//追加元素
bool Arr_Append(Array * pArry, int e)
{
	//如果已满，则扩容,扩10个
	if(pArry->len >= pArry->size)
	{
		int * newbase;
		newbase = realloc(pArry->elem, (pArry->size + 10)*sizeof(int) );//开辟新空间，返回新地址
		if(NULL == newbase)
			return false;//扩容失败
		pArry->elem = newbase;
		pArry->size +=10;
	}
	pArry->elem[pArry->len] = e;
	pArry->len++;
	return true; 

}
//扩展制定长度并填充0
bool Arr_Expand(Array * pArry, int expan_len)
{
	if (expan_len <=0)
		return false;
	int lenth_t;//预设的长度
	lenth_t = pArry->len + expan_len;
	//如果超出，扩容
	if(lenth_t >= pArry->size)
	{
		int size_tmp = lenth_t + 10;//目标大小
		int * newbase;
		newbase = realloc(pArry->elem, size_tmp*sizeof(int) );//开辟新空间，返回新地址
		if(NULL == newbase)
			return false;//扩容失败
		pArry->elem = newbase;//空间地址更新
		pArry->size = size_tmp ;//目标大小更新
	}
	int i;
	for(i = pArry->len; i < lenth_t ; i++)
		pArry->elem[i] = 0;
	pArry->len = lenth_t;//长度更新
	return true;



}

//删除，删除pos位置元素，后部整体前移
bool Arr_Delete(Array * pArry, int pos)
{
	if(pos < 0 || pos >= pArry->len )
		return false;
  /*if(pArry->len <= 0)
		return false;*/
	//assert(pArry->len > 0);//逻辑上肯定大于0
	int j;
	for(j = pos; j < (pArry->len - 1);j++)
		pArry->elem[j] = pArry->elem[j+1];
	pArry->len--;
	printf("delete success!\n");
	return true;

}


//修改元素
bool Arr_SetElem(Array * pArry, int e, int pos)
{
	if(pos < 0 || pos >= pArry->len )
		return false;
	pArry->elem[pos] = e;
	return true;

}

void Arr_Print(const Array *pArry)
{
	if(pArry->len <= 0)
	{
		printf("Lenth = %d\n", pArry->len);
		return;
	}
	int j;
	printf("[");
	for(j = 0; j < pArry->len ;j++)
	{

		printf("%d",pArry->elem[j] );
		if(j != pArry->len - 1 )
			printf(",");
		else
			printf("]\n");
	}
	printf("Lenth = %d,Size = %d\n", pArry->len, pArry->size);
		
	

}




/*int main()
{
	Array test;
	if(!Arr_Create(&test, 12) )
	{
		printf("fail!\n");
		return 1;
	}
	printf("初始化情况\n");
	Arr_Print(&test);
	printf("插入测试：\n");
	int i;
	for(i = 0 ; i <= 14; i++)
	{
		Arr_Insert(&test, i, i);
		Arr_Print(&test);
	}
	printf("删除位置0：\n");
	Arr_Delete(&test, 0);
	Arr_Print(&test);
	printf("修改位置2为100：\n");
	Arr_SetElem(&test, 100, 2);
	Arr_Print(&test);
	printf("尾部追加233：\n");
	Arr_Append(&test, 233);
	Arr_Print(&test);

	Arr_Destroy(&test);

	return 1;


}*/