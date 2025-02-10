// Queues using Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node *front = NULL;
struct Node *rear = NULL;
struct Node *n;

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *node)
{
    printf("\nLinked List: ");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void enqueue(int value)
{
    n = (struct Node *)malloc(sizeof(struct Node));

    if (n == NULL)
    {
        printf("Queue Overflow\n");
        return;
    }
    n->data = value;
    n->next = NULL;
    if (front == NULL)
    {
        front = rear = n;
        return;
    }
    rear->next = n;
    rear = n;
}

int dequeue()
{
    int val = -1;
    n = front;
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    front = front->next;
    val = n->data;
    free(n);
    return val;
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2: // Dequeue operation
            printf("Dequeued element: %d\n", dequeue());
            break;
        case 3:
            printList(front);
            break;
        case 4: // Exit
            printf("Exiting...\n");
            free(n);
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}