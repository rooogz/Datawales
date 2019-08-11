#ifndef _STACK_H
#define _STACK_H

/*顺序栈*/
template <class ElemType>
class SqStack
{
public:
	SqStack(int m);
	~SqStack();
	void Clear();                      //清空栈
	bool IsEmpty() const;                //判断是否为空
	int Length() const;                //取长度
	ElemType & Top() const;            //取栈顶元素
    void Push(const ElemType &e);       //入栈
	void Pop();                     //出栈
private:
	ElemType *m_base;                //基地址指针
	int m_top;                       //栈顶指针
	int m_size;                      //顺序空间大小
};

/*链栈*/
//单链表栈节点
template <class ElemType>
struct LinkNode
{	
	ElemType data;
	LinkNode<ElemType> *next;
}
//链栈类
template <class ElemType>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();
	void Clear();                      //清空栈
	bool IsEmpty() const;                //判断是否为空
	int Length() const;                //取长度
	ElemType & Top() const;            //取栈顶元素
    void Push(const ElemType &e);       //入栈
	void Pop();                         //出栈


private:
	struct LinkNode<ElemType> *top;

}