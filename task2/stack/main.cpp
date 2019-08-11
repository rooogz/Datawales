#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	SqStack<int>  *My_Stack = new SqStack<int>(100) ;
	My_Stack->Push(12);
	int test = My_Stack->Top();
	delete[] My_Stack;
	printf("%d\n" , test);

	return 0;



}