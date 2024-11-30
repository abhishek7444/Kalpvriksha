#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.c"


int isOperand(char c)
{
    return c >= '0' && c <= '9';
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    return 2; 
}


char *toPostfix(char str2[])
{
    int l = strlen(str2);
    char *str = (char *)malloc(sizeof(char) * (2 * l + 1)); 
    struct stack s;
    s.top = -1;
    s.size = l;
    s.st = (long *)malloc(sizeof(long) * l);
    int k = 0;

    for (int i = 0; i < l; i++)
    {
        if (isOperand(str2[i]))
        {
            
            while (i < l && isOperand(str2[i]))
            {
                str[k++] = str2[i++];
            }
            str[k++] = ' '; // Add a space to separate numbers
            i--;            // Adjust loop index
        }
        else if (str2[i] == ' ')
        {
            continue; // Ignore spaces
        }
        else
        {
            while (!isempty(&s) && precedence(str2[i]) <= precedence((char)top(&s)))
            {
                str[k++] = (char)top(&s);
                str[k++] = ' '; 
                pop(&s);
            }
            push(&s, str2[i]);
        }
    }

    while (!isempty(&s))
    {
        str[k++] = (char)top(&s);
        str[k++] = ' ';
        pop(&s);
    }

    str[k] = '\0'; 
    free(s.st);
    return str;
}

long getAns(char str2[])
{
    char *str = toPostfix(str2);
    int a, b;
    int num = 0; 
    int l = strlen(str);
    struct stack s;
    s.size = l;
    s.top = -1;
    s.st = (long *)malloc(sizeof(long) * l);
    
    int isReadingNum = 0; 

    for (int i = 0; i < l; i++)
    {
        if (isOpernad(str[i]))
        {
            num = num * 10 + (str[i] - '0');
            isReadingNum = 1;
        }
        else if (str[i] == ' ')
        {
            if (isReadingNum)
            {
                push(&s, num); 
                num = 0;      
                isReadingNum = 0;
            }
        }
        else
        {
            b = top(&s);
            pop(&s);
            a = top(&s);
            pop(&s);
            switch (str[i])
            {
            case '+':
                push(&s, a + b);
                break;
            case '-':
                push(&s, a - b);
                break;
            case '*':
                push(&s, a * b);
                break;
            case '/':
                if (b == 0)
                {
                    printf("Error: Division by zero.\n");
                    free(s.st);
                    free(str);
                    return __INT32_MAX__;
                }
                push(&s, a / b);
                break;
            }
        }
    }

    long ans = top(&s);
    free(s.st);
    free(str);
    return ans;
}

int main()
{
    char str[100], str2[100];
    printf("Enter the Expression:");
    scanf("%[^\n]s", str);

    int l = strlen(str), k = 0;

    for (int i = 0; i < l; i++)
    {
        if (isOperand(str[i]) || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == ' ')
        {
            str2[k++] = str[i];
        }
    }

    str2[k] = '\0';

    long ans = getAns(str2);
    if (ans != __INT32_MAX__)
        printf("Result: %ld\n", ans);
    return 0;
}