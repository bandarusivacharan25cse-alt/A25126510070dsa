#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue is Full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        queue[rear] = value;

        printf("Inserted: %d\n", value);
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Deleted: %d\n", queue[front]);

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");

    for (i = front; i != rear; i = (i + 1) % SIZE)
    {
        printf("%d ", queue[i]);
    }

    printf("%d\n", queue[rear]);
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Circular Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}