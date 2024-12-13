struct stack
{
    int *arr;
    int size;
    int top;
};

void push(struct stack *st, long ch)
{
    if (st->top == st->size - 1)
        return;
    st->top++;
    st->arr[st->top] = ch;
}

void pop(struct stack *st)
{
    if (st->top == -1)
        return;
    st->top--;
}

int top(struct stack *st)
{
    if (st->top == -1)
        return '\0';
    return st->arr[st->top];
}

int isEmpty(struct stack *st)
{
    return st->top == -1;
}
