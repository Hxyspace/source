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

typedef struct BiTNode            //二叉树的二叉链表结点结构定义
{
	int data;
	struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;

int CreateSqTable(SqTable *L,recnode r[])
{
	int i,j,k,n;
	srand(time(0));
	L->length = 0;
	printf("请输入需要创建的表长：\n");
	scanf("%d",&n);
	for(i = 1;i<=n;i++)          //r[0] 用作标志位  不存数据
	{
		r[i].key = rand()%100 + 1;
		if(L->length == 0)              //如果顺序表中无数据，则直接将第一个数放进去
		{
			L->data[i] = r[i].key;
			L->length++;
		}
		else if(r[i].key >= L->data[L->length])      //如果新输入的值大于顺序表的最后一个数，则直接插在顺序表的最后
		{
			L->data[++L->length] = r[i].key;
		}
		else
		{
			for(j = 1;j<=L->length;j++)        //遍历顺序表
			{
				if(r[i].key < L->data[j])     //当新输入的值比顺序表内某个值小时，将新的值填充，该值之后的数据都向后移一位
				{
					L->length++;
					for(k = L->length;k > j;k--)
					{
						L->data[k] = L->data[k-1];      //向后移
					}
					L->data[j] = r[i].key;
					break;
				}
			}
			
		}
	}
	return 1;
}

void show(SqTable L,recnode r[])  //显示有序表和无序表
{
	int i;
	printf("有序表： ");
	for(i = 1;i<=L.length;i++)
	{
		printf("%d ",L.data[i]);
	}
	putchar('\n');
	printf("无序表： ");
	for(i = 1;i<=L.length;i++)
	{
		printf("%d ",r[i].key);
	}
	putchar('\n');
}

int UnordSearch(recnode r[],int n,keytype k)     //无序查找
{
	int i = n;
	r[0].key = k;
	while(r[i].key != k)
	{
		i--;
	}
	return i;
}

int bs1(SqTable *L,Elemtype k)          //折半算法查找 非递归
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
	if(!T)    //查找失败
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
		return SearchBST(T->lchild,key,T,p);     //在左子树继续查找
	}
	else
	{
		return SearchBST(T->rchild,key,T,p);     //在右子树继续查找
	}
}

//二叉排序树插入
void InsertBST(BiTree *T,int key)
{
	BiTree p,s;

	SearchBST(*T ,key ,NULL,&p);
	s = (BiTree)malloc(sizeof(BiTNode));
	s->data = key;
	s->lchild = s->rchild = NULL;

	if( !p )        //查找不到key
	{
		*T = s;     //插入 s 为新的根结点
	}
	else if(key < p->data)
	{
		p->lchild = s;       //插入 s 为左孩子

	}
	else if(key > p->data)
	{
		p->rchild = s;       //插入 s 为右孩子
	}
	else
	{
		s->rchild = p->rchild;
		p->rchild = s;       //插入 s 为右孩子
	}

}

void MiddleOrderTraverse(BiTree T)   //中序遍历
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
	printf("请输入要查找的数：\n");
	scanf("%d",&k);
	printf("请选择查找方式\n");
	printf("\t1.顺序查找\t2.折半查找（非递归）\t3.折半查找（递归）\t4.二叉排序数\n");
	scanf("%d",&i);
	while(i)
	{
		switch(i)
		{
		case 1:
			n = UnordSearch(r,L.length,k);
			if(n)
				printf("\n[%d]位于表中的第%d位\n",k,n);
			break;
		case 2:
			n = bs1(&L,k);
			if(n)
				printf("\n[%d]位于表中的第%d位\n",k,n);
			break;
		case 3:
			n = bs2(&L,1,L.length,k);
			if(n)
				printf("\n[%d]位于表中的第%d位\n",k,n);
			break;
		case 4:
			T = NULL;
			printf("要插入多少个数：");
			scanf("%d",&n);
			printf("\n请输入%d个数\n",n);
			while(n--)
			{
				scanf("%d",&k);
				InsertBST(&T,k);
			}
			printf("中序遍历输出二叉排序树\n");
			MiddleOrderTraverse(T);
			putchar('\n');
			break;
		default:printf("ssss");
		}
		printf("\t1.顺序查找\t2.折半查找（非递归）\t3.折半查找（递归）\t4.二叉排序数\n");
		scanf("%d",&i);
	}
	return 0;
}
