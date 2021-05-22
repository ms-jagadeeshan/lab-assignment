#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
     char ch;
     struct node *next;
} node;

void createList(node *head, unsigned int n);
void print(node *head);
void rm_dup(node *head);
int main()
{
     node *head = (node *)malloc(sizeof(node));
     if (head == NULL)
     {
          printf("Memory not allocated");
          exit(1);
     }
     unsigned int n; //number of nodes
     printf(" Enter the no. of nodes: ");
     scanf("%u", &n);
     createList(head, n);

     printf("The  g e n e r a t e d   characters:");
     print(head);

     rm_dup(head);

     printf("After removing duplicate characters:");
     print(head);

     while (head != NULL)
     {
          node *tmp = head->next;
          free(head);
          head = tmp;
     }
}
void createList(node *head, unsigned int n)
{
     char randomletter = 'A' + (random() % 26);
     head->ch = randomletter;
     head->next = NULL;
     for (int i = 1; i < n; i++)
     {
          randomletter = 'A' + (random() % 26);
          node *tmp = (node *)malloc(sizeof(node));
          if (tmp == NULL)
          {
               printf("Memory not allocated");
               exit(1);
          }
          head->next = tmp;
          head = tmp;
          head->ch = randomletter;
          head->next = NULL;
     }
}
void print(node *head)
{
     for (head; head != NULL; head = head->next)
     {
          printf(" %c", head->ch);
     }
     printf("\n");
}
void rm_dup(node *head)
{
     node *i = NULL;
     node *j = NULL;
     for (i = head; i != NULL; i = i->next)
     {
          j = i;
          while (j->next != NULL)
          {
               if ((i->ch) == (j->next->ch))
               {
                    node *tmp = j->next;
                    j->next = j->next->next;
                    free(tmp);
               }
               else
                    j = j->next;
          }
     }
}