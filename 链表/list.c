#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct Node
{
	ElemType data;               //������
	struct Node* next;           //ָ����
} LinkList;

LinkList* LinkListInit()                     //��ʼ��
{
	LinkList *L;
	L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
	return L;
}

int EmptyList(LinkList L)                 //�п�
{
	return (NULL == L.next);
}

Status ClearList(LinkList *L)            //���
{
	LinkList *p,*q;
	p = L->next;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
}

int ListLength(LinkList *L)            //�󳤶�
{
	LinkList *p;
	int i = 0;
	p = L->next;
	while(p)
	{
		p = p->next;
		++i;
	}
	return i;
}

Status GetElem(LinkList *L,int i,ElemType *e)        //��λ�ò���
{
	int j;
	LinkList *p;

	p = L->next;
	j = 1;
	while(p && j<i)
	{
		p = p->next;
		++j;
	}

	if(!p||j>i)
	{
		return ERROR;
	}
	*e = p->data;

	return OK;
}

int GetPosition(LinkList *L,ElemType e)          //��ֵ����
{
	int i = 1;
	LinkList *p;
	p = L->next;

	while(p)
	{
		if(e == p->data)
			break;
		p = p->next;
		++i;
	}
	if(!p)
	{
		return ERROR;
	}

	return i;

}

Status ListInsert(LinkList *L,int i,ElemType e)           //����
{
	int j;
	LinkList *p,*s;

	p = L;
	j = 1;

	while(p && j<i)          //����Ѱ�ҵ�i�����
	{
		p = p->next;
		++j;
	}
	
	if(!p||j>i)
	{
		return ERROR;
	}

	s = (LinkList *)malloc(sizeof(LinkList));
	s->data = e;

	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList *L,int i,ElemType *e)    //��λ��ɾ��
{
	int j;
	LinkList *p,*q;
	p = L;
	j=1;

	while(p->next && j<i)
	{
		p = p->next;
		++j;
	}
	if(!p || j>i)
	{
		return ERROR;
	}
	q = p->next;
	p->next = q->next;

	*e = q->data;

	free(q);
	return OK;
}

void ListShow(LinkList *L)          //��ʾ
{
	LinkList *p;
	p = L->next;
	while(p)
	{
		printf("[%d] ",p->data);
		p = p->next;
	}
	printf("\n\n");
}

void CreatListHead(LinkList *L,int n)             //������ͷ�巨��
{
	LinkList *p;
	int i;

	srand((unsigned)time(NULL));

	L->next = NULL;
	for(i=0;i<n;i++)
	{
		p = (LinkList *)malloc(sizeof(LinkList));
		p->data = rand()%100+1;
		p->next = L->next;
		L->next = p;
	}
}

void CreatListTail (LinkList *L,int n)             //������β�巨��
{
	LinkList *p,*r;
	int i;
	srand((unsigned)time(NULL));
	
	r = L;
	for(i=0;i<n;i++)
	{
		p = (LinkList*)malloc(sizeof(LinkList));
		p->data = rand()%100;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

void CreatListTailSQ (LinkList *L,int n)             //���򴴽���β�巨��
{
	LinkList *p,*r;
	int i,e;
	srand((unsigned)time(NULL));
	e = rand()%10;
	r = L;
	for(i=0;i<n;i++)
	{
		p = (LinkList*)malloc(sizeof(LinkList));
		p->data = e;
		r->next = p;
		r = p;
		e += rand()%35;
	}
	r->next = NULL;
}

Status ListInsertSQ(LinkList *L,ElemType e)           //�������
{
	LinkList *p,*s;
	p = L;

	while(p->next)          //�������� ֱ�����һ�����
	{
		if(p->next->data > e)
			break;
		p = p->next;
	}
	if(!p->next)                                  //����Ѿ������һ����㣬������ֱ�ӽӵ�����β��
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = e;
		p->next = s;
		s->next = NULL;
		return OK;
	}

	s = (LinkList *)malloc(sizeof(LinkList));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status InsertSQ()     //��������ִ��
{
	LinkList *H;
	int n;
	H = LinkListInit();
	CreatListTailSQ(H,12);
	printf("��������Ϊ��\n");
	ListShow(H);
	printf("��������Ҫ��������ݡ�\n");
	scanf("%d",&n);
	ListInsertSQ(H,n);
	printf("�������ݺ������Ϊ��\n");
	ListShow(H);
	
	return OK;

}

Status unionL()                 //�������ϲ�
{
	LinkList *p,*q;
	int e;
	p = LinkListInit();
	q = LinkListInit();
	CreatListTailSQ(p,8);
	_sleep(1000);
	CreatListTailSQ(q,11);
	ListShow(p);
	ListShow(q);
	while(p)
	{
		GetElem(p,1,&e);
		ListInsertSQ(q,e);
		p = p->next;
	}
	ListShow(q);
	return OK;
}

void Inverse(LinkList *L)            //����
{
	//����Ƚ������
	LinkList *p,*q,*r;
	p = L->next;
	q = p->next;
	while(q)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	L->next->next=NULL;
	L->next = p;
}



void Menu()                //�˵�
{

}

int main()
{
	//LinkList *L;
	//int n ;
	//L = LinkListInit();
	//CreatListTailSQ(L,10);
	////CreatListTail(L,10);
	//ListShow(L);
	//ListInsertSQ(L,500);
	////Inverse(L);
	//ListShow(L);
	//InsertSQ();
	unionL();

	return 0;
}