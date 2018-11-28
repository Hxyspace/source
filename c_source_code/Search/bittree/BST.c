typedef struct BiTNode            //二叉树的二叉链表结点结构定义
{
	int data;
	struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;

//递归查找二叉排序树T中是否存在key
//指针f指向T的双亲，其初始化调用值为NULL
//若查找成功，则指针p指向该数据元素结点，并返回TRUE
//否则指针p指向查找路径上访问的最后一个结点，并返回false
Status SearchBST(BiTree T,int key,BiTree f,BiTree *p)
{
	if(!T)    //查找失败
	{
		*p = f;
		return FALSE;
	}
	else if(key == T->data)
	{
		*p = T;
		return TRUE;
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

//当二叉排序树T中不存在关键字等于key的数据元素时
//插入key并返回TRUE，否则返回FALSE
Status InsertBST(BiTree T,int key)
{
	BiTree p,s;
	if(!SearchBST(*T ,key ,NULL,&p))
	{
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
		else 
		{
			p->rchild = s;       //插入 s 为右孩子
		}
		return TRUE;
	}
	else
	{
		return FALSE;           //树中已有关键字相同的结点，不再插入
	}
}


//删除操作
Status DeketeBST(BiTree *T,int key)
{
	if(! *T)
	{
		return FALSE;
	}
	else
	{
		if(key == (*T->data))
		{
			return Delete(T);
		}
		else if(key<(*T)->data)
		{
			return DeleteBST(&(*T)->lchild,key);
		}
		else
		{
			return Delete(&(*T)->rchild,key);
		}
	}
}

Status Delete(BiTree *p)
{
	BiTree q,s;
	if((*p)->rchild == NULL)
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	
	else if((*p)->lchild == NULL)
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else
	{
		q = *p;
		s = (*p)->lchild;
		while(s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		
		(*p)->data = s->data;
		
		if(q != *p)
		{
			q->rchild = s->lchild;
		}
		else
		{
			q->lchild = s->lchild;
		}
		
		free(s);
	}