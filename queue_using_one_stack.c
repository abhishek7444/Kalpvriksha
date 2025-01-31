#include <stdio.h>
#define size 5

typedef struct
{
    int stack[size];
    int top;
} queue;

void initializeStack(queue *queuePointer)
{
    queuePointer->top = -1;
}

int isEmpty(queue *queuePointer)
{
    return queuePointer->top == -1;
}

void push(queue *queuePointer, int data)
{
    if (queuePointer->top == size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        queuePointer->top++;
        queuePointer->stack[queuePointer->top] = data;
    }
}

int pop(queue *queuePointer)
{
    return queuePointer->stack[queuePointer->top--];
}

void enqueue(queue *queuePointer)
{
    int data;
    printf("Enter value\n");
    scanf("%d", &data);
    push(queuePointer, data);
}

int dequeue(queue *queuePointer)
{
    if (isEmpty(queuePointer))
    {
        printf("Queue is empty\n");
        return -1;
    }

    if (queuePointer->top == 0)
    {
        return pop(queuePointer);
    }
    int data = pop(queuePointer);
    int result = dequeue(queuePointer);
    push(queuePointer, data);
    return result;
}

int peek(queue *queuePointer)
{
    if (isEmpty(queuePointer))
    {
        return -1;
    }
    if (queuePointer->top == 0)
    {
        return queuePointer->stack[queuePointer->top];
    }
    int data = pop(queuePointer);
    int result = dequeue(queuePointer);
    push(queuePointer, data);
    return result;
}

int findSize(queue *queuePointer)
{
    if (isEmpty(queuePointer))
    {
        return -1;
    }
    return (queuePointer->top) + 1;
}
int main()
{
    queue myqueue;
    int data;
    initializeStack(&myqueue);
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
            data = dequeue(&myqueue);
            if (data != -1)
            {
                printf("Dequeued element is %d\n", data);
            }
            break;
        case 3:
            data = peek(&myqueue);
            if (data != -1)
            {
                printf("front element of queue is %d \n", data);
            }
            else
            {
                printf("Queue is empty\n");
            }
            break;
        case 4:
            data = isEmpty(&myqueue);
            if (data != -1)
            {
                printf("queue is not empty\n");
            }
            else
            {
                printf("queue is empty\n");
            }
            break;
        case 5:
            data = findSize(&myqueue);
            if (data != -1)
            {
                printf("size of queue is %d \n", data);
            }
            else
            {
                printf("size of queue is 0\n");
            }
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
