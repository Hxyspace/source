typedef struct BiTNode            //�������Ķ���������ṹ����
{
	int data;
	struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;

//�ݹ���Ҷ���������T���Ƿ����key
//ָ��fָ��T��˫�ף����ʼ������ֵΪNULL
//�����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE
//����ָ��pָ�����·���Ϸ��ʵ����һ����㣬������false
Status SearchBST(BiTree T,int key,BiTree f,BiTree *p)
{
	if(!T)    //����ʧ��
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
		return SearchBST(T->lchild,key,T,p);     //����������������
	}
	else
	{
		return SearchBST(T->rchild,key,T,p);     //����������������
	}
}

//������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ
//����key������TRUE�����򷵻�FALSE
Status InsertBST(BiTree T,int key)
{
	BiTree p,s;
	if(!SearchBST(*T ,key ,NULL,&p))
	{
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
		else 
		{
			p->rchild = s;       //���� s Ϊ�Һ���
		}
		return TRUE;
	}
	else
	{
		return FALSE;           //�������йؼ�����ͬ�Ľ�㣬���ٲ���
	}
}


//ɾ������
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