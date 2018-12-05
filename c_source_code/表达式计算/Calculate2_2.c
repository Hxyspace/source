/*  ����׺ת��׺���ʽ �ͼ����׺���ʽ ���㷨�ϲ�   ������ջ�ṹ��  �������ջ*/

#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100

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
	char s1[STACK_INIT_SIZE];              //���������s1    ���ִ���s2
	double s2[STACK_INIT_SIZE];
	char c,e;

	double d,f,sum;
	char str[10];
	int i = 0;

	int base1,top1,base2,top2;           //�ֱ�Ϊs1 �� s2 ��  ջ��  ջ��

	base1=top1=base2=top2 = 0;   //��ʼ��ջ�� ջ��

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
				s2[top2++] = d;            //�����ִ��� double�͵�ջ��
				i = 0;
			}
		}
		while(c == ' ')
			scanf ("%c",&c);        //������յ��ո�   ���������

		if(')'==c)              //������� ) ����� ջ�е�����  ֱ������  (
		{
			e = s1[--top1];     //�������ջ
			while('(' != e)
			{
				f = s2[--top2];       //��ջ�е��������� ��ջ  
				d = s2[--top2];
				sum = Sum(e,d,f);       //�����ջ��������
				s2[top2++] = sum;      //������������ջ��
				e = s1[--top1];   //�������ջ
			}
		}
		else if('+'==c||'-'==c)     //������� + ���� - ���ͼ���ջ�е�����  ֱ�������ջ��
		{
			if( !(top1 - base1))
			{
				s1[top1++] = c;    //��������ջ��������  ���������ջ
			}
			else       //��������ջ��Ϊ��  ��һֱ����
			{
				do
				{
					e = s1[--top1];   //��ջ�е����������
					if('('==e)
					{
						s1[top1++] = e;   //��� �����Ϊ ( ��ջ
					}
					else
					{
						f = s2[--top2];       //��ջ�е��������� ��ջ  
						d = s2[--top2];
						sum = Sum(e,d,f);       //�����ջ��������
						s2[top2++] = sum;      //������������ջ��
					}
				}while(top1 - base1 &&'('!=e);
				s1[top1++] = c;                //�������ջ
			}
		}
		else if('*'==c||'/'==c||'('==c)       //��������Ϊ�Ƚϸߵ� *  /  ��  (   ��ֱ����ջ�ȴ�
		{
			s1[top1++] = c;
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
	while(top1 - base1)
	{
		e = s1[--top1];
		f = s2[--top2];
		d = s2[--top2];
		sum = Sum(e,d,f);        //�����������Ľ�� �������ѹ��ջ��
		s2[top2++] = sum;
	}

	d = s2[--top2];   //�����Ľ����ջ
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
		Priority();    //����

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