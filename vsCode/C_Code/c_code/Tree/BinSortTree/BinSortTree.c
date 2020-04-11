/* 二叉排序树
*
* 所有右子树都大于根结点，所有左子树都小于根结点
*
 */

#include<malloc.h>
#define true 1
#define false 0

typedef int status;

typedef struct BiTNode
{
    int data;
    struct BitNode *lchild, *rchild;
}BitNode, *BiTree;

status SearchBST(BiTree T, int key, BiTree f, BiTree *p)        //T为查找的树， f为data最接近key的节点， p存放查找到的节点
{
    if( !T )
    {
        *p = f;
        return false;
    }
    else if(key == T->data)     //查找成功
    {
        *p = T;

        return true;
    }
    else if (key < T->data)
    {
        return SearchBST(T->lchild, key, T, p);     //在左子树继续查找
    }
    else
    {
        return SearchBST(T->rchild, key, T, p);     //在右子树继续查找
    }
    
}

status InsertBST(BiTree *T, int key)
{
    BiTree p, s;
    if( !SearchBST(*T, key, NULL, &p) )     //当key不在树中时插入
    {
        s = (BiTree)malloc(sizeof(BitNode));
        s->data = key;
        s->lchild = s->rchild = NULL;

        if( !p )        //树为空时， s 直接作为根结点
        {
            *T = s;
        }
        else if(key < p->data)
        {
            p->lchild = s;          //如果key比data小，插入s为左孩子，否则为右孩子
        }
        else
        {
            p->rchild = s;
        }
        return true;
    }
    else
    {
        return false;
    }
    
}

status DeleteBST(BiTree *T, int key)
{
    if( !*T )
    {
        return false;
    }
    else
    {
        if(key == (*T)->data)
        {
            return Delete(T);
        }
        else if (key < (*T)->data)
        {
            return DeleteBST(&(*T)->lchild, key);
        }
        else
        {
            return DeleteBST(&(*T)->rchild, key);
        }
    }
    
}

status Delete(BiTree *p)
{
    BiTree q, s;

    if((*p)->rchild == NULL)        //如果没有右子树，直接把左子树接上去
    {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    else if ((*p)->lchild == NULL)  //如果没有左子树，直接把右子树接上去
    {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else
    {
        q = *p;
        s = (*p)->lchild;

        while (s->rchild)       //找到直接前驱，也就是左子树的最后一个右子树
        {
            q = s;
            s->rchild;
        }

        (*p)->data = s->data;       //只修改数据

        if(q != *p)
        {
            q->rchild = s->lchild;
        }
        else
        {
            q->lchild = s->lchild;      //如果q == *p 说明p的左子树没有右子树
        }
        
        free(s);
        
    }
    
    return true;
}