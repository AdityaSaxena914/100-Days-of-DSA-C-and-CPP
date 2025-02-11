// Implementing double ended queue using array

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
    return (q->front == 0 && q->rear == q->size - 1) || (q->front == q->size + 1);
}

int isEmpty(struct Queue *q)
{
    return (q->front == -1 && q->rear == -1);
}

void printQueue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }
    int i = q->front;
    while (1)
    {
        printf("%d ", q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

void enqueueRear(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    q->rear++;
    q->arr[q->rear] = value;
}
void enqueueFront(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->front = (q->front - 1 + q->size) % q->size;
    }
    q->arr[q->front] = value;
}

int dequeueFront(struct Queue *q)
{
    if (isEmpty(q))
    {
        return q->front = q->rear = -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1; // Reset when queue becomes empty
    }
    else
    {
        q->front = (q->front + 1) % q->size;
    }
    return value;
}

int dequeueRear(struct Queue *q)
{
    if (isEmpty(q))
    {
        return q->front = q->rear = -1;
    }
    int value = q->arr[q->rear];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1; // Reset when queue becomes empty
    }
    else
    {
        q->rear = (q->rear - 1 + q->size) % q->size;
    }
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
        printf("1. Enqueue from Front\n");
        printf("2. Enqueue from Rear\n");
        printf("3. Dequeue from Front\n");
        printf("4. Dequeue from Rear\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Enqueue from front operation
            if (isFull(&q))
            {
                printf("Queue is Full. Cannot enqueue more elements.\n");
            }
            else
            {
                printf("Enter element to enqueue: ");
                scanf("%d", &value);
                enqueueFront(&q, value);
            }
            break;
        case 2: // Enqueue from rear operation
            if (isFull(&q))
            {
                printf("Queue is Full. Cannot enqueue more elements.\n");
            }
            else
            {
                printf("Enter element to enqueue: ");
                scanf("%d", &value);
                enqueueRear(&q, value);
            }
            break;
        case 3: // Dequeue from front operation
            value = dequeueFront(&q);
            if (value != -1)
            {
                printf("Dequeued element: %d\n", value);
            }
            else
            {
                printf("Queue is Empty. Cannot dequeue.\n");
            }
            break;
        case 4: // Dequeue from rear operation
            value = dequeueRear(&q);
            if (value != -1)
            {
                printf("Dequeued element: %d\n", value);
            }
            else
            {
                printf("Queue is Empty. Cannot dequeue.\n");
            }
            break;
        case 5: // Display queue operation
            printQueue(&q);
            break;
        case 6: // Exit
            printf("Exiting...\n");
            free(q.arr);
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}