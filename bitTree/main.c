#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

//线索存储标志位
//Link(0);表示指向左右孩子的指针
//Thread(1);表示指向前驱后继的线索
typedef enum {Link,Thread} PointerNag;

typedef struct BiThrNode
{
    ElemType data;
    struct BiThrNode *lchild,*rchild;
    PointerNag ltag;
    PointerNag rtag;
} BiThrNode,*BiThree;

//全局变量，始终指向刚刚访问过的结点
BiThree pre;

//创建一棵二叉树
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
//中序遍历线索化
InThreading(BiThree T)
{
    if(T)
    {
        InThreading( T->lchild ) ;          //递归左孩子线索化

        if( !T->lchild )              //如果该结点没有左孩子，设置ltag 为Thread，并把lchild指向刚刚访问的结点
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

        InThreading( T->rchild );            //递归右孩子线索化
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
