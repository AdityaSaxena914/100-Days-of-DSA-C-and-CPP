// Creation, traversal, insetion of the circular linked list

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
    struct Node *ptr = node;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != node);
}

struct Node *insertAtfirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next!= head)
    {
        p = p->next;
    }
    // At this point p point to the end of the list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
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

    // Linking between Node and Node
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
    tenth->next = head;

    // Print the linked list
    printf("Circular Linked list before insertion: ");
    printList(head);

    // Insertion at the beginning
    head = insertAtfirst(head, 11);
    printf("\nCircular Linked list after insertion: ");
    printList(head);
    return 0;
}