/*  ����׺ת��׺���ʽ �ͼ����׺���ʽ ���㷨�ϲ�   ����ջ�ṹ��*/

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
	int type;  //�ֱ�ջ������char  ����double  ��1��ʾchar  2��ʾdouble
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

double sum(char a,double x,double y)     //�������ļ���
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
					printf("\n��������Ϊ�㣡\n");
					return -1;
				}
		}
}

int Priority()
{
	sqStack s1,s2;       //���������s1   ���ִ���s2
	data c1,e1;

	data d2,e2,sum2;
	char str[10];
	int i = 0;
	
	InitStack(&s1,1);
	InitStack(&s2,2);
	
	scanf ("%c",&c1.C);
	while( c1.C != '#')
    {	
		while(c1.C == ' ')
			scanf ("%c",&c1.C);        //������յ��ո�   ���������

		while((c1.C >= '0' && c1.C <= '9')||c1.C=='.')
		{
			str[i++] = c1.C;
			str[i] = '\0';
			if(i>=10)
			{
				printf("������̫��!\n");
				return -1;
			}
			scanf ("%c",&c1.C);
			if(!((c1.C >= '0' && c1.C <= '9')||c1.C=='.'))
			{
				d2.D = atof(str);             //�ַ���ת���ɸ�������
				push(&s2,d2);
				i = 0;
			}
		}
		while(c1.C == ' ')
			scanf ("%c",&c1.C);        //������յ��ո�   ���������

		if(')'==c1.C)
        {
            pop(&s1,&e1);
			while('(' != e1.C)
            {
				pop(&s2,&e2);
				pop(&s2,&d2);
				sum2.D = sum(e1.C,d2.D,e2.D);
				push(&s2,sum2);
				pop(&s1,&e1);
            }
        }
		else if('+'==c1.C||'-'==c1.C)
        {
            if( !StackLen(s1))
            {
				push(&s1,c1);
            }
            else
            {
                do
                {
                    pop(&s1,&e1);
					if('('==e1.C)
                    {
                        push(&s1,e1);
                    }
                    else
                    {
						pop(&s2,&e2);
						pop(&s2,&d2);
						sum2.D = sum(e1.C,d2.D,e2.D);
						push(&s2,sum2);
                    }
				}while(StackLen(s1)&&'('!=e1.C);
                push(&s1,c1);
            }
        }
		else if('*'==c1.C||'/'==c1.C||'('==c1.C)
        {
            push(&s1,c1);
        }
		else if(c1.C=='#')
        {
            break;

        }
        else
        {
            printf("\n���������ʽ����\n");
            return -1;
        }

		scanf ("%c",&c1.C);
    }
    while(StackLen(s1))
    {
        pop(&s1,&e1);
		pop(&s2,&e2);
		pop(&s2,&d2);
		sum2.D = sum(e1.C,d2.D,e2.D);
		push(&s2,sum2);
    }

	pop(&s2,&d2);
	if((int)d2.D == d2.D)
		printf("\n %d",(int)d2.D);
	else
		printf("\n %lf",d2.D);

	return 0;
}

int main()
{

	char x = 'y';
	printf("�������������ʽ��֧��С��������#��Ϊ������־��\n");
	while(x == 'y')
	{
		Priority();

		putchar('\n');
		printf("\n�Ƿ�������루 y / n ����  ��");

		while((x = getchar()) == '\n');

		while(x != 'y' && x != 'n')
		{
			printf("\n�Ƿ�������루 y / n ����  ��");

			while((x = getchar()) == '\n');
		}         
		while(getchar() != '\n');          //��ջ�����
		putchar('\n');
	}
    return 0;
}