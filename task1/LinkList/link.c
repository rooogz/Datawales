#include "link.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool Link_Create(LinkList * li)
{
	li->len = 0;
	li->head = li->rear = (LinkNode *)malloc(sizeof(LinkNode) );
	if(li->head == NULL)
	{
		printf("Create LinkList Failed!");
		return false;
	}
	head->next = NULL;

}
//i from 1 to len .insert prior to position "i"
bool Link_Insert(LinkList * li, int i, int data)
{
	LinkNode * f;//f为查找指针
	LinkNode * nn;
	if(i < 1 || i > li->len + 1 ) //包括尾部插入
		return false;
	int j = 1;//j标记f位置，从1 开始
	f = li->head;//j=1时，f位于i=1插入位置

	while(j < i)//按规律，当j=i的时候正好f位于正确的插入位置
	{
		f = f->next;
		j++;
	} 
	//插入在f后面
	nn =  (LinkNode *)malloc(sizeof(LinkNode) );//开辟新节点
	nn->data = data;
	nn->next = f->next;//插入
	f->next = nn;
	//边界：如果是尾部插入
	if(i == li->len +1 )
		li->rear = nn;
	//表长更新 
	li->len++;

	printf("Insert %d in position %d",data ,i );
	return true;
}

bool Link_Delete(LinkList * li, int i)
{
	LinkNode * f;
	LinkNode * tp;
	if(i < 1 || i > li->len )
		return false
	int j = 1;
	f = li->head;

	while(j < i)
	{
		f = f->next;
		j++;
	}
	tp = f->next;
	f->next = tp->next;
	//边界：如果是尾部删除
	if(tp ==  li->rear ) //if(i == li->len)
		li->rear = f;
	//销毁节点
	free(tp);
	//表长更新
	li->len--;
	printf("Delete node in position %d",i );
	return true;

}