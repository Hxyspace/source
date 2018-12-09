//递归问题：在n个球中取m个球 不放回  多少种取法
#include<stdio.h>

int f(int n,int m)
{
	if(n<m) 
		return 0;
	if(n == m)
		return 1;
	if(m == 0)
		return 1;
	
	return f(n-1,m-1) + f(n-1,m);
}

int main()
{
	printf("%d",f(10,3));
	return 0;
}