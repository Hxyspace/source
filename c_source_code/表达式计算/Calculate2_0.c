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

double Sum(char a,double x,double y)     //�������ļ���
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
	CsqStack s1;       //���������s1   ���ִ���s2
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
			scanf ("%c",&c);        //������յ��ո�   ���������

		while((c >= '0' && c <= '9')||c=='.')         //ɸѡ����
		{
			str[i++] = c;
			str[i] = '\0';
			if(i>=10)
			{
				printf("������̫��!\n");
				return -1;
			}
			scanf ("%c",&c);
			if(!((c >= '0' && c <= '9')||c=='.'))     //�����������
			{
				d = atof(str);             //�ַ���ת���ɸ�������
				Dpush(&s2,d);            //�����ִ��� double�͵�ջ��
				i = 0;
			}
		}
		while(c == ' ')
			scanf ("%c",&c);        //������յ��ո�   ���������

		if(')'==c)              //������� ) ����� ջ�е�����  ֱ������  (
        {
            Cpop(&s1,&e);     //�������ջ
			while('(' != e)
            {
				Dpop(&s2,&f);       //��ջ�е��������� ��ջ 
				Dpop(&s2,&d);
				sum = Sum(e,d,f);       //�����ջ��������
				Dpush(&s2,sum);      //������������ջ��
				Cpop(&s1,&e);   //�������ջ
            }
        }
		else if('+'==c||'-'==c)     //������� + ���� - ���ͼ���ջ�е�����  ֱ�������ջ��
        {
            if( !CStackLen(s1))
            {
				Cpush(&s1,c);    //��������ջ��������  ���������ջ
            }
            else       //��������ջ��Ϊ��  ��һֱ����
            {
                do
                {
                    Cpop(&s1,&e);   //��ջ�е����������
					if('('==e)
                    {
                        Cpush(&s1,e);   //��� �����Ϊ ( ��ջ
                    }
                    else
                    {
						Dpop(&s2,&f);       //��ջ�е��������� ��ջ  
						Dpop(&s2,&d);
						sum = Sum(e,d,f);       //�����ջ��������
						Dpush(&s2,sum);      //������������ջ��
                    }
				}while(CStackLen(s1)&&'('!=e);
                Cpush(&s1,c);                //�������ջ
            }
        }
		else if('*'==c||'/'==c||'('==c)       //��������Ϊ�Ƚϸߵ� *  /  ��  (   ��ֱ����ջ�ȴ�
        {
            Cpush(&s1,c);
        }
		else if(c=='#')    //���� # ˵��������� �˳�ѭ��
        {
            break;

        }
        else
        {
            printf("\n���������ʽ����\n");
            return -1;
        }

		scanf ("%c",&c);
    }
	//�������û�����������ַ���   ���Ͻ����ֵ���ջ  ����  ֱ��û�������  Ҳ��������ֻʣ���һ�����
    while(CStackLen(s1))
    {
        Cpop(&s1,&e);
		Dpop(&s2,&f);
		Dpop(&s2,&d);
		sum = Sum(e,d,f);        //�����������Ľ�� �������ѹ��ջ��
		Dpush(&s2,sum);
    }

	Dpop(&s2,&d);   //�����Ľ����ջ
	if((int)d == d)
		printf("\n %d",(int)d);     //������Ϊ�����ʹ�ӡ����   ������ΪС���ʹ�ӡ������
	else
		printf("\n %lf",d);

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

		while((x = getchar()) == '\n');    //��ջ�����

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