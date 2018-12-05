#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100

typedef struct
{
    double *base;
    double *top;
    int stackSize;
}DsqStack;

typedef struct
{
    char *base;
    char *top;
    int stackSize;
}CsqStack;

void DInitStack(DsqStack *s)
{
    s->base = (double *)malloc(STACK_INIT_SIZE * sizeof (double));
    if (!s->base)
        exit (0);
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void CInitStack(CsqStack *s)
{
    s->base = (char *)malloc(STACK_INIT_SIZE * sizeof (char));
    if (!s->base)
        exit (0);
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Dpush(DsqStack *s,double e)
{
    *(s->top) = e;
    s->top++;
}

void Cpush(CsqStack *s,char e)
{
    *(s->top) = e;
    s->top++;
}

int DStackLen(DsqStack s)
{
    return(s.top - s.base );
}

int CStackLen(CsqStack s)
{
    return(s.top - s.base );
}

int Dpop(DsqStack *s,double *e)
{
    if(s->top == s->base )
        return 0;
    *e = *--(s->top);
}

int Cpop(CsqStack *s,char *e)
{
    if(s->top == s->base )
        return 0;
    *e = *--(s->top);
}

double Sum(char a,double x,double y)     //两个数的计算
{
	switch( a )
		{
			case '+':
				return x+y;
			case '-':
				return x-y;
			case '*':
				return x*y;
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
		}
}

int Priority()
{
	CsqStack s1;       //运算符存入s1   数字存入s2
	DsqStack s2;
	char c,e;

	double d,f,sum;
	char str[10];
	int i = 0;
	
	CInitStack(&s1);
	DInitStack(&s2);
	
	scanf ("%c",&c);
	while( c != '#')
    {	
		while(c == ' ')
			scanf ("%c",&c);        //如果接收到空格   则继续输入

		while((c >= '0' && c <= '9')||c=='.')         //筛选数字
		{
			str[i++] = c;
			str[i] = '\0';
			if(i>=10)
			{
				printf("出错，数太大!\n");
				return -1;
			}
			scanf ("%c",&c);
			if(!((c >= '0' && c <= '9')||c=='.'))     //数字输入结束
			{
				d = atof(str);             //字符串转换成浮点类型
				Dpush(&s2,d);            //将数字存入 double型的栈中
				i = 0;
			}
		}
		while(c == ' ')
			scanf ("%c",&c);        //如果接收到空格   则继续输入

		if(')'==c)              //如果遇到 ) 则计算 栈中的数据  直到遇到  (
        {
            Cpop(&s1,&e);     //运算符出栈
			while('(' != e)
            {
				Dpop(&s2,&f);       //将栈中的两个数字 出栈 
				Dpop(&s2,&d);
				sum = Sum(e,d,f);       //计算出栈的两个数
				Dpush(&s2,sum);      //将计算结果存入栈中
				Cpop(&s1,&e);   //运算符出栈
            }
        }
		else if('+'==c||'-'==c)     //如果遇到 + 或者 - ，就计算栈中的数据  直到运算符栈空
        {
            if( !CStackLen(s1))
            {
				Cpush(&s1,c);    //如果运算符栈中无数据  则运算符入栈
            }
            else       //如果运算符栈不为空  则一直计算
            {
                do
                {
                    Cpop(&s1,&e);   //将栈中的运算符弹出
					if('('==e)
                    {
                        Cpush(&s1,e);   //如果 运算符为 ( 入栈
                    }
                    else
                    {
						Dpop(&s2,&f);       //将栈中的两个数字 出栈  
						Dpop(&s2,&d);
						sum = Sum(e,d,f);       //计算出栈的两个数
						Dpush(&s2,sum);      //将计算结果存入栈中
                    }
				}while(CStackLen(s1)&&'('!=e);
                Cpush(&s1,c);                //运算符入栈
            }
        }
		else if('*'==c||'/'==c||'('==c)       //如果运算符为比较高的 *  /  或  (   就直接入栈等待
        {
            Cpush(&s1,c);
        }
		else if(c=='#')    //遇到 # 说明输入结束 退出循环
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
	//接受完用户输入的所有字符后   不断将数字弹出栈  计算  直到没有运算符  也就是数字只剩最后一个结果
    while(CStackLen(s1))
    {
        Cpop(&s1,&e);
		Dpop(&s2,&f);
		Dpop(&s2,&d);
		sum = Sum(e,d,f);        //计算两个数的结果 并将结果压入栈中
		Dpush(&s2,sum);
    }

	Dpop(&s2,&d);   //将最后的结果出栈
	if((int)d == d)
		printf("\n %d",(int)d);     //如果结果为整数就打印整型   如果结果为小数就打印浮点型
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

		while((x = getchar()) == '\n');    //清空缓冲区

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