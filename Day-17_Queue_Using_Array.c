#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue *q)
{
    return (q->rear == q->size - 1);
}

int isEmpty(struct Queue *q)
{
    return ((q->front == -1 && q->rear == -1) || q->front > q->rear);
}

void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = value;
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    int value = q->arr[q->front];
    q->front++;
    return value;
}
int main()
{
    struct Queue q;
    q.size = 10;
    q.front = -1;
    q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int choice, value;

    while (1)
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Enqueue operation
            if (isFull(&q))
            {
                printf("Queue is Full. Cannot enqueue more elements.\n");
            }
            else
            {
                printf("Enter element to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
            }
            break;
        case 2: // Dequeue operation
            value = dequeue(&q);
            if (value != -1)
            {
                printf("Dequeued element: %d\n", value);
            }
            else
            {
                printf("Queue is Empty. Cannot dequeue.\n");
            }
            break;
        case 3: // Exit
            printf("Exiting...\n");
            free(q.arr);
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}