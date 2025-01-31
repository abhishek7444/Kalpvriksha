
#include <stdio.h>
#include <stdbool.h>
#define size 5

typedef struct
{
    int stack1[size];
    int stack2[size];
    int top1;
    int top2;
    int count;
} Queue;

void initializeQueue(Queue *queuePointer)
{
    queuePointer->top1 = -1;
    queuePointer->top2 = -1;
    queuePointer->count = 0;
}

void push1(Queue *queuePointer, int data)
{
    if (queuePointer->top1 == size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        queuePointer->top1++;
        queuePointer->stack1[queuePointer->top1] = data;
    }
}

void push2(Queue *queuePointer, int data)
{
    if (queuePointer->top2 == size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        queuePointer->top2++;
        queuePointer->stack2[queuePointer->top2] = data;
    }
}

int pop1(Queue *queuePointer)
{
    return queuePointer->stack1[queuePointer->top1--];
}

int pop2(Queue *queuePointer)
{
    return queuePointer->stack2[queuePointer->top2--];
}

void enqueue(Queue *queuePointer)
{
    int data;
    printf("Enter value\n");
    scanf("%d", &data);
    push1(queuePointer, data);
    queuePointer->count++;
}

void dequeue(Queue *queuePointer)
{
    if (queuePointer->top1 == -1 && queuePointer->top2 == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        for (int index = 0; index < queuePointer->count; index++)
        {
            int popped1 = pop1(queuePointer);
            push2(queuePointer, popped1);
        }
        int popped2 = pop2(queuePointer);
        queuePointer->count--;
        printf("Popped element is %d ", popped2);
        for (int index = 0; index < queuePointer->count; index++)
        {
            int popped2 = pop2(queuePointer);
            push1(queuePointer, popped2);
        }
    }
    printf("\n");
}

void peek(Queue *queuePointer)
{
    if (queuePointer->top1 == -1 && queuePointer->top2 == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int index = 0; index < queuePointer->count; index++)
        {
            int popped1 = pop1(queuePointer);
            push2(queuePointer, popped1);
        }
        printf("front element of queue is %d ", queuePointer->stack2[queuePointer->top2]);
        for (int index = 0; index < queuePointer->count; index++)
        {
            int popped2 = pop2(queuePointer);
            push1(queuePointer, popped2);
        }
    }
    printf("\n");
}

void findSize(Queue *queuePointer)
{
    printf("Size of queue is %d ", queuePointer->count);
    printf("\n");
}

bool isEmpty(Queue *queuePointer)
{
    if (queuePointer->top1 == -1 && queuePointer->top2 == -1)
    {
        return true;
    }
    return false;
}

int main()
{
    Queue myqueue;
    bool empty;
    initializeQueue(&myqueue);
    int choice;
    printf("1. push element in queue\n");
    printf("2. pop an element from queue\n");
    printf("3. find front element of queue\n");
    printf("4. check queue is empty or not\n");
    printf("5. find size of queue\n");
    printf("for exit enter 0\n");
    do
    {

        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&myqueue);
            break;
        case 2:
            dequeue(&myqueue);
            break;
        case 3:
            peek(&myqueue);
            break;
        case 4:
            empty = isEmpty(&myqueue);
            if (empty)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;
        case 5:
            findSize(&myqueue);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Enter a valid choice\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
