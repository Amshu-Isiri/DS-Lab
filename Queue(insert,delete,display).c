#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert()
{
    int value;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        printf("%d inserted into the queue.\n", value);
    }
}

void delete()
{
    int value;

    if (front == -1 || front > rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        value = queue[front];

        printf("%d deleted from the queue.\n", value);

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
}

void display()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("Queue elements are: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice;
     printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
         case 1:
           insert();
           break;

         case 2:
            delete();
            break;
         case 3:
            display();
            break;
         case 4:
            printf("Program ended.");
            return 0;
         default:
            printf("Invalid choice!");
        }


    }

    return 0;
}
