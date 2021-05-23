#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
     long long fibo;
     struct list *prev;
     struct list *next;
} list;
list *createlist(list *head, int N);
void delete (list **head_ref, list **tail_ref, int factor, int N);
void print(char *str, list *head);
void printFromHead(char *str, list *head);
void printFromTail(char *str, list *tail);
void printcolor(list *head, int init);
void freelist(list *head);

int main()
{
     int N, factor;
     printf("Enter the no. of nodes you want?");
     scanf("%d", &N);
     printf("What is the factor for G.P series?");
     scanf("%d", &factor);
     list *head = (list *)malloc(sizeof(list));
     if (head == NULL)
     {
          printf("Memory not allocated");
          exit(1);
     }
     list *tail = createlist(head, N);
     printFromHead("\nCreated List(accessing from head):", head);
     printFromTail("\nCreated List(accessing from tail):", tail);
     delete (&head, &tail, factor, N);
     printFromHead("\nAfter deleting(accessing from head): ", head);
     printFromTail("\nAfter deleting(accessing from tail): ", tail);
     printf("\n");
     freelist(head);
     tail = NULL;
}

void printFromHead(char *str, list *head)
{
     printf("%s", str);
     while (head != NULL)
     {
          printf("\033[1;33m %lld\033[0m", head->fibo);
          head = head->next;
     }
}
void printFromTail(char *str, list *tail)
{
     printf("%s", str);
     while (tail != NULL)
     {
          printf(" %lld", tail->fibo);
          tail = tail->prev;
     }
}
list *createlist(list *head, int N)
{
     if (N > 0)
     {
         
          head->fibo = 1;
          head->prev = NULL;
          head->next = NULL;
          list *previous = head;
          if (N > 1)
          {
               list *pprevious = NULL;
               list *temp = (list *)malloc(sizeof(list));
               if (temp == NULL)
               {
                    printf("Memory not allocated");
                    exit(1);
               }
               head->next = temp;
               head = temp;
               head->fibo = 1;
               head->prev = previous;
               head->next = NULL;
               pprevious = previous;
               previous = head;
               for (int i = 0; i < N - 2; ++i)
               {
                    temp = (list *)malloc(sizeof(list));
                    if (temp == NULL)
                    {
                         printf("Memory not allocated");
                         exit(1);
                    }
                    head->next = temp;
                    head = temp;
                    head->fibo = previous->fibo + pprevious->fibo;
                    head->prev = previous;
                    head->next = NULL;
                    pprevious = previous;
                    previous = head;
               }
          }
          return previous;
     }
}
void printcolor(list *head, int init)
{
     printf("\n");
     int j = 0;
     for (j, head; head != NULL; head = head->next, ++j)
     {
          if (j == init)
          {
               printf("\033[1;31m%lld \033[0m", head->fibo);
          }
          else
               printf("\033[0;37m%lld \033[0m", head->fibo);
     }
}
void freelist(list *head)
{
     while (head != NULL)
     {
          list *temp = head->next;
          free(head);
          head = temp;
     }
}
void delete (list **head_ref, list **tail_ref, int factor, int N)
{
     list *dummy_head = *head_ref;
     list *previous = NULL;
     int d_index = 1, j = 1;
     int i = 1;
     for (i = 1; i <= N; i++)
     {
          if (dummy_head->next == NULL)
          {
               if (i == d_index)
               {
                    printf("\n\nSTEP-%d", j++);
                    printcolor(*head_ref, (i - j + 1));
                    list *temp = previous->next;
                    previous->next = NULL;
                    *tail_ref = previous;
                    free(temp);
               }
          }
          else if (dummy_head->prev == NULL)
          {
               if (i == d_index)
               {
                    printf("\n\nSTEP-%d", j++);
                    printcolor(*head_ref, (i - j + 1));
                    d_index = d_index * factor;
                    *head_ref = dummy_head->next;
                    dummy_head->next->prev = NULL;
                    free(dummy_head);
                    dummy_head = *head_ref;
               }
               else
               {
                    previous = dummy_head;
                    dummy_head = dummy_head->next;
               }
          }
          else
          {
               if (i == d_index)
               {
                    printf("\n\nSTEP-%d", j++);
                    printcolor(*head_ref, (i - j + 1));
                    d_index = d_index * factor;
                    list *temp = dummy_head;
                    previous->next = dummy_head->next;
                    dummy_head = dummy_head->next;
                    dummy_head->prev = previous;
                    free(temp);
               }
               else
               {
                    previous = dummy_head;
                    dummy_head = dummy_head->next;
               }
          }
     }
}
