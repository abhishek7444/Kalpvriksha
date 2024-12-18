struct Stack
{
    char *arr;
    int size;
    int top;
};

void push(struct Stack *stack, long ch)
{
    if (stack->top == stack->size - 1)
        return;
    stack->top++;
    stack->arr[stack->top] = ch;
}

void pop(struct Stack *stack)
{
    if (stack->top == -1)
        return;
    stack->top--;
}

int top(struct Stack *stack)
{
    if (stack->top == -1)
        return 0;
    return stack->arr[stack->top];
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}
