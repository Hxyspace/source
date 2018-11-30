#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100

int RNM(char Ex[])          //��׺���ʽת���ɺ�׺
{
	int i = 0;
	char s[STACK_INIT_SIZE];
	int base = 0,top = 0;
    char c,e;
	scanf ("%c",&c);
	while( c != '#')
    {	
		while(c == ' ')
			scanf ("%c",&c);        //������յ��ո�   ���������

		while(c>='0'&&c<='9')
        {
			Ex[i++] = c;

			scanf("%c",&c);
			if(c<'0'||c>'9')
				Ex[i++] = ' ';
			
        }

		while(c == ' ')
			scanf ("%c",&c);        //������յ��ո�   ���������

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
            printf("\n���������ʽ����\n");
            return -1;
        }

		scanf ("%c ",&c);
    }
    while(top - base)
    {
        e = s[--top];
		Ex[i++] = e;
		Ex[i++] = ' ';
    }
	Ex[i-1] = '#';
	return 0;
}

int RPN(char Ex[])         //��׺���ʽ�ļ���
{
	
	double s[STACK_INIT_SIZE];
	char c;
	double d,e;
	char str[10];
	int i = 0,j = 0;
	int base = 0,top = 0;
	c = Ex[j++];

	while(c != '#')
	{
		while((c >= '0' && c <= '9')||c=='.')
		{
			str[i++] = c;
			str[i] = '\0';
			if(i>=10)
			{
				printf("������̫��!\n");
				return -1;
			}
			c = Ex[j++];
			if(c == ' ')
			{
				d = atof(str);             //�ַ���ת���ɸ�������
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
					printf("\n��������Ϊ�㣡\n");
					return -1;
				}
				break;
		}
		c = Ex[j++];
	}
	d = s[--top];
	printf("%lf",d);
	return 0;
}

int main()
{
	char Ex[STACK_INIT_SIZE];    //���ڴ�ź�׺���ʽ
	char x = 'y';
	printf("�������������ʽ��֧��С��������#��Ϊ������־��\n");
	while(x == 'y')
	{
		RNM(Ex);    //�������ʽת��׺���ʽ

		RPN(Ex);    //�����׺���ʽ

		putchar('\n');
		printf("\n�Ƿ�������루 y / n ����  ��");

		while(x = getchar(),x == '\n');

		while(x != 'y' && x != 'n')
		{
			printf("\n�Ƿ�������루 y / n ����  ��");

			while(x = getchar(),x == '\n');
		}         
		fflush(stdin);          //��ջ�����
		putchar('\n');
	}
    return 0;
}