struct stack
{
    long *st;
    int size;
    int top;
};

void push(struct stack *stk, long ch)
{
    if (stk->top == stk->size - 1)
        return;
    stk->top++;
    stk->st[stk->top] = ch;
}

void pop(struct stack *stk)
{
    if (stk->top == -1)
        return;
    stk->top--;
}

long top(struct stack *stk)
{
    if (stk->top == -1)
        return '\0';
    return stk->st[stk->top];
}

int isempty(struct stack *stk)
{
    return stk->top == -1;
}
