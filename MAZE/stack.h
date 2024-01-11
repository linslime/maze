//����һ����ջ
void InitStack(SqStack* S)
{
    S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    //if (!S->base)
        //exit(OVERFLOW);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
}

//����ջ
void DestroyStack(SqStack* S)
{
    free(S->base);
    S->top = NULL;
    S->base = NULL;
    S->stacksize = 0;
}

//��S��Ϊ��ջ
void ClearStack(SqStack* S)
{
    S->top = S->base;
}

//�ж�S�Ƿ�Ϊ��ջ
bool StackEmpty(SqStack S)
{
    if (S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

//����ջ��Ԫ�ظ���
int StackLength(SqStack S)
{
    return S.top - S.base;
}

//��e����ջ��ջ��Ԫ��
void GetTop(SqStack S, SElemType* e)
{
    if (S.top != S.base)
        //return ERROR;
        *e = *(S.top - 1);
}

//����eΪ�µ�ջ��Ԫ��
void Push(SqStack* S, SElemType e)
{
    if (S->top - S->base >= S->stacksize)
    {
        S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        //if (!S->base)
            //return OVERFLOW;
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top++ = e;
}

//ɾ��ջ��ջ��Ԫ�أ�����e������ֵ
void Pop(SqStack* S, SElemType* e)
{
    if (S->top != S->base)
        *e = *(--S->top);
}

void StackTraverse(SqStack S)
{
    SElemType* p;
    p = S.base;
    while (p != S.top)
    {
        Push(&minroute, *p);
        p++;
    }
}

void visit(SElemType e)
{

}


