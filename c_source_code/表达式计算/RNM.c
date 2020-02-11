#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef double ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

InitStack(sqStack *s)		//��ʼ��ջ
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof (ElemType));
    if (!s->base)
        exit (0);
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

push(sqStack *s,ElemType e)		//��ջ
{
    //���ջ�գ�׷�ӿռ�
    if (s->top - s->base >= s->stackSize )
    {
        s->base = (ElemType *)realloc(s->base,(s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if( !s->base )
            exit(0);
        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACKINCREMENT;
    }
    *(s->top) = e;
    s->top++;
}

ClearStack(sqStack *s)	//���ջ
{
    s->top = s->base;
}

DestroyStack(sqStack *s)		//����ջ
{
    int i,len;
    len = s->stackSize;
    for(i = 0;i<=len;i++)
    {
        free(s->base);
        s->base++;
    }
    s->base = s->top =NULL;
    s->stackSize = 0;
}

int StackLen(sqStack s)		//����ջ����
{
    return(s.top - s.base );
}

pop(sqStack *s,ElemType *e)		//��ջ
{
    if(s->top == s->base )
        return 0;
    *e = *--(s->top);
}

int main()
{
	sqStack s;
	char c;
	double d,e;
	char str[10];
	int i =0;
	InitStack(&s);

	printf("��������ʽ  ��#������");
	scanf("%c",&c);

	while(c != '#')
	{
		while(isdigit(c)||c=='.')
		{
			str[i++] = c;
			str[i] = '\0';
			if(i>=10)
			{
				printf("������̫��!\n");
				return -1;
			}
			scanf("%c",&c);
			if(c == ' ')
			{
				d = atof(str);
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
				push(&s,d+e);
				break;
			case '-':
				pop(&s,&e);
				pop(&s,&d);
				push(&s,d-e);
				break;
			case '*':
				pop(&s,&e);
				pop(&s,&d);
				push(&s,d*e);
				break;
			case '/':
				pop(&s,&e);
				pop(&s,&d);
				if(e != 0)
				{
				push(&s,d/e);
				}
				else
				{
					printf("\n��������Ϊ�㣡\n");
					return -1;
				}
				break;
		}
		scanf("%c",&c);
	}
	pop(&s,&d);
	printf("%lf",d);

	return 0;
}