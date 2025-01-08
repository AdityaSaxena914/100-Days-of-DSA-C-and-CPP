#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to print the linked list forward
void printForward(struct Node *node)
{
    while (node != NULL) // Traverse until NULL
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

// Function to print the linked list backward
void printBackward(struct Node *node)
{
    while (node != NULL) // Traverse until NULL
    {
        printf(" %d ", node->data);
        node = node->prev;
    }
}

int main()
{
    // Allocate memory for nodes in the linked list in Heap
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *sixth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *seventh = (struct Node *)malloc(sizeof(struct Node));
    struct Node *eighth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ninth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *tenth = (struct Node *)malloc(sizeof(struct Node));

    // Link nodes together
    head->prev = NULL;
    head->data = 1;
    head->next = second;
    second->prev = head;
    second->data = 2;
    second->next = third;
    third->prev = second;
    third->data = 3;
    third->next = fourth;
    fourth->prev = third;
    fourth->data = 4;
    fourth->next = fifth;
    fifth->prev = fourth;
    fifth->data = 5;
    fifth->next = sixth;
    sixth->prev = fifth;
    sixth->data = 6;
    sixth->next = seventh;
    seventh->prev = sixth;
    seventh->data = 7;
    seventh->next = eighth;
    eighth->prev = seventh;
    eighth->data = 8;
    eighth->next = ninth;
    ninth->prev = eighth;
    ninth->data = 9;
    ninth->next = tenth;
    tenth->prev = ninth;
    tenth->data = 10;
    tenth->next = NULL;

    // Print the linked list
    printf("Doubly Linked list in forward: ");
    printForward(head);
    printf("\nDoubly Linked list in backward: ");
    printBackward(tenth);

    return 0;
}
