#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stack.c"

bool isOperand(char ch)
{
    return ch >= '0' && ch <= '9';
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

char *toPostfix(char *infix)
{
    int sizeOfInfixString = strlen(infix);
    char *postfixString = (char *)malloc((2 * sizeOfInfixString + 1) * sizeof(char));

    struct stack st;
    st.top = -1;
    st.size = sizeOfInfixString;
    st.arr = (int *)malloc(sizeOfInfixString * sizeof(int));

    int infixIndex = 0, postfixIndex = 0;

    while (infixIndex < sizeOfInfixString)
    {
        if (infix[infixIndex] == ' ')
        {
            infixIndex++;
            continue;
        }

        if (isOperand(infix[infixIndex]))
        {
            while (infixIndex < sizeOfInfixString && isOperand(infix[infixIndex]))
            {
                postfixString[postfixIndex++] = infix[infixIndex++];
            }
            postfixString[postfixIndex++] = ' ';
        }
        else
        {
            while (!isEmpty(&st) && precedence((char)top(&st)) >= precedence(infix[infixIndex]))
            {
                postfixString[postfixIndex++] = (char)top(&st);
                postfixString[postfixIndex++] = ' ';
                pop(&st);
            }
            push(&st, infix[infixIndex]);
            infixIndex++;
        }
    }

    while (!isEmpty(&st))
    {
        postfixString[postfixIndex++] = (char)top(&st);
        postfixString[postfixIndex++] = ' ';
        pop(&st);
    }

    if (postfixIndex > 0 && postfixString[postfixIndex - 1] == ' ')
    {
        postfixIndex--;
    }

    postfixString[postfixIndex] = '\0';
    free(st.arr);

    return postfixString;
}

int evalPostfixString(char *postfixString)
{
    struct stack st;
    int lenOfPostfixString = strlen(postfixString);
    st.top = -1;
    st.size = lenOfPostfixString;
    st.arr = (int *)malloc(lenOfPostfixString * sizeof(int));

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
            push(&st, num);
            num = 0; // Reset for the next operand
        }
        else
        {
            int b = top(&st);
            pop(&st);
            int a = top(&st);
            pop(&st);

            switch (postfixString[postfixIndex])
            {
            case '+':
                push(&st, a + b);
                break;
            case '-':
                push(&st, a - b);
                break;
            case '*':
                push(&st, a * b);
                break;
            case '/':
                if (b == 0)
                {
                    printf("Error: Division by zero\n");
                    free(st.arr);
                    return -1;
                }
                push(&st, a / b);
                break;
            }
            postfixIndex++;
        }
    }

    int ans = top(&st);
    free(st.arr);

    return ans;
}

int main()
{
    char infix[256];
    printf("Enter the string: ");
    scanf(" %[^\n]", infix);
    char *postfixString = toPostfix(infix);

    printf("Postfix: %s\n", postfixString);
    printf("Result: %d\n", evalPostfixString(postfixString));

    free(postfixString);
    return 0;
}
