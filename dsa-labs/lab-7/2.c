#include <stdio.h>
#include <stdlib.h>
int MAX;
int token = 0;
typedef struct queue
{
    int token;
    struct queue *next;
} queue;
int count = 0;
queue *head;
queue *start = NULL;
queue *FRONT = NULL;
queue *REAR = NULL;
int isEmpty();
void remove_k(int k);
char printMenu();
void enqueue();
int dequeue();
int display();
int main()
{
    printf("Enter the Parking lot size: ");
    scanf("%d", &MAX);
    while (1)
    {
        switch (printMenu())
        {
        case 'E':
        case 'e':
        {
            enqueue();
            break;
        }
        case 'l':
        case 'L':
        {
            dequeue();
            break;
        }
        case 's':
        case 'S':
        {
            display();
            break;
        }
        case 'R':
        case 'r':
        {
            printf("\033[2J\033[1;1H");
            int k;
            printf("Enter the position of car: ");
            scanf("%d", &k);
            remove_k(k);
            break;
        }
        case 'Q':
        case 'q':
        {
            exit(0);
            break;
        }
        default:
        {
            printf("\033[2J\033[1;1H");
            printf("Invalid input\nTry again......\n");
        }
        }
    }
}
int isEmpty()
{
    if (start == NULL)
    {
        return 1;
    }
    return 0;
}
int display()
{
    if (isEmpty())
    {
        printf("\033[2J\033[1;1H");
        printf("\033[1;31mParking lot is empty!\033[0m\n");
    }
    else
    {
        printf("\033[2J\033[1;1H");
        printf("\033[1;37mToken number of cars in parking lot:");
        for (queue *i = FRONT; i != NULL; i = i = i->next)
        {
            printf(" %d", i->token);
        }
    }
    printf("\033[0m");
}

int dequeue()
{
    if (isEmpty())
    {
        printf("\033[2J\033[1;1H");
        printf("\033[1;31mSorry, Parking lot is already empty!!\033[0m\n");
        return 0;
    }
    else
    {
        printf("\033[2J\033[1;1H");
        printf("Success!\nCar with token no. %d left the parking lot\n", FRONT->token);
        count--;
        FRONT = FRONT->next;
        free(start);
        start = FRONT;
    }
}
void remove_k(int k)
{
    if (k > count)
    {
        printf("\033[2J\033[1;1H");
        printf("\033[1;31mSorry, Car not found in position %d\033[0m\n", k);
    }
    else
    {
        for (int i = 1; i < k; i++)
        {
            queue *tmp = start;
            start = start->next;
            tmp->next = head;
            head = tmp;
        }
        queue *tmp = start;
        start = start->next;
        free(tmp);
        while (head != NULL)
        {
            queue *tmp = head;
            head = head->next;
            tmp->next = start;
            start = tmp;
        }
        printf("\033[2J\033[1;1H");
        printf("Car at position %d left the parking lot!\n",k);
    }
}
void enqueue()
{
    if (count == MAX)
    {
        printf("\033[2J\033[1;1H");
        printf("\033[1;31mSorry, There is no space for parking!!\033[0m\n");
    }
    else if (start == NULL)
    {
        printf("\033[2J\033[1;1H");
        printf("Parking Success!\nToken No. => %d\n", ++token);
        count++;
        queue *temp = (queue *)malloc(sizeof(queue));
        temp->token = token;
        temp->next = NULL;
        start = temp;
        REAR = temp;
        FRONT = temp;
    }
    else
    {
        printf("\033[2J\033[1;1H");
        printf("Parking Success!\nToken No. => %d\n", ++token);
        count++;
        queue *temp = (queue *)malloc(sizeof(queue));
        temp->token = token;
        temp->next = NULL;
        REAR->next = temp;
        REAR = temp;
    }
}
char printMenu()
{
    printf("\n\n\033[1m**********MENU************\033[0m\n");
    printf("\n1. Press E to enter a new car to the Parking from the REAR end");
    printf("\n2. Press L to leave a new car from the Parking from the FRONT end");
    printf("\n3. Press S to show the cars currently present in the Parking");
    printf("\n4. Press R to remove a car from a given location (K) in the parking");
    printf("\n5. Press Q to quit");
    printf("\nEnter your choice: ");
    char ch;
    while ((getchar()) != '\n')
        ;
    scanf("%c", &ch);
    return ch;
}