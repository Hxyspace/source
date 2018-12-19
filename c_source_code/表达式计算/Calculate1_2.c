/*   将中缀表达式转成后缀表达式 再计算后缀表达式  不定义栈结构   用数组代替栈结构*/

#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100

int RNM(char Ex[])          //中缀表达式转换成后缀
{
	int i = 0;
	char s[STACK_INIT_SIZE];        //定义数组作栈
	int base = 0,top = 0;           //栈底，栈顶
    char c,e;
	scanf ("%c",&c);
	while( c != '#')
    {	
		while(c == ' ')
			scanf ("%c",&c);        //如果接收到空格   则继续输入

		while((c >= '0' && c <= '9')||c =='.')
        {
			Ex[i++] = c;           //当字符为数字时   直接存入后缀表达式存放数组中

			scanf("%c",&c);
			if(c<'0'||c>'9'||c != '.')
				Ex[i++] = ' ';      //当数字输入结束时  存入空格
			
        }

		while(c == ' ')
			scanf ("%c",&c);        //如果接收到空格   则继续输入

		if(')'==c)
        {
            e = s[--top];
			while('(' != e)
            {
				Ex[i++] = e;
				Ex[i++] = ' ';
				e = s[--top];
            }
        }
		else if('+'==c||'-'==c)
        {
            if( !(top - base))
            {
				s[top++] = c;
            }
            else
            {
                do
                {
                    e = s[--top];
					if('('==e)
                    {
                        s[top++] = e;
                    }
                    else
                    {
						Ex[i++] = e;
						Ex[i++] = ' ';
                    }
				}while(top - base &&'('!=e);
                s[top++] = c;
            }
        }
		else if('*'==c||'/'==c||'('==c)
        {
            s[top++] = c;
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
    while(top - base)      //将栈中数组全部出栈存入  后缀表达式存放数组中
    {
        e = s[--top];
		Ex[i++] = e;
		Ex[i++] = ' ';
    }
	Ex[i-1] = '#';       //最后一个字符以 ‘#’ 作为结束
	return 0;
}

int RPN(char Ex[])         //后缀表达式的计算
{
	
	double s[STACK_INIT_SIZE];     //定义数组作栈
	char c;
	double d,e;
	char str[10];
	int i = 0,j = 0;
	int base = 0,top = 0;      //栈顶，栈底
	c = Ex[j++];               //将后缀表达式数组  逐一提取出来  计算

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
				d = atof(str);             //字符串转换成浮点类型
				s[top++] = d;
				i = 0;
				break;
			}
			
		}
		switch( c )
		{
			case '+':
				e = s[--top];
				d = s[--top];
				s[top++] = d + e;
				break;
			case '-':
				e = s[--top];
				d = s[--top];
				s[top++] = d - e;
				break;
			case '*':
				e = s[--top];
				d = s[--top];
				s[top++] = d * e;
				break;
			case '/':
				e = s[--top];
				d = s[--top];
				if(e != 0)
				{
					s[top++] = d / e;
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
	d = s[--top];
	if((int)d== d)
		printf("\n %d",(int)d);
	else
		printf("\n %lf",d);

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