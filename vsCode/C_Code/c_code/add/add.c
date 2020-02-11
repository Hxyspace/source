#include<stdio.h>

int add(int , int );
int sub(int , int );
int sub2(int , int );
int mul(int , int );
int div(int , int );

int main()
{
	int a , b;
	while(1)
	{
		scanf("%d%d",&a, &b);
		
		printf("add:\t%d\nsub:\t%d\nmul:\t%d\ndiv:\t%d\n\n",add(a, b), sub2(a, b), mul(a, b), div(a, b) );
	}
	
	return 0;
}

int add(int a, int b)
{			/* a ^ b 等于相加后不进位的和   a & b 得可以产生进位的地方，左移一位后得进位后的值*/
	return b ? add(a ^ b, (a & b) << 1) : a ;
}

int sub(int a, int b)
{		/* 减法为 加上减数的补码*/
	return add(a, add(~b, 1));
}

int sub2(int a, int b)
{	
	int temp = a & b;		/* temp得刚好相减为0的位*/
	b ^= temp;				/* b 得被减数为 0，减数为 1 的位 ，即产生借位的地方*/
	a ^= temp;				/* a 得 被减数为1 ，减数为 0 的位 */
	
	/* a | b 得相减不借位的差  b << 1 为借位的值 */
	return b ? sub(a | b, b << 1) : a;
}

int mul(int a, int b)
{
	/* 列竖式运算 */
	int sum = 0;
	
	if(b < 0)
	{
		b = add(~b, 1);
		a = add(~a, 1);
	}
	
	while(b)
	{
		if(b & 1)
			sum = add(sum, a);
		b >>= 1;
		a <<= 1;
	}
	
	return sum;
}

int div(int a, int b)
{
	int sum = 0, temp , sym = 0;
	
	if((a ^ b) < 0)
		sym = 1;
	
	if(a < 0)
		a = add(~a, 1);
	if(b < 0)
		b = add(~b, 1);
	
	temp = b;
	while(temp <= a)
		temp <<= 1;
	
	while(temp > b)
	{
		sum <<= 1;
		temp >>= 1;

		if(temp <= a)
		{
			a = sub(a, temp);
			sum |= 1;
		}
	}
	
	return sym ? add(~sum, 1) : sum;
}