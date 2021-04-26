#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int capacity;
    int rear, front;
    int *arr;
} queue;

int main()
{
    queue *q = NULL;

    q = createQueue(4);
    int item;

    while(1)
    {
        system("cls");
        printMetaDeta(q);

        switch(menu())
        {
        case 1:
            printf("Enter item -> ");
            scanf("%d",&item);
            enqueue(q, item);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            printf("Peek %d ",peek(q));
            break;
        case 4:
            viewList(q);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice!!!");
        }
        getch();
    }

    return 0;
}

void viewList(queue *q)
{
    int i;
    if(q->front >= 0)
        for(i = q->front; i <= q->rear; i++)
            printf("%d ", q->arr[i]);
    else
        printf("List is empty");
}

void printMetaDeta(queue *q)
{
    printf("Queue is empty? %s\n",isEmpty(q)? "Yes" : "No");
    printf("Queue is full? %s\n", isFull(q)? "Yes" : "No");
    printf("Queue has %d items\n",countItems(q));
}

int menu()
{
    int n;
    printf("\n1.Enqueue");
    printf("\n2.Dequeue");
    printf("\n3.Peek");
    printf("\n4.View List");
    printf("\n5.Exit");
    printf("\nEnter your choice ->");
    scanf("%d",&n);
    return n;
}
