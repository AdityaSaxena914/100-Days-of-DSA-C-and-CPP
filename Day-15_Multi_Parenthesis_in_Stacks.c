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
    return node->top;
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    else if (a == '[' && b == ']')
        return 1;
    else if (a == '{' && b == '}')
        return 1;
    else
        return 0;
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

int parenthesisMatch(char *string)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = strlen(string);
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char popped_ch;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '(' || string[i] == '[' || string[i] == '{')
            Push(s, string[i]);
        else if (string[i] == ')' || string[i] == ']' || string[i] == '}')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            else
            {
                popped_ch = Pop(s);
                if (!match(popped_ch, string[i]))
                {
                    return 0;
                }
            }
        }
    }
    if (isEmpty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char *string;
    printf("Enter a string: ");
    scanf("%s", string);
    if (parenthesisMatch(string))
    {
        printf("Parentheses are balanced\n");
    }
    else
    {
        printf("Parentheses are not balanced\n");
    }

    return 0;
}
