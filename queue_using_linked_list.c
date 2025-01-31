#include<stdio.h>   
#include<stdlib.h>  
#define maxsize 100  
int count = 0;
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* front = NULL;
Node* rear = NULL;
void enqueue()  
{  
    int item;  
    printf("\nEnter the element\n");  
    scanf("\n%d",&item);
    Node* newNode = createNode(item);
    count++;
    if(front==0 && rear==0)
    {
        front  = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

}  


void dequeue()  
{  
    if(front==0)
    {
        printf("queue is empty: \n");
        return;
    }
    else
    {
        count--;
        front = front->next;
    }
}  
      
int peek()
{
    return front==0?-1 : front->data;
}

int size()
{
    return count;
}

int isEmpty()
{
   if(front==0)
   {
       return 1;
   }
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
                enqueue();  
                break;  
            }
            case 2:  
            {
                dequeue();  
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
