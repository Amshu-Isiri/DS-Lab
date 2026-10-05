#include <stdio.h>

char stack[50];
int top = -1;

void push(char x)
{
    top++;
    stack[top] = x;
}

char pop()
{
    char x;
    x = stack[top];
    top--;
    return x;
}

int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[50], postfix[50];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        if ((infix[i] >= 'A' && infix[i] <= 'Z') ||
            (infix[i] >= 'a' && infix[i] <= 'z'))
        {
            postfix[j] = infix[i];
            j++;
        }

        else if (infix[i] == '(')
        {
            push(infix[i]);
        }

        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }
            pop();
        }

        else
        {
            while (top != -1 &&
                   priority(stack[top]) >= priority(infix[i]))
            {
                postfix[j] = pop();
                j++;
            }

            push(infix[i]);
        }
    }

    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s", postfix);

    return 0;
}
