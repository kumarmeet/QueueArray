#include <stdio.h>
#include <stdlib.h>

typedef struct QUEUE
{
    int capacity;
    int rear, front;
    int *arr;
} queue;

int peek(queue *q)
{
    if(isEmpty(q))
        printf("Underflow");
    else
        return q->arr[q->front];
}

int countItems(queue *q)
{
    int a = q->rear + 1;
    return a;
}

int isFull(queue *q)
{
    return (q->front == 0 && q->rear == q->capacity - 1
            || q->front == q->rear + 1) ? 1 : 0;
}

int isEmpty(queue *q)
{
    return (q->rear == -1) ? 1 : 0;
}

void dequeue(queue *q)
{
    if(q->front == -1)
        printf("Underflow");
    else if(q->front == q->rear)
        q->rear = q->front = -1;
    else if(q->front == q->capacity - 1)
        q->front = 0;
    else
        q->front += 1;
}

//below code is mine concept
//void dequeue(queue *q)
//{
//    if(q->front == -1 || q->front > q->rear)
//    {
//        printf("Underflow");
//    }
//    else if(q->front == 0 || q->front <= q->rear + 1)
//    {
//        q->arr[q->front];
//        q->front += 1;
//        if(q->front == q->rear + 1)
//        {
//            q->rear = q->front = -1;
//            printf("Queue is empty");
//        }
//    }
//}

void enqueue(queue *q, int value)
{
    if(isFull(q))
        printf("Overflow");
    else if(q->rear == -1)
    {
        q->front = q->rear = 0;
        q->arr[q->rear] = value;
    }
    else if(q->rear == q->capacity - 1)
    {
        q->rear = 0;
        q->arr[q->rear] = value;
    }
    else
    {
        q->rear += 1;
        q->arr[q->rear] = value;
    }
}

queue * createQueue(int cap)
{
    queue *q;
    q = (queue*)malloc(sizeof(queue));
    q->capacity = cap;
    q->rear = q->front = -1;
    q->arr = (int*)malloc(sizeof(int) * cap);
    return q;
}
