#include <stdio.h>   
int stack[1000],i,j,choice=0,n,top=-1;  

void push()  
{  
    int val;      
    if (top == n-1)   
        printf("\n Overflow");   
    else   
    {  
        printf("Enter the value?");  
        scanf("%d",&val);         
        top = top +1;   
        stack[top] = val;   
    }   
}   
  
void pop()   
{   
    if(top == -1)   
        printf("Underflow");  
    else  
        top = top -1;   
}   
int peek()  
{  
   return stack[top];
}
int size()
{
    return top+1;
}
int isEmpty()
{
    return top==-1;
}
int main ()  
{  
    printf("Enter the number of elements in the stack ");   
    scanf("%d",&n);  
  
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
                printf("%d",peak);
                break;  
            }  
            case 4:   
            {  
                int isempty = isEmpty();
                if(isempty)
                {
                    printf("Stack is Empty");
                }
                else
                    printf("Stack is Not Empty:");
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
  
