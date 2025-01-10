#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    return ptr->top == -1;
}
int isFull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}
void Push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack is Overflowed, Cannot push %d in stack\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int Pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Underflowed, Cannot pop from stack\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main()
{
    int value;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    for (int i = 0; i < s->size; i++)
    {
        printf("Enter %d value to push: ", i + 1);
        scanf("%d", &value);
        Push(s, value);
    }
    printf("\n");
    for (int i = s->size - 1; i >= -1; i--)
    {
        if (i!=-1)
        {
            printf("Element: %d is Popped\n", Pop(s));
        }
        else
        {
            printf("Stack is Underflowed, Cannot pop from stack");
        }
    }
    return 0;
}
