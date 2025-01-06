// Deletion in Linked lists
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
struct Node * DeletionAtbeginning(struct Node *node)
{
    struct Node *ptr = node;
    node = node->next;
    free(ptr);
    return node;
};
struct Node * DeletionAtindex(struct Node *node, int index)
{
    struct Node *ptr = node;
    struct Node *p = node->next;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = p->next;
    free(p);
    return node;
};
struct Node * DeletionAtend(struct Node *node)
{
    struct Node *ptr = node;
    struct Node *p = node->next;
    while (p->next != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = NULL;
    free(p);
    return node;
};
struct Node*DeletionAtValue(struct Node *node, int value)
{
    struct Node *ptr = node;
    struct Node *p = node->next;
    while (p->data!=value && p->next!= NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }
    if (p->data == value)
    {
        ptr->next = p->next;
    }
    free(p);
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
    // Deletion at the beginning
    head = DeletionAtbeginning(head);
    printf("Linked list after Deletion: ");
    printList(head);
    printf("\n");
    // Deletion at index 3
    head = DeletionAtindex(head, 3);
    printf("Linked list after Deletion: ");
    printList(head);
    printf("\n");
    // Deletion at the end
    head = DeletionAtend(head);
    printf("Linked list after Deletion: ");
    printList(head);
    printf("\n");
    // Deletion at value
    head = DeletionAtValue(head, 9);
    printf("Linked list after insertion: ");
    printList(head);
    return 0;
}