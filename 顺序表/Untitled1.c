#include <stdio.h>
#include <stdlib.h>         //�����ڴ�ʱ���õ�malloc�������ڵĿ��ļ�

#define MAXSIZE 100         //�궨��˳������󳤶�
typedef int elemtype;       //��int����ȡ���
typedef struct {            //����˳���ṹ�壬��ȡ���Ϊ sequenlist
	elemtype data[MAXSIZE];
	int last;
} sequenlist;

sequenlist * InitList()    //��ʼ��
{
	sequenlist *L;                                //����ָ��˳����ָ��
	L=(sequenlist *)malloc(sizeof(sequenlist));   //Ϊ˳��������ڴ�
	L->last=0;                                    //��ʼ��˳��Ԫ��Ϊ0
	return L;                                     //����˳������͵�ָ��
}
void InputList(sequenlist *L,int n) //׷��n����
{
	int i;
	if(L->last+n >MAXSIZE )                //�ж�׷��n�����Ƿ�ᳬ��˳���ռ�
	{
		printf("�����ռ䣡");
		return ;                           //�˳��˺���
	}
	printf("������%d����:",n);
	for(i=0;i<n;i++)                               //����n��������˳�����
		scanf("%d" , &(L->data[L->last+i]));
	L->last=L->last+n;                             //�������ݸ�����n
}

void ClearList(sequenlist *L)   //���
{
	L->last=0;                  //ֱ�Ӱѱ������ݸ�������Ϊ0
}

int ListLength(sequenlist *L)   //���㳤��
{
	return (L->last);           //�������ݵĸ��� ����˳�����    ����ֱ�ӷ��ظ���
}

int FindList(sequenlist *L,elemtype e)  //����λ��
{
	int i;
	for(i=0;i<L->last;i++)             //����˳���
	{
		if(e==L->data[i])              //�ж�e�Ƿ�����е�ĳһ������ͬ
			return (i+1);              //����e����˳����е�λ��
	}
	printf("˳����в����� [%d]\n",e); //����������������˳�����Ȼ�Ҳ���e �����ʾe���ڱ���
	return 0;
}

int ListInsert(sequenlist *L,int i,elemtype e)   //��������
{
	int k;
	if (L->last == MAXSIZE )                     //�ж�˳����Ƿ�����
	{
		printf("˳����������޷�����Ԫ��\n");
		return 0;
	}
	if (i<1||i>L->last+1)                        //�жϲ����λ���Ƿ���˳���Χ��
	{
		printf("��Ҫ�����λ�ò���˳���Χ�С�\n");
		return 0;
	}
	if (i<=L->last)
	{
		for (k=L->last-1; k >= i-1;k--)
		{
			L->data[k+1] = L->data[k];             //�����λ�ú����Ԫ�ض�Ҫ�����һλ
		}
	}
	L->data[i-1] = e;                            //��������
	L->last++;                                   //���ȼ�1
	return 1;
}

int GetElem(sequenlist *L,int i)    //ȡֵ
{
	int e;
	if(L->last == 0)                            //�жϱ��Ƿ�Ϊ��
	{
		printf("˳���Ϊ��\n");
		return 0;
	}
	if(i<1||i>L->last)                          //�ж�i�Ƿ��ڷ�Χ��
	{
		printf("��%d��λ�ó���˳���Χ\n",i);
		return 0;
	}
	return (L->data[i-1]);                 //���ص�i��λ���ϵ�ֵ
}

int ListDelete(sequenlist *L,int i)          //ɾ������
{
	int k,e;
	if(L->last==0)                           //�жϱ��Ƿ�Ϊ��
	{
		printf("˳���Ϊ�ձ��޷�ִ��ɾ��������\n");
		return 0;
	}
	if(i<1||i>L->last)                       //�ж�i�Ƿ��ڷ�Χ��
	{
		printf("��%d��λ�ó���˳���Χ\n");
		return 0;
	}
	e = L->data[i-1];                        //�����е�i��Ԫ�ظ�ֵ��e
	if(i<L->last)
	{
		for (k = i;k<L->last;k++)
		{
			L->data[k-1]=L->data[k];            //����ɾ��Ԫ�غ����Ԫ��λ�ö�����ǰ��һλ
		}
	}
	L->last--;                                 //���ȼ�1
	printf("ɾ����Ԫ��Ϊ [%d]\n",e);
	return 1;
}

void OutputList(sequenlist *L)
{
	int i;

	for(i=0;i<L->last;i++)              //����˳�����˳�����Ԫ�ش�ӡ����
		printf("[%d] ",L->data[i]);
	printf("\n");
}

int Insert(sequenlist *L,elemtype e)   //�������
{
    int i,k;
    if (L->last == MAXSIZE )                  //�ж�˳����Ƿ�����
	{
		printf("˳����������޷�����Ԫ��\n");
		return 0;
	}
    if(e<=L->data[0]||L->last==0)             //���������ݱȱ��е�һ����С  ����˳���Ϊ��ʱ  ���������ֱ�ӷ��ڵ�һλ
    {
        for (k=L->last-1; k >=0;k--)
		{
			L->data[k+1] = L->data[k];        //��������ݶ��������һλ
		}
	L->data[0] = e;                           //���ڵ�һλ
	L->last++;                                //���ȼ�1

    }

    else if(e>=L->data[L->last-1])          //���������ݱȱ������һ������ʱ
    {
        L->data[L->last]=e;                 //��������ݷ������һλ
        L->last++;                          //���ȼ�1

    }
	else                                   //������Ҫ�����м�ʱ
    {
        for(i=1;i<=L->last-1;i++)          //����˳���
            if(e<=L->data[i])              //�Ƚϲ�������������Ԫ�صĴ�С���ȱ���Ԫ��Сʱ������ѭ��
            break;
		for (k=L->last-1; k >= i;k--)
		{
			L->data[k+1] = L->data[k];     //�����λ�ú����Ԫ�ض������һλ
        }
        L->data[i] = e;                    //��������
        L->last++;                         //���ȼ�1
	}

	return 1;
}

void CreatList()         //ִ��������뺯��
{
    int n,e;
    sequenlist L={{1,4,8,14,16,38,45,67,69,97,188,211},12};
    printf("˳���L����ֵΪ��\n");
    OutputList(&L);                            //��ʾ���и�Ԫ��
    printf("��������Ҫ�����Ԫ�أ�");
    scanf("%d",&n);                            //��������Ԫ��
    Insert(&L,n);                              //�����������ĺ���
    printf("����ɹ���������˳���Ϊ��\n");
    OutputList(&L);                             //��ʾ���и�Ԫ��



}

int LocateElem(sequenlist *L,elemtype e)  //�鿴ĳ����ֵ�Ƿ���˳�����
{
    int i;
    for(i=0;i<L->last;i++)
    {
        if(e==L->data[i])                //��ֵ�ڱ��д���  ������ֵ���ڵ�λ��
            return i+1;
    }
    return 0;                            //��ֵ���ڱ���   ���� 0
}

void unionL()              //�ϲ�����˳���
{
    sequenlist *La,*Lb;        //��������˳���ָ��
    int La_len,Lb_len,i,e;
    La=InitList();              //���ó�ʼ����������ʼ������˳���ָ��
    Lb=InitList();
    printf("�������һ�����Ա����ֵ�����س��������롣\n");

    do
    {
        scanf("%d",&e);
        Insert(La,e);         //����������뺯����ʹ�������ֵ����������

    }while(getchar()!='\n');  //�����벻���ڻس�ʱѭ��

    printf("������ڶ������Ա����ֵ�����س��������롣\n");
    do
    {
        scanf("%d",&e);
        Insert(Lb,e);         //����������뺯����ʹ�������ֵ����������

    }while(getchar()!='\n');  //�����벻���ڻس�ʱѭ��
    printf("����˳���ֱ�Ϊ��\n");
    OutputList(La);                 //������ʾ�������������������ʾ����
    OutputList(Lb);
	La_len = ListLength(La);        //�����󳤶ȵĺ�������ȡ���������ĳ���
	Lb_len = ListLength(Lb);
	for (i=1;i<=Lb_len;i++)
	{
		e=GetElem(Lb,i);            //��b������е�Ԫ��ȡ��
//		if(!LocateElem(La,e))
//		{
			Insert(La,e);           //��ȡ����Ԫ������Ĳ���a�������
//		}
	}
	printf("�ϲ����˳���Ϊ��\n\n");
	OutputList(La);                   //��ʾ�ϲ���������
}

int menu()   //�˵�
{
	int choice;
	printf("  \n˳����������\n");
	printf("     1.׷��\n");
	printf("     2.���\n");
	printf("     3.���㳤��\n");
	printf("     4.Ѱ�ҵ�Ԫ��λ��\n");
	printf("     5.����Ԫ��\n");
	printf("     6.ȡֵ\n");
	printf("     7.ɾ��\n");
	printf("     8.��ʾ\n");
	printf("     9.�������\n");
	printf("     10.˳���ĺϲ�\n");
	printf("     0.�˳�\n");
	printf("     ���������ѡ��");
	scanf("%d",&choice);
	return choice;                            //���û������ѡ����Ϊ����ֵ
}

int main()
{
	int choice;
	sequenlist *L;             //����˳���ָ��
	int i,n;
	L=InitList();              //��ʼ��˳���


	do
	{
		choice=menu();         //���ò˵�������������ֵ��ֵ��choice
		printf("\n\n");
		switch(choice)         //�����û��������ֵѡ��ִ�еĹ���
		{
		case 1:
			printf("Ҫ׷�Ӷ��ٸ���?");
			scanf("%d",&n);
			InputList(L,n);            //ִ��׷�����ݺ���
			break;
		case 2:
			ClearList(L);               //ִ�������
			printf("˳��������\n\n");
			break;
		case 3:
			printf("˳���ĳ���Ϊ%d\n\n",ListLength(L));   //�����󳤶Ⱥ���������ӡ˳���ĳ���
			break;
		case 4:
			printf("������Ҫ���ҵ�ֵ��\n");
			scanf("%d",&n);
			if(FindList(L,n))                                              //���ò��Һ��������ж��Ƿ���ҳɹ�
				printf("[%d] Ϊ˳����еĵ�%d������\n",n,FindList(L,n));   //��ӡ������Ԫ�����ڵ�λ��

			break;
		case 5:
			printf("��������Ҫ�����λ�ã�");
			scanf("%d",&i);
			printf("\n��������Ҫ�����Ԫ�أ�");
			scanf("%d",&n);
			if(ListInsert(L,i,n))                         //���ò��뺯�������ж��Ƿ����ɹ�
				printf("\nԪ�ز���ɹ���\n");
			break;
		case 6:
			printf("��Ҫȡ�ڼ���λ�õ�ֵ��\n");
			scanf("%d",&i);
			if(GetElem(L,i))                                     //����ȡֵ���������ж��Ƿ�ȡֵ�ɹ�
				printf("��%d��λ�õ�ֵΪ [%d]",i,GetElem(L,i));  //��ӡȡ������Ԫ��
			break;
		case 7:
			printf("��Ҫɾ���ڼ���λ�õ�ֵ��\n");
			scanf("%d",&i);
			ListDelete(L,i);                                //ִ��ɾ������
			break;
		case 8:
			OutputList(L);                                  //ִ����ʾ����
			break;
		case 9:
            CreatList();                                    //ִ��������뺯��
			break;
        case 10:
            unionL();                                       //ִ�����������ĺϲ�����
		case 0:
			break;
		default:  printf("[ %d ]Ϊ�Ƿ���\n",choice);
		}
	}
	while(choice);                  //���벻Ϊ0ʱѭ��
	return 0;
}
