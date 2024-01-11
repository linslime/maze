//构造一个空栈
void InitStack(SqStack* S)
{
    S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    //if (!S->base)
        //exit(OVERFLOW);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
}

//销毁栈
void DestroyStack(SqStack* S)
{
    free(S->base);
    S->top = NULL;
    S->base = NULL;
    S->stacksize = 0;
}

//把S设为空栈
void ClearStack(SqStack* S)
{
    S->top = S->base;
}

//判断S是否为空栈
bool StackEmpty(SqStack S)
{
    if (S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

//返回栈的元素个数
int StackLength(SqStack S)
{
    return S.top - S.base;
}

//用e返回栈的栈顶元素
void GetTop(SqStack S, SElemType* e)
{
    if (S.top != S.base)
        //return ERROR;
        *e = *(S.top - 1);
}

//插入e为新的栈顶元素
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

//删除栈的栈顶元素，并用e返回其值
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


