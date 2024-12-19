#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stack.c"

bool isOperand(char character)
{
    return character >= '0' && character <= '9';
}

int precedence(char ch)
{
    int priority = 0;
    if (ch == '*' || ch == '/')
        priority = 2;
    
    if (ch == '+' || ch == '-')
        priority = 1;

    return priority;
    
}

char *toPostfix(char *infixString)
{
    int sizeOfInfixString = strlen(infixString);
    char *postfixString = (char *)malloc((2 * sizeOfInfixString + 1) * sizeof(char));

    struct Stack stack;
    stack.top = -1;
    stack.size = sizeOfInfixString;
    stack.arr = (int *)malloc(sizeOfInfixString * sizeof(int));

    int infixIndex = 0, postfixIndex = 0;

    while (infixIndex < sizeOfInfixString)
    {
        if (infixString[infixIndex] == ' ')
        {
            infixIndex++;
            continue;
        }

        if (isOperand(infixString[infixIndex]))
        {
            while (infixIndex < sizeOfInfixString && isOperand(infixString[infixIndex]))
            {
                postfixString[postfixIndex++] = infixString[infixIndex++];
            }
            postfixString[postfixIndex++] = ' ';
        }
        else
        {
            while (!isEmpty(&stack) && precedence((char)top(&stack)) >= precedence(infixString[infixIndex]))
            {
                postfixString[postfixIndex++] = (char)top(&stack);
                postfixString[postfixIndex++] = ' ';
                pop(&stack);
            }
            push(&stack, infixString[infixIndex]);
            infixIndex++;
        }
    }

    while (!isEmpty(&stack))
    {
        postfixString[postfixIndex++] = (char)top(&stack);
        postfixString[postfixIndex++] = ' ';
        pop(&stack);
    }

    if (postfixIndex > 0 && postfixString[postfixIndex - 1] == ' ')
    {
        postfixIndex--;
    }

    postfixString[postfixIndex] = '\0';
    free(stack.arr);

    return postfixString;
}

int evalPostfixString(char *postfixString)
{
    struct Stack stack;
    int lenOfPostfixString = strlen(postfixString);
    stack.top = -1;
    stack.size = lenOfPostfixString;
    stack.arr = (int *)malloc(lenOfPostfixString * sizeof(int));

    int postfixIndex = 0;
    int num = 0;

    while (postfixIndex < lenOfPostfixString)
    {
        if (postfixString[postfixIndex] == ' ')
        {
            postfixIndex++;
            continue;
        }
        if (isOperand(postfixString[postfixIndex]))
        {
            while (postfixIndex < lenOfPostfixString && isOperand(postfixString[postfixIndex]))
            {
                num = num * 10 + (postfixString[postfixIndex] - '0');
                postfixIndex++;
            }
            push(&stack, num);
            num = 0; 
        }
        else
        {
            int b = top(&stack);
            pop(&stack);
            int a = top(&stack);
            pop(&stack);

            switch (postfixString[postfixIndex])
            {
            case '+':
                push(&stack, a + b);
                break;
            case '-':
                push(&stack, a - b);
                break;
            case '*':
                push(&stack, a * b);
                break;
            case '/':
                if (b == 0)
                {
                    printf("Error: Division by zero\n");
                    free(stack.arr);
                    return 0;
                }
                push(&stack, a / b);
                break;
            }
            postfixIndex++;
        }
    }

    int ans = top(&stack);
    free(stack.arr);

    return ans;
}

int main()
{
    char infixString[256];
    printf("Enter the string: ");
    scanf(" %[^\n]", infixString);
    char *postfixString = toPostfix(infixString);

    printf("Postfix: %s\n", postfixString);
    printf("Result: %d\n", evalPostfixString(postfixString));

    free(postfixString);
    return 0;
}
