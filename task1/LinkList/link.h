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



typedef struct 
{
	int len;
	LinkNode * head;
	LinkNode * rear;

}LinkList;

typedef struct 
{
	int len;
	LinkNode * head;
	LinkNode * rear;
}ScLinkList;

typedef struct 
{
	int len;
	LinkNode * head;
	LinkNode * rear;
}DuLinkList;
#endif