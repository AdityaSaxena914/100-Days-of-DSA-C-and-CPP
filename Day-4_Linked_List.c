#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

// Function to print the linked list

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;
    struct Node *seventh;
    struct Node *eighth;
    struct Node *ninth;
    struct Node *tenth;

    // Allocate memory for nodes in the liked list in Heap

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));
    seventh = (struct Node *)malloc(sizeof(struct Node));
    eighth = (struct Node *)malloc(sizeof(struct Node));
    ninth = (struct Node *)malloc(sizeof(struct Node));
    tenth = (struct Node *)malloc(sizeof(struct Node));

    // Link first node to second
    head->data = 1;
    head->next = second;

    // Link second node to third
    second->data = 2;
    second->next = third;

    // Link third node to fourth
    third->data = 3;
    third->next = fourth;

    // Link fourth node to fifth
    fourth->data = 4;
    fourth->next = fifth;

    // Link fifth node to sixth
    fifth->data = 5;
    fifth->next = sixth;

    // Link sixth node to seventh
    sixth->data = 6;
    sixth->next = seventh;

    // Link seventh node to eighth
    seventh->data = 7;
    seventh->next = eighth;

    // Link eighth node to ninth
    eighth->data = 8;
    eighth->next = ninth;

    // Link ninth node to tenth
    ninth->data = 9;
    ninth->next = tenth;

    // Terminate the Linked list of nodes
    tenth->data = 10;
    tenth->next = NULL;

    // Print the linked list
    printf("Linked list: ");
    printList(head);
    return 0;
}