#include<stdio.h>

int f(int n)
{
	int i;
	if(n==0)
		return 0;
	for(i=1;i<8&&n-i>=0;i+=2)
	if(f(n-i)==0) return 1;
	return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	if(f(n))
		printf("yes\n");
	else
		printf("no\n");
	getchar();getchar();
	return 0;
}