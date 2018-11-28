#include<stdio.h>

long long write()
{
	long long sum = 0;
	char i;
	int t = 1;
	i = getchar();
	while(i!='-'&&(i<'0'||i>'9'))
	{
		i = getchar();
	}
	if(i=='-')
		t = -1;
	else sum = i - '0';
	while(i = getchar(),i>='0'&&i<='9')
		sum = sum *10 + i-'0';
	return sum*t;
}

int main()
{
	int T,N,Q,l,r,t=1;
	long long sum,i,a[100005] = {0},q;
	T = write();
	while(T--)
	{
		N = write();
		Q = write();
			for(i = 1;i<=N;i++)
				a[i] = write()+a[i-1];
			printf("Case #%d\n",t++);
			q = Q;
			while(Q--)
			{
				l = write();
				r = write();
				printf("%lld\n",a[r]-a[l-1]);
			}
	}
}