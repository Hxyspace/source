#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef char ElemType;
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

ClearStack(sqStack *s)		//���ջ
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
        return ;
    *e = *--(s->top);
}

int main()
{
    sqStack s;
    char c,e;
    InitStack(&s);

    printf("��������׺���ʽ����#��Ϊ������־��");
    scanf ("%c",&c);
    while( c != '#')
    {
        while(c>='0'&&c<='9')
        {
            printf("%c",c);
            scanf("%c",&c);
            if(c<'0'||c>'9')
            printf(" ");

        }
        if(')'==c)
        {
            pop(&s,&e);
            while('(' != e)
            {
                printf("%c ",e);
                pop(&s,&e);
            }
        }
        else if('+'==c||'-'==c)
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
                    if('('==e)
                    {
                        push(&s,e);
                    }
                    else
                    {
                        printf("%c ",e);
                    }
                }while(StackLen(s)&&'('!=e);
                push(&s,c);
            }
        }
        else if('*'==c||'/'==c||'('==c)
        {
            push(&s,c);
        }
        else if(c=='#')
        {
            break;

        }
        else
        {
            printf("\n���������ʽ����\n");
            return -1;
        }

        scanf ("%c ",&c);
    }
    while(StackLen(s))
    {
        pop(&s,&e);
        printf("%c ",e);
    }
    return 0;
}
