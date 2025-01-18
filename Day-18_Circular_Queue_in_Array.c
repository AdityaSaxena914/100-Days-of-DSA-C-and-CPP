#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct CircularQueue *q)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct CircularQueue *q)
{
    return ((q->front == -1 && q->rear == -1) || q->front > q->rear);
}

void enqueue(struct CircularQueue *q, int value)
{
    if (isFull(q))
    {
        printf("CircularQueue is Full\n");
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = value;
}

int dequeue(struct CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("CircularQueue is Empty\n");
    }
    q->front = (q->front + 1) % q->size;
    int value = q->arr[q->front];
    return value;
}
int main()
{
    struct CircularQueue q;
    q.size = 10;
    q.front = 0;
    q.rear = 0;
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
                printf("CircularQueue is Full. Cannot enqueue more elements.\n");
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
                printf("CircularQueue is Empty. Cannot dequeue.\n");
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