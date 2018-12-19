/*   将中缀表达式转成后缀表达式 再计算后缀表达式  定义栈结构*/

#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100

typedef union
{
	double D;
	char C;
}data;

typedef union
{
	double *D;
	char *C;
} Top,Base;

typedef struct
{
    Base base;
    Top top;
	int type;  //分别栈类型是char  还是double  用1表示char  2表示double
    int stackSize;
}sqStack;

void InitStack(sqStack *s,int type)
{
	if(type == 1)
	{
		s->base.C = (char *)malloc(STACK_INIT_SIZE * sizeof (char));
	   s->type = 1;
	}
	else
	{
		s->base.D = (double *)malloc(STACK_INIT_SIZE * sizeof (double));
		s->type = 2;
	}
	   s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void push(sqStack *s,data e)
{
	if(s->type == 1)
		*s->top.C++ = e.C;
	else
		*s->top.D++ = e.D;
}

void ClearStack(sqStack *s)
{
	if(s->type == 1)
		s->top.C = s->base.C;
	else
		s->top.D = s->base.D;
}

void DestroyStack(sqStack *s)
{
    int i,len;
    len = s->stackSize;
    for(i = 0;i<=len;i++)
    {
		if(s->type == 1)
		{
			free(s->base.C);
			s->base.C++;
		}
		else
		{
			free(s->base.D);
			s->base.D++;
		}
    }
	if(s->type == 1)
		s->base.C = s->top.C = NULL;
	else
		s->base.D = s->top.D = NULL;
    s->stackSize = 0;
}

int StackLen(sqStack s)
{
	if(s.type == 1)
		return(s.top.C - s.base.C );
	else
		return(s.top.D - s.base.D);
}

int pop(sqStack *s,data *e)
{
	if(s->type == 1)
	{
		if(s->top.C == s->base.C )
			return 0;
		e->C = *--(s->top.C);
	}
	else
	{
		if(s->top.D == s->base.D )
			return 0;
		e->D = *--(s->top.D);
	}
	return 0;
}

int RNM(char Ex[])          //中缀表达式转换成后缀
{
	int i = 0;
	sqStack s;
    data c,e;
    InitStack(&s,1);

	scanf ("%c",&c.C);
	while( c.C != '#')
    {	
		while(c.C == ' ')
			scanf ("%c",&c.C);        //如果接收到空格   则继续输入

		while((c.C >= '0' && c.C <= '9')||c.C=='.')
        {
			Ex[i++] = c.C;

			scanf("%c",&c.C);
			if(c.C<'0'||c.C>'9')
				Ex[i++] = ' ';
        }

		while(c.C == ' ')
			scanf ("%c",&c.C);        //如果接收到空格   则继续输入

		if(')'==c.C)
        {
            pop(&s,&e);
			while('(' != e.C)
            {
				Ex[i++] = e.C;
				Ex[i++] = ' ';
				pop(&s,&e);
            }
        }
		else if('+'==c.C||'-'==c.C)
        {
            if( !StackLen(s))
            {
				push(&s,c);
            }
            else
            {
                do
                {
                    pop(&s,&e);
					if('('==e.C)
                    {
                        push(&s,e);
                    }
                    else
                    {
						Ex[i++] = e.C;
						Ex[i++] = ' ';
                    }
				}while(StackLen(s)&&'('!=e.C);
                push(&s,c);
            }
        }
		else if('*'==c.C||'/'==c.C||'('==c.C)
        {
            push(&s,c);
        }
		else if(c.C=='#')
        {
            break;

        }
        else
        {
            printf("\n出错：输入格式错误！\n");
            return -1;
        }

		scanf ("%c",&c.C);
    }
    while(StackLen(s))
    {
        pop(&s,&e);
		Ex[i++] = e.C;
		Ex[i++] = ' ';
    }
	Ex[i-1] = '#';
	return 0;
}

int RPN(char Ex[])         //后缀表达式的计算
{
	
	sqStack s;
	char c;
	data d,e,sum;
	char str[10];
	int i = 0,j = 0;
	InitStack(&s,2);
	c = Ex[j++];

	while(c != '#')
	{
		while((c >= '0' && c <= '9')||c=='.')
		{
			str[i++] = c;
			str[i] = '\0';
			if(i>=10)
			{
				printf("出错，数太大!\n");
				return -1;
			}
			c = Ex[j++];
			if(c == ' ')
			{
				d.D = atof(str);             //字符串转换成浮点类型
				push(&s,d);
				i = 0;
				break;
			}
			
		}
		switch( c )
		{
			case '+':
				pop(&s,&e);
				pop(&s,&d);
				sum.D = d.D + e.D;
				push(&s,sum);
				break;
			case '-':
				pop(&s,&e);
				pop(&s,&d);
				sum.D = d.D - e.D;
				push(&s,sum);
				break;
			case '*':
				pop(&s,&e);
				pop(&s,&d);
				sum.D = d.D * e.D;
				push(&s,sum);
				break;
			case '/':
				pop(&s,&e);
				pop(&s,&d);
				if(e.D != 0)
				{
					sum.D = d.D / e.D;
					push(&s,sum);
				}
				else
				{
					printf("\n出错：除数为零！\n");
					return -1;
				}
				break;
		}
		c = Ex[j++];
	}
	pop(&s,&d);
	if((int)d.D == d.D)
		printf("\n %d",(int)d.D);
	else
		printf("\n %lf",d.D);
	return 0;
}

int main()
{
	char Ex[STACK_INIT_SIZE];    //用于存放后缀表达式
	char x = 'y';
	printf("请输入算数表达式（支持小数），以#作为结束标志：\n");
	while(x == 'y')
	{
		RNM(Ex);    //算数表达式转后缀表达式

		RPN(Ex);    //计算后缀表达式

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