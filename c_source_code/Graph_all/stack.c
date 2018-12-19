
//����һ����ջ
int InitStack(SqStack *s)
{
	s->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!s->base)
		exit(0);
	s->top = s->base;           //ջ����ջ����ͬ
	s->stacksize = STACK_INIT_SIZE;
	return 1;
}

//��ջΪ��  �򷵻�1 ���򷵻�0
int StackEmpty(sqStack *s)
{
	if(s->top == s->base)
		return 1;
	else
		return 0;
}

//����Ԫ��eΪ��Ԫ�ص�ջ��Ԫ��
int push(SqStack *s,SElemType e)
{
	if(s->top - s->base >= s->stacksize)
	{
		s->base = (SElemType *)realloc(s->base,(s->stacksize +STACKINCREMENT) * sizeof(SElemType));
		if(!s->base)
			exit(0);
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	*(s->top)++ = e;
	return 1;
}

//��ջ  �ɹ�����1 ʧ�ܷ���0
int pop(sqStack *s,SElemType *e)
{
	if(s->top == s->base)
		return 0;
	*e = *--(s->top);
	return 1;
}