#ifndef __LINK_H__
#define __LINK_H__



typedef struct 
{
	int data;
	LinkNode * next;
}LinkNode;

typedef struct 
{
	int data;
	LinkNode * next;
	LinkNode * pri;
}DuLinkNode;


//带dummy头节点，头指针指向dummy
typedef struct 
{
	int len;
	LinkNode * head;
	LinkNode * rear;

}LinkList;

typedef struct 
{
	int len;
	LinkNode * rear;
}ScLinkList;

typedef struct 
{
	int len;
	LinkNode * head;
	LinkNode * rear;
}DuLinkList;
#endif