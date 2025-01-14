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

    for (int i = 0; i < s->size; i++)
    {
        if (string[i] == '(')
            Push(s, '(');
        else if (string[i] == ')')
        {
            if (isEmpty(s))
                return 0;
            else
                Pop(s);
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
    char * string;
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
