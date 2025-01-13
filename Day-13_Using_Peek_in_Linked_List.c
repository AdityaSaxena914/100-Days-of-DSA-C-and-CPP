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

int Peek(int index)
{
    struct Node *p = top;
    for (int i = 0; (i < index - 1 && p != NULL); i++)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        return p->data;
    }
    else
    {
        printf("Index out of range\n");
        return -1;
    }
}

int stackTop(struct Node *node){
    return node->data;
}

int stackBottom(struct Node *node){
    struct Node *p = node;
    while(p->next!=NULL){
        p = p->next;
    }
    return p->data;
}

int main()
{
    int element;
    for (int i = 1; i <= 10; i++)
    {
        printf("Enter the Element to push: ");
        scanf("%d", &element);
        top = Push(top, element);
    }
    printf("\n");
    printf("Top element is %d\n",stackTop(top));
    printf("Bottom element is %d\n",stackBottom(top));
    printf("Element at index 5 is: %d", Peek(5));

    return 0;
}