#include<stdio.h>
#include <stdlib.h>
    typedef struct node
{
     int number;
     struct node *next;
} node;
void list(node *head);
void print(node *head);
int main()
{
     node *head = NULL;
     head = (node *)malloc(sizeof(node));
     if (head == NULL)
     {
          printf("no memory allocated");
          exit(1);
     }
     list(head);
     print(head);
}
void list(node *head)
{
     char c;
     printf("enter number-%d", 1);
     scanf("%d", &head->number);
     head->next = NULL;
     int i = 2;
     printf("press anything to continue or press q to quit\n");
     scanf("\n%c", &c);
     while (c != 'q')
     {
          node *temp = NULL;
          temp = (node *)malloc(sizeof(node));
          if (temp == NULL)
          {
               printf("no memory allocated");
               exit(1);
          }
          head->next = temp;
          head = head->next;
          printf("\nenter element-%d", i++);
          scanf("%d", &head->number);
          head->next = NULL;
          printf("press anything to continue or press q to quit\n");
          scanf("\n%c", &c);
     }
}
void print(node *head)
{
     printf("elements are:");
     while (head != NULL)
     {
          node *temp;
          temp = head->next;
          printf("%d", head->number);
          free(head);
          head = temp;
     }
}