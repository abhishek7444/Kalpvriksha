
#include <stdio.h>
#include <stdlib.h>
#define max_size 5

struct queue {
    int arr[max_size];
    int front, rear, size;
};

struct Stack {
    struct queue Q;
};

int isQueueEmpty(struct queue *queuePointer) {
    return queuePointer->size == 0;
}

int isQueueFull(struct queue *queuePointer) {
    return queuePointer->size == max_size;
}

void enqueue(struct queue *queuePointer, int value) {
    if (isQueueFull(queuePointer)) {
        printf("Queue overflow!\n");
        return;
    }
    if (queuePointer->front == -1) {
        queuePointer->front = 0;
    }
    queuePointer->rear = (queuePointer->rear + 1) % max_size;
    queuePointer->arr[queuePointer->rear] = value;
    queuePointer->size++;
}

void dequeue(struct queue *queuePointer) {
    if (isQueueEmpty(queuePointer)) {
        printf("Queue underflow!\n");
        return;
    }
    if (queuePointer->front == queuePointer->rear) {
        queuePointer->front = queuePointer->rear = -1;
    } 
    else {
        queuePointer->front = (queuePointer->front + 1) % max_size;
    }
    queuePointer->size--;
}

int front(struct queue *queuePointer) {
    if (isQueueEmpty(queuePointer)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queuePointer->arr[queuePointer->front];
}

void push(struct Stack *stackPointer) {
    if (isQueueFull(&stackPointer->Q)) {
        printf("Stack overflow!\n");
        return;
    }

    int value;
    printf("Enter the value\n");
    scanf("%d", &value);

    enqueue(&stackPointer->Q, value);
    int initialSize = stackPointer->Q.size - 1;

    for (int i = 0; i < initialSize; i++) {
        int temp = front(&stackPointer->Q);
        dequeue(&stackPointer->Q);
        enqueue(&stackPointer->Q, temp);
    }
}

int peek(struct Stack *stackPointer) {
    if (isQueueEmpty(&stackPointer->Q)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return front(&stackPointer->Q);
}

void pop(struct Stack *stackPointer) {
    if (isQueueEmpty(&stackPointer->Q)) {
        printf("Stack underflow!\n");
        return;
    }

    printf("The removed value is %d.\n", peek(stackPointer));
    dequeue(&stackPointer->Q);
}

int size(struct Stack *stackPointer) {
    return stackPointer->Q.size;
}

void checkEmpty(struct Stack *stackPointer) {
    if (size(stackPointer) == 0) {
        printf("Stack is empty.\n");
    } 
    else {
        printf("Stack is not empty.\n");
    }
}

int main() {
    struct Stack myStack;
    
    myStack.Q.front = -1;
    myStack.Q.rear = -1;
    myStack.Q.size = 0;

    int choice;
    printf("1. Push element onto stack\n");
    printf("2. Pop element from stack\n");
    printf("3. Find top element of stack\n");
    printf("4. Check if stack is empty\n");
    printf("5. Find size of stack\n");
    printf("0. Exit\n");

    do {

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(&myStack);
                break;

            case 2:
                pop(&myStack);
                break;

            case 3:
                printf("The value at top is %d.\n", peek(&myStack));
                break;

            case 4:
                checkEmpty(&myStack);
                break;

            case 5:
                printf("The size of stack is %d.\n", size(&myStack));
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
