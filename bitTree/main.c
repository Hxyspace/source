#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

//�����洢��־λ
//Link(0);��ʾָ�����Һ��ӵ�ָ��
//Thread(1);��ʾָ��ǰ����̵�����
typedef enum {Link,Thread} PointerNag;

typedef struct BiThrNode
{
    ElemType data;
    struct BiThrNode *lchild,*rchild;
    PointerNag ltag;
    PointerNag rtag;
} BiThrNode,*BiThree;

//ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��
BiThree pre;

//����һ�ö�����
CreataBiThrTree(BiThree *T)
{
    char c;

    scanf("%c",&c);
    if(' ' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiThrNode *)malloc(sizeof(BiThrNode));
        (*T)->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;

        CreataBiThrTree(&(*T)->lchild);
        CreataBiThrTree(&(*T)->rchild);

    }
}
//�������������
InThreading(BiThree T)
{
    if(T)
    {
        InThreading( T->lchild ) ;          //�ݹ�����������

        if( !T->lchild )              //����ý��û�����ӣ�����ltag ΪThread������lchildָ��ոշ��ʵĽ��
        {
            T->ltag = Thread;
            T->lchild = pre;
        }

        if( !pre->rchild )
        {
            pre->rtag = Thread;
            pre->rchild = T;
        }

        pre = T;

        InThreading( T->rchild );            //�ݹ��Һ���������
    }
}

InOrderThreading(BiThree *p,BiThree T)
{
    *p = (BiThree)malloc(sizeof(BiThrNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild = *p;
    if(!T)
    {
        (*p)->lchild = *p;
    }
    else
    {
        (*p)->lchild = T;
        pre = *p;
        InThreading(T);
        pre->rchild = *p;
        pre->rtag = Thread;
        (*p)->rchild = pre;
    }
}
int main()
{
    BiThree p,T = NULL;

    CreataBiThrTree( &T );

    InOrderThreading (&p,T);

    return 0;
}
