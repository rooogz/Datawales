#include <stdio.h>
#include <stdlib.h>

//Flag:0升序1:降序
int _MergeSort(char Flag, int seq[], int len, int temp[])
{
	int len1 = 0, len2 = 0;//划分子序列长
	int p1, p2, pos, left_st, left_end, i;

	//base case
	if(len == 1)
		return ?;

	if(len > 1)
	{
		if((len % 2) == 1 )
		{
			len2 = len/2;//短
			len1 = len - len2;//长
		}
		else
		{
			len1 = len2 = len/2;
		}
		p1 = 0;
		p2 = len1;
		//分
		_MergeSort(Flag, seq, len1, temp);
		_MergeSort(Flag, seq + len1, len2, temp);
		//治
		if(Flag == 0)//升序
		{
			pos = 0;
			while( pos < len )
			{

				if(seq[p1] > seq[p2])
				{
					temp[pos] = seq[p2];
					pos++; 
					p2++;
					if(p2 == len )
					{			
						left_st = p1;
						left_end = len1;//末位置+1	
						break;
					}
				}
				else
				{
					temp[pos] = seq[p1];
					pos++; 
					p1++;
					if(p1 == len1 )
					{			
						left_st = p2;
						left_end = len;//末位置+1	
						break;
					}
				}		
			}
			//剩余部分填入temp
			for(i = left_st; i < left_end; i++, pos++;)
			{
				temp[pos] = seq[i];
			}
			//temp拷贝到seq
			for(i = 0)
		}


	}

}