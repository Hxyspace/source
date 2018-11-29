#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define MAXSIZE 100
typedef int keytype;
typedef int Elemtype;

typedef struct
{
	keytype key;
} recnode;

typedef struct
{
	Elemtype data[MAXSIZE];
	int length;
}SqTable;

typedef struct BiTNode            //�������Ķ���������ṹ����
{
	int data;
	struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;

int CreateSqTable(SqTable *L,recnode r[])
{
	int i,j,k,n;
	srand(time(0));
	L->length = 0;
	printf("��������Ҫ�����ı���\n");
	scanf("%d",&n);
	for(i = 1;i<=n;i++)          //r[0] ������־λ  ��������
	{
		r[i].key = rand()%100 + 1;
		if(L->length == 0)              //���˳����������ݣ���ֱ�ӽ���һ�����Ž�ȥ
		{
			L->data[i] = r[i].key;
			L->length++;
		}
		else if(r[i].key >= L->data[L->length])      //����������ֵ����˳�������һ��������ֱ�Ӳ���˳�������
		{
			L->data[++L->length] = r[i].key;
		}
		else
		{
			for(j = 1;j<=L->length;j++)        //����˳���
			{
				if(r[i].key < L->data[j])     //���������ֵ��˳�����ĳ��ֵСʱ�����µ�ֵ��䣬��ֵ֮������ݶ������һλ
				{
					L->length++;
					for(k = L->length;k > j;k--)
					{
						L->data[k] = L->data[k-1];      //�����
					}
					L->data[j] = r[i].key;
					break;
				}
			}
			
		}
	}
	return 1;
}

void show(SqTable L,recnode r[])  //��ʾ�����������
{
	int i;
	printf("����� ");
	for(i = 1;i<=L.length;i++)
	{
		printf("%d ",L.data[i]);
	}
	putchar('\n');
	printf("����� ");
	for(i = 1;i<=L.length;i++)
	{
		printf("%d ",r[i].key);
	}
	putchar('\n');
}

int UnordSearch(recnode r[],int n,keytype k)     //�������
{
	int i = n;
	r[0].key = k;
	while(r[i].key != k)
	{
		i--;
	}
	return i;
}

int bs1(SqTable *L,Elemtype k)          //�۰��㷨���� �ǵݹ�
{
	int low,mid,high;
	low = 1;
	high = L->length;
	while(low<=high)
	{
		mid = (low + high)/2;
		if(k == L->data[mid])
			return mid;
		else if(k < L->data[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

int bs2(SqTable *L,int low,int high,Elemtype k)
{
	int mid;
	if(low > high)
		return 0;
	mid = (low + high)/2;
	if(k == L->data[mid])
		return mid;
	else if(k < L->data[mid])
		return bs2(L,low,mid - 1,k);
	else
		return bs2(L,mid + 1,high,k);
}

int SearchBST(BiTree T,int key,BiTree f,BiTree *p)
{
	if(!T)    //����ʧ��
	{
		*p = f;
		return 0;
	}
	else if(key == T->data)
	{
		*p = T;
		return 1;
	}
	else if(key < T->data)
	{
		return SearchBST(T->lchild,key,T,p);     //����������������
	}
	else
	{
		return SearchBST(T->rchild,key,T,p);     //����������������
	}
}

//��������������
void InsertBST(BiTree *T,int key)
{
	BiTree p,s;

	SearchBST(*T ,key ,NULL,&p);
	s = (BiTree)malloc(sizeof(BiTNode));
	s->data = key;
	s->lchild = s->rchild = NULL;

	if( !p )        //���Ҳ���key
	{
		*T = s;     //���� s Ϊ�µĸ����
	}
	else if(key < p->data)
	{
		p->lchild = s;       //���� s Ϊ����

	}
	else if(key > p->data)
	{
		p->rchild = s;       //���� s Ϊ�Һ���
	}
	else
	{
		s->rchild = p->rchild;
		p->rchild = s;       //���� s Ϊ�Һ���
	}

}

void MiddleOrderTraverse(BiTree T)   //�������
{
	if(T)
	{
		MiddleOrderTraverse(T->lchild);
		printf("%d ",T->data);
		MiddleOrderTraverse(T->rchild);
	}
}

int main()
{
	int i,k,n;
	SqTable L;
	recnode r[MAXSIZE];
	BiTree T;
	CreateSqTable(&L,r);
	show(L,r);
	printf("������Ҫ���ҵ�����\n");
	scanf("%d",&k);
	printf("��ѡ����ҷ�ʽ\n");
	printf("\t1.˳�����\t2.�۰���ң��ǵݹ飩\t3.�۰���ң��ݹ飩\t4.����������\n");
	scanf("%d",&i);
	while(i)
	{
		switch(i)
		{
		case 1:
			n = UnordSearch(r,L.length,k);
			if(n)
				printf("\n[%d]λ�ڱ��еĵ�%dλ\n",k,n);
			break;
		case 2:
			n = bs1(&L,k);
			if(n)
				printf("\n[%d]λ�ڱ��еĵ�%dλ\n",k,n);
			break;
		case 3:
			n = bs2(&L,1,L.length,k);
			if(n)
				printf("\n[%d]λ�ڱ��еĵ�%dλ\n",k,n);
			break;
		case 4:
			T = NULL;
			printf("Ҫ������ٸ�����");
			scanf("%d",&n);
			printf("\n������%d����\n",n);
			while(n--)
			{
				scanf("%d",&k);
				InsertBST(&T,k);
			}
			printf("��������������������\n");
			MiddleOrderTraverse(T);
			putchar('\n');
			break;
		default:printf("ssss");
		}
		printf("\t1.˳�����\t2.�۰���ң��ǵݹ飩\t3.�۰���ң��ݹ飩\t4.����������\n");
		scanf("%d",&i);
	}
	return 0;
}
