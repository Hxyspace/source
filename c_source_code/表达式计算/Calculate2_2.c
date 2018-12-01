/*  将中缀转后缀表达式 和计算后缀表达式 的算法合并   不定义栈结构体  数组代替栈*/

#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100

double Sum(char a,double x,double y)
{
	switch( a )
		{
			case '+':
				return x+y;
				break;
			case '-':
				return x-y;
				break;
			case '*':
				return x*y;
				break;
			case '/':
				if(y != 0)
				{
					return x / y;
				}
				else
				{
					printf("\n出错：除数为零！\n");
					return -1;
				}
				break;
		}
}

int Priority()
{
	char s1[STACK_INIT_SIZE];
	double s2[STACK_INIT_SIZE];
	char c,e;

	double d,f,sum;
	char str[10];
	int i = 0;

	int base1,top1,base2,top2;

	base1=top1=base2=top2 = 0;
	
	scanf ("%c",&c);
	while( c != '#')
    {	
		while(c == ' ')
			scanf ("%c",&c);        //如果接收到空格   则继续输入

		while((c >= '0' && c <= '9')||c=='.')
		{
			str[i++] = c;
			str[i] = '\0';
			if(i>=10)
			{
				printf("出错，数太大!\n");
				return -1;
			}
			scanf ("%c",&c);
			if(!((c >= '0' && c <= '9')||c=='.'))
			{
				d = atof(str);             //字符串转换成浮点类型
				s2[top2++] = d;
				i = 0;
			}
		}
		while(c == ' ')
			scanf ("%c",&c);        //如果接收到空格   则继续输入

		if(')'==c)
        {
            e = s1[--top1];
			while('(' != e)
            {
				f = s2[--top2];
				d = s2[--top2];
				sum = Sum(e,d,f);
				s2[top2++] = sum;
				e = s1[--top1];
            }
        }
		else if('+'==c||'-'==c)
        {
            if( !(top1 - base1))
            {
				s1[top1++] = c;
            }
            else
            {
                do
                {
                    e = s1[--top1];
					if('('==e)
                    {
                        s1[top1++] = e;
                    }
                    else
                    {
						f = s2[--top2];
						d = s2[--top2];
						sum = Sum(e,d,f);
						s2[top2++] = sum;
                    }
				}while(top1 - base1 &&'('!=e);
                s1[top1++] = c;
            }
        }
		else if('*'==c||'/'==c||'('==c)
        {
            s1[top1++] = c;
        }
		else if(c=='#')
        {
            break;

        }
        else
        {
            printf("\n出错：输入格式错误！\n");
            return -1;
        }

		scanf ("%c",&c);
    }
    while(top1 - base1)
    {
        e = s1[--top1];
		f = s2[--top2];
		d = s2[--top2];
		sum = Sum(e,d,f);
		s2[top2++] = sum;
    }

	d = s2[--top2];
	if((int)d == d)
		printf("\n %d",(int)d);
	else
		printf("\n %lf",d);

	return 0;
}

int main()
{

	char x = 'y';
	printf("请输入算数表达式（支持小数），以#作为结束标志：\n");
	while(x == 'y')
	{
		Priority();

		putchar('\n');
		printf("\n是否继续输入（ y / n ）？  ：");

		while((x = getchar()) == '\n');

		while(x != 'y' && x != 'n')
		{
			printf("\n是否继续输入（ y / n ）？  ：");

			while((x = getchar()) == '\n');
		}         
		while(getchar() != '\n');          //清空缓冲区
		putchar('\n');
	}
    return 0;
}