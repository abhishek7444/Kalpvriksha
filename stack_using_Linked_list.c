#include <stdio.h>   
#include<stdlib.h>
int count = 0;

typedef struct Node
{
    int val;
    struct Node* next;
}Node;

Node* top = NULL;
Node* createNode(int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
void push()  
{  
    int val; 
    printf("Enter the value?");  
    scanf("%d",&val);
    Node* newNode = createNode(val);
    count++;
    if(top==0)
    {
        top = newNode;
        return;
    }
    else   
    {  
        newNode->next = top;
        top = newNode;
    }   
}   
  
void pop()   
{   
    if(top==0) return;
    else
    {
        top = top->next;
        count--;
    }
}   


int peek()  
{  
    if(top!=0)
        return top->val;
}
int size()
{
    return count;
}
int isEmpty()
{
    return top==0;
}
int main ()  
{  
    int choice = 0;
    while(choice != 6)  
    {  
        printf("Enter the operation you want to Perform: \n");  
        printf("\n1.Push\n2.Pop\n3.Peek\n4.checkEmpty\n5.Size\n6.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
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
                int isempty = isEmpty();
                if(isempty)
                {
                    printf("Stack is Empty\n");
                }
                else
                    printf("Stack is Not Empty:\n");
                break;   
            }  
            case 5:
            {
                int s = size();
                printf("%d",s);
                break;
            }
            case 6:
            {
                printf("Exit..");
                break;
            }
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
        };  
    }  
    return 0;
}   
  
