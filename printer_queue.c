#include <stdio.h>
#include <string.h>

#define MAX 5

char queue[MAX][50];
int front = -1, rear = -1;

void addJob()
{
    char job[50];

    if (rear == MAX - 1)
    {
        printf("\nPrinter queue is full!\n");
        return;
    }

    printf("Enter document name: ");
    scanf("%49s", job);

    if (front == -1)
        front = 0;

    rear++;
    strcpy(queue[rear], job);

    printf("Print job '%s' added successfully.\n", job);
}

void printJob()
{
    if (front == -1 || front > rear)
    {
        printf("\nNo print jobs available.\n");
        return;
    }

    printf("\nPrinting document: %s\n", queue[front]);
    front++;

    if (front > rear)
        front = rear = -1;
}

void displayQueue()
{
    int i;

    if (front == -1)
    {
        printf("\nPrinter queue is empty.\n");
        return;
    }

    printf("\nPending print jobs:\n");

    for (i = front; i <= rear; i++)
        printf("%d. %s\n", i - front + 1, queue[i]);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Printer Job Management System ---\n");
        printf("1. Add Print Job\n");
        printf("2. Print Next Job\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addJob();
                break;

            case 2:
                printJob();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                printf("\nExiting Printer System.\n");
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
