#include<stdio.h>   
#include<stdlib.h>  
#define maxsize 100  

int front = -1, rear = -1;  
int queue[maxsize];  

void enque()  
{  
    int item;  
    printf("\nEnter the element\n");  
    scanf("\n%d",&item);      
    if(rear == maxsize-1)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    if(front == -1 && rear == -1)  
    {  
        front = 0;  
        rear = 0;  
    }  
    else   
    {  
        rear = rear+1;  
    }  
    queue[rear] = item;  
    printf("\nValue inserted ");  
      
}  
void deque()  
{  
    int item;   
    if (front == -1 || front > rear)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
              
    }  
    else  
    {  
        item = queue[front];  
        if(front == rear)  
        {  
            front = -1;  
            rear = -1 ;  
        }  
        else   
        {  
            front = front + 1;  
        }  
        printf("\nvalue deleted ");  
    }  
      
      
}  
      
int peek()
{
    if(front==-1)
    {
        return -1;
    }
    return queue[front];
    
}

int size()
{
    return rear-front+1;
}

int isEmpty()
{
    if(rear==-1|| front>rear) return 1;
    return 0;
}

int main ()  
{  
    int choice=0;   
    while(choice != 6)   
    {     
  
        printf("\n1.insert an element\n2.Delete an element\n3.Peek\n4.Size\n5.isEmpty\n6.Exit\n");  
        printf("\nEnter your choice ?");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:
            {
                enque();  
                break;  
            }
            case 2:  
            {
                deque();  
                break;  
            }
            case 3:  
            {
                int peak = peek();  
                printf("%d\n",peak);
                break;  
            }
            case 4:  
            {
                int s = size();
                printf("%d\n",s);
                break; 
            }
            case 5:
            {
                int isempty = isEmpty();
                if(isempty==1)
                {
                    printf("queue is empty\n");
                    
                }
                else
                {
                    printf("queue is not empty\n");
                }
                break;
            }
            case 6:
            {
                exit(0);
                break;
            }
            default:
            {
                printf("\nEnter valid choice??\n"); 
            }
        }  
    }  
    return 0;
}  
