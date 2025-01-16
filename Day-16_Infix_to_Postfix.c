// Implementing parenthesis in stacks

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *ptr)
{
    return ptr->top == -1;
}
int isFull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}
void Push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("Stack is Overflowed, Cannot push %c in stack\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
char stackTop(struct stack *node)
{
    return node->arr[node->top];
}
char Pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Underflowed, Cannot pop from stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if (ch == '/' || ch == '*' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char *infixTopostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // track infix
    int j = 0; // track postfix
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                Push(sp, infix[i++]);
            }
            else
            {
                postfix[j++] = Pop(sp);
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j++] = Pop(sp);
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *string;
    printf("Enter a string: ");
    scanf("%s", string);
    printf("Postfix expression: %s\n", infixTopostfix(string));
    return 0;
}