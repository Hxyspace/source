/*  ����׺ת��׺���ʽ �ͼ����׺���ʽ ���㷨�ϲ�   ������ջ�ṹ��  �������ջ*/

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
					printf("\n��������Ϊ�㣡\n");
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
			scanf ("%c",&c);        //������յ��ո�   ���������

		while((c >= '0' && c <= '9')||c=='.')
		{
			str[i++] = c;
			str[i] = '\0';
			if(i>=10)
			{
				printf("������̫��!\n");
				return -1;
			}
			scanf ("%c",&c);
			if(!((c >= '0' && c <= '9')||c=='.'))
			{
				d = atof(str);             //�ַ���ת���ɸ�������
				s2[top2++] = d;
				i = 0;
			}
		}
		while(c == ' ')
			scanf ("%c",&c);        //������յ��ո�   ���������

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
            printf("\n���������ʽ����\n");
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