
//构造一个空栈
int InitStack(SqStack *s)
{
	s->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!s->base)
		exit(0);
	s->top = s->base;           //栈顶和栈底相同
	s->stacksize = STACK_INIT_SIZE;
	return 1;
}

//若栈为空  则返回1 否则返回0
int StackEmpty(sqStack *s)
{
	if(s->top == s->base)
		return 1;
	else
		return 0;
}

//插入元素e为新元素的栈顶元素
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

//出栈  成功返回1 失败返回0
int pop(sqStack *s,SElemType *e)
{
	if(s->top == s->base)
		return 0;
	*e = *--(s->top);
	return 1;
}