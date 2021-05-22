#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
     long long int fibo;
     struct node *next;
} node;

void createList(node *head, unsigned int n);
void print(node *head, unsigned int n);
int main()
{
     node *head = (node *)malloc(sizeof(node));
     if (head == NULL)
     {
          printf("Memory not allocated");
          exit(1);
     }
     unsigned int n; //number of terms
     printf("\tFIBONACCI NUMBER GENERTOR\n");
     printf("Enter the no. of terms you need: ");
     scanf("%u", &n);
     createList(head, n);

     print(head, n);
     while (head != NULL)
     {
          node *tmp = head->next;
          free(head);
          head = tmp;
     }
}
void createList(node *head, unsigned int n)
{
     node *previous = NULL;
     node *pprevious = NULL;
     if (n)
     {
          head->fibo = 1;
          head->next = NULL;
          previous = head;
          if (n > 1)
          {
               node *tmp = (node *)malloc(sizeof(node));
               if (tmp == NULL)
               {
                    printf("Memory not allocated");
                    exit(1);
               }
               head->next = tmp;
               head = tmp;
               head->fibo = 1;
               head->next = NULL;
               pprevious = previous;
               previous = head;
               if (n > 2)
               {
                    for (int i = 2; i < n; i++)
                    {
                         tmp = (node *)malloc(sizeof(node));
                         if (tmp == NULL)
                         {
                              printf("Memory not allocated");
                              exit(1);
                         }
                         head->next = tmp;
                         head = tmp;
                         head->fibo = previous->fibo + pprevious->fibo;
                         head->next = NULL;
                         pprevious = previous;
                         previous = head;
                    }
               }
          }
     }
}
void print(node *head, unsigned int n)
{
     if (n == 0)
     {
          printf("Input should be greater than 0\n");
     }
     else

     {
          long long int oddsum = 0;
          long long int evensum = 0;
          printf("First %u terms of fibonacci:", n);
          for (head; head != NULL; head = head->next)
          {
               if (head->fibo & 1)
                    oddsum += head->fibo;
               else
                    evensum += head->fibo;
               printf(" %lld", head->fibo);
          }
          printf("\nSum of odd fibonacci numbers = %lld\n", oddsum);
          printf("Sum of even fibonacci numbers = %lld\n", evensum);
     }
}