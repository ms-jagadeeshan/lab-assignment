#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int arr[MAX];
int front = -1, rear = -1;
int printMenu();
int enqueue(int num);
int dequeue();
int display();
int main()
{

    int option;
    while (1)
    {
        switch (printMenu())
        {
        case 1:
        {
            int num;
            printf("\033[2J\033[1;1H");
            printf("Enter the number to enqueue: ");
            scanf("%d", &num);
            printf("\033[2J\033[1;1H");
            enqueue(num);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
            exit(0);
        default:
        {
            printf("\033[2J\033[1;1H");
            printf("Invalid input\nTry again......\n");
        }
        }
    }
}
int display()
{
    if (front == -1)
    {
        printf("\033[2J\033[1;1H");
        printf("\033[1;31mSorry, queue is empty!\033[0m\n");
        return 0;
    }
    printf("\033[2J\033[1;1H");
    printf("\033[1;37mValues in queue:");
    if (rear < front)
    {
        for (int i = front; i < MAX; i++)
        {
            printf(" %d", arr[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf(" %d", arr[i]);
        }
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf(" %d", arr[i]);
        }
    }
    printf("\033[0m");
}
int dequeue()
{
    if (front == -1)
    {
        printf("\033[2J\033[1;1H");
        printf("\033[1;31mSorry, queue is already empty!!\033[0m\n");
        return 0;
    }
    if (front == rear)
    {
        printf("\033[2J\033[1;1H");
        printf("Success!\n");
        front = -1;
        rear = -1;
        return 0;
    }
    else
    {
        if (front == MAX - 1)
        {
            printf("\033[2J\033[1;1H");
            printf("Success!\n");
            front = 0;
        }
        else
        {
            front++;
            printf("\033[2J\033[1;1H");
            printf("Success!\n");
        }
    }
}
int enqueue(int num)
{
    if ((rear + 1) == front || (front == 0 && rear == MAX - 1))
    {
        printf("\033[2J\033[1;1H");
        printf("\033[1;31mSorry, queue is already full!\033[0m\n");
        return 0;
    }

    if (front = -1)
    {
        printf("\033[2J\033[1;1H");
        printf("Enqueue Success!\n");
        front++;
        rear++;
        arr[rear] = num;
        return 0;
    }
    else
    {
        if (rear == MAX - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        printf("\033[2J\033[1;1H");
        printf("Enqueue Success!\n");
        arr[rear] = num;
    }
}
int printMenu()
{
    printf("\n\tMENU\n");
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
    printf("\nYour option: ");
    int option;
    scanf("%d", &option);
    return option;
}