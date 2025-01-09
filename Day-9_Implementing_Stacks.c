// Implementing stacks using arrays

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
    if (ptr->top == -1)
    {
        return 1;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
}
int main()
{
    // Creating a stack pointer 
    struct stack *s;
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    
    // Push operation
    s->arr[0] = 4;
    s->arr[1] = 5;
    s->arr[2] = 6;
    s->arr[3] = 7;
    s->arr[4] = 8;
    s->top++;

    // Check whether stack is empty
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is not empty\n");
    }
    // check whether stack is fully initialized
    if(isFull(s)){
        printf("Stack is full\n");
    }
    else{
        printf("Stack is not full\n");
    }
    return 0;
}