// using Peek() for printing stacks

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

int Peek(struct stack *ptr, int i){
    int arrayIND = ptr->top - i + 1;
    if (arrayIND < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return ptr->arr[arrayIND];
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
    for (int j = 1; j <=s->top+1; j++)
    {
        printf("Element at position %d is %d\n", j, Peek(s, j));
    }
    printf("\n");
    return 0;
}
