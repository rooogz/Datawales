#include "stack.h"

/*******顺序栈方法*******/
//输入参数：申请的顺序栈空间大小
template<class ElemType>
SqStack <ElemType> :: SqStack(int m)
{
	m_top = 0;
	m_base = new ELemType[m];
	printf("栈空间申请！");//Debug
	m_size = m;
}

template<class ElemType>
SqStack <ElemType> :: ~SqStack()
{
	if(m_base != NULL)
	{
		delete[] m_base;
		printf("栈空间释放！");//Debug
	}
}

template<class ElemType>
void SqStack <ElemType> :: Clear()
{
	m_top = 0;
}

template<class ElemType>
bool SqStack <ElemType> :: IsEmpty() const
{
	return m_top == 0;

}

template<class ElemType>
int SqStack <ElemType> :: Length() const
{
	return m_top;
}


template<class ElemType>
ElemType & SqStack <ElemType> :: Top() const
{
	if(m_top>0)
	{
		printf("取栈顶成功！");//Debug
		return m_base[m_top-1];
	}
	else 
		return NULL;
}

/*入栈*/
/*需先判断栈是否已经满了*/
template<class ElemType>
void SqStack <ElemType> :: Push(const ElemType &e)
{
	if(m_top>=m_size)          //如果栈空间不足，则申请新空间
	{
		ElemType *newbase;
		newbase = new ElemType[m_size + 10]; //新空间比原先大10
		for(int i = 0; i < m_top; i++)       //把旧栈的数据复制到新站  
		{
			*(newbase + i) = *(m_base + i);
		} 
		delete[] m_base;                      //释放原空间 
		m_base = newbase;                     //栈空间转移完毕
		m_size += 10;                         //更新新栈空间大小
	}

	m_base[m_top++] = e;                      //入栈

}

/*出栈*/
template<class ElemType>
void SqStack <ElemType> :: Pop()
{
	if(m_top > 0)
	{
		m_top--;
	}

}

/*******链栈方法*******/
template <class ElemType>
LinkStack <ElemType>::LinkStack()
{
	top = NULL;

}

template <class ElemType>
LinkStack <ElemType>::~LinkStack()
{}

template <class ElemType>
void LinkStack <ElemType>::Clear()
{}

template <class ElemType>
bool LinkStack <ElemType>::IsEmpty() const
{}

template <class ElemType>
LinkStack <ElemType>::Length() const
{}

template <class ElemType>
LinkStack <ElemType>::Top() const
{}

template <class ElemType>
LinkStack <ElemType>::Push(ElemType &e) 
{}

template <class ElemType>
LinkStack <ElemType>::Pop() 
{}