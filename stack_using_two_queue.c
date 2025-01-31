#include <stdio.h>
#define MAX_SIZE 5

struct Queue
{
    int arr[MAX_SIZE];
    int front, rear;
};

struct Stack
{
    struct Queue Queue1, Queue2;
    int size;
};

int isEmptyQueue(struct Queue *queuePointer)
{
    return queuePointer->front == -1;
}

void enqueue(struct Queue *queuePointer, int value)
{
    if (queuePointer->rear == MAX_SIZE - 1)
    {
        printf("Queue overflow!\n");
        return;
    }
    if (queuePointer->front == -1)
    {
        queuePointer->front = 0;
    }
    queuePointer->rear++;
    queuePointer->arr[queuePointer->rear] = value;
}

void dequeue(struct Queue *queuePointer)
{
    if (isEmptyQueue(queuePointer))
    {
        printf("Queue underflow!\n");
        return;
    }
    int data = queuePointer->arr[queuePointer->front];
    if (queuePointer->front == queuePointer->rear)
    {
        queuePointer->front = queuePointer->rear = -1;
    }
    else
    {
        queuePointer->front++;
    }
}

int front(struct Queue *queuePointer)
{
    if (!isEmptyQueue(queuePointer))
    {
        return queuePointer->arr[queuePointer->front];
    }
    return -1; 
}

void push(struct Stack *stackPointer)
{
    if (stackPointer->size == MAX_SIZE)
    {
        printf("Stack overflow!\n");
        return;
    }
    int value;
    printf("Enter the value:\n");
    scanf("%d", &value);
    stackPointer->size++;
    enqueue(&stackPointer->Queue2, value);
    while (!isEmptyQueue(&stackPointer->Queue1))
    {
        enqueue(&stackPointer->Queue2, front(&stackPointer->Queue1));
        dequeue(&stackPointer->Queue1);
    }

    struct Queue temp = stackPointer->Queue1;
    stackPointer->Queue1 = stackPointer->Queue2;
    stackPointer->Queue2 = temp;
}

void pop(struct Stack *stackPointer)
{
    if (isEmptyQueue(&stackPointer->Queue1))
    {
        printf("Stack underflow!\n");
        return;
    }
    stackPointer->size--;
    dequeue(&stackPointer->Queue1);
}

int peek(struct Stack *stackPointer)
{
    if (isEmptyQueue(&stackPointer->Queue1))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return front(&stackPointer->Queue1);
}

int size(struct Stack *stackPointer)
{
    return stackPointer->size;
}

void isEmpty(struct Stack *stackPointer)
{
    if (size(stackPointer) == 0)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack is not empty.\n");
}

int main()
{
    struct Stack myStack = {.size = 0};
    myStack.Queue1.front = myStack.Queue1.rear = -1;
    myStack.Queue2.front = myStack.Queue2.rear = -1;

    int choice;
    printf("1. Push element onto stack\n");
    printf("2. Pop element from stack\n");
    printf("3. Find top element of stack\n");
    printf("4. Check if stack is empty\n");
    printf("5. Find size of stack\n");
    printf("0. Exit\n");
    do
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(&myStack);
            break;

        case 2:
            pop(&myStack);
            break;

        case 3:
            printf("The value at top of stack is %d.\n", peek(&myStack));
            break;

        case 4:
            isEmpty(&myStack);
            break;

        case 5:
            printf("The size of the stack is %d.\n", size(&myStack));
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 0);
    return 0;
}
