// Insertions in linked lists
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
struct Node*InsertionAtbeginning(struct Node *node, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = node;
    ptr->data = data;
    return ptr;
};
struct Node*InsertionAtindex(struct Node *node, int data, int index)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = node;
    int i=0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return node;
};
struct Node*InsertionAtend(struct Node *node, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = node;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return node;
};
struct Node*InsertionAfter(struct Node *node,struct Node *prevNode, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return node;
};
int main()
{
    // Allocate memory for nodes in the liked list in Heap
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
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = fifth;
    fifth->data = 5;
    fifth->next = sixth;
    sixth->data = 6;
    sixth->next = seventh;
    seventh->data = 7;
    seventh->next = eighth;
    eighth->data = 8;
    eighth->next = ninth;
    ninth->data = 9;
    ninth->next = tenth;
    tenth->data = 10;
    tenth->next = NULL;

    // Print the linked list
    printf("Linked list: ");
    printList(head);
    printf("\n");
    // Insert 11 at the beginning
    head = InsertionAtbeginning(head, 11);
    printf("Linked list after insertion: ");
    printList(head);
    printf("\n");
    // Insert 12 at index 3
    head = InsertionAtindex(head, 12, 3);
    printf("Linked list after insertion: ");
    printList(head);
    printf("\n");
    // Insert 13 at the end
    head = InsertionAtend(head, 13);
    printf("Linked list after insertion: ");
    printList(head);
    printf("\n");
    // Insert 14 after node with data 4
    head = InsertionAfter(head, fourth, 14);
    printf("Linked list after insertion: ");
    printList(head);
    return 0;
}