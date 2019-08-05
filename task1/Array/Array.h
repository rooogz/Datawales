#ifndef __ARRAY_H__
#define __ARRAY_H__
#include <stdbool.h>

//整形态动态数组
typedef struct 
{
	//private:
	int  * elem;//空间
	unsigned int size;//总量/元素个数
	unsigned int len;//当前长度/元素个数(也是尾游标)

}Array;


//构造函数，外部传入分配好的结构体地址，以便在栈区创建对象
bool Arr_Create(Array * , unsigned int );

//销毁函数，当结构体被释放的时候，还需要执行这个函数释放指向的动态空间防止泄露
void Arr_Destroy(Array * );

//插值,插入到pos，后部整体后移
bool Arr_Insert(Array * , int , int );

//追加元素
bool Arr_Append(Array * , int );

//删除，删除pos位置元素，后部整体前移
bool Arr_Delete(Array * , int );
//长度扩展
bool Arr_Expand(Array * pArry, int expan_len);

//修改元素
bool Arr_SetElem(Array * , int , int );


void Arr_Print(const Array * );





#endif