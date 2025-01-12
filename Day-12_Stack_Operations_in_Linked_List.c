// implementing Stack operations Linked List Like Peek(), Pop(), Push(), isEmpty() and isFull()

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int isEmpty(struct Node *node)
{
    if (node == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *node)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct Node *Push(struct Node *node, int data)
{
    if (!isFull(node))
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = data;
        n->next = node;
        node = n;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

int Pop(struct Node *node)
{
    if (!isEmpty(node))
    {
        struct Node *n = node;
        top = node->next;
        int i = n->data;
        free(n);
        return i;
    }
    else
    {
        printf("Stack Underflow\n");
    }
}

int main()
{
    
    top = Push(top, 0);
    top = Push(top, 1);
    top = Push(top, 2);
    top = Push(top, 3);
    printList(top);
    int i = Pop(top);
    printf("\nPopped element is: %d\n", i);
    printList(top);
    return 0;
}