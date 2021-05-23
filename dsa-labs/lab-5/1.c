#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
     float fl;
     struct list *next;
} list;
void createlist(list *head, int N);
void reverselist(list *head, int factor, int N);
void print(char *str, list *head);
void printcolor(list *head, int init, int length);
void reverselist(list *head, int factor, int N);
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
     createlist(head, N);

     print("Created List:", head);
     reverselist(head, factor, N);
     printf("\n");
     print("\nAfter reversing: ", head);
     printf("\n");
     freelist(head);
}

void print(char *str, list *head)
{
     printf("%s", str);
     while (head != NULL)
     {
          printf("\033[0;34m %.3f\033[0m", head->fl);
          head = head->next;
     }
}
void createlist(list *head, int N)
{
     float random = (rand() % 100000) * 0.001;
     head->fl = random;
     head->next = NULL;

     for (int i = 0; i < N - 1; ++i)
     {

          random = (rand() % 100000) * 0.001;
          list *temp = (list *)malloc(sizeof(list));
          if (temp == NULL)
          {
               printf("Memory not allocated");
               exit(1);
          }
          head->next = temp;
          head = temp;
          head->fl = random;
          head->next = NULL;
     }
}
void printcolor(list *head, int init, int length)
{
     printf("\n");
     int j = 1;
     for (j, head; head != NULL; head = head->next, ++j)
     {
          if (j >= init && j < (length + init))
          {
               if (j & 1)
                    printf("\033[1;33m%.3f \033[0m", head->fl);
               else
                    printf("\033[1;34m%.3f \033[0m", head->fl);
          }
          else
               printf("\033[0;37m%.3f \033[0m", head->fl);
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
void reverselist(list *head, int factor, int N)
{
     list *pseudo_start = head;
     list *real_start = head->next;
     int sum = 1 + factor;
     int i = 1;
     printf("\n\nSTEP-%d", i);
     printcolor(head, 1, 1);
     printcolor(head, 1, 1);
     for (int term = factor; sum <= N; term = term * factor, sum = sum + term)
     {
          printf("\n\nSTEP-%d", ++i);
          printcolor(head, (sum - term + 1), term);
          list *current = real_start, *prev = NULL, *next = NULL;
          for (int i = 0; i < term; ++i)
          {
               next = current->next;
               current->next = prev;
               prev = current;
               current = next;
          }
          pseudo_start->next = prev;
          real_start->next = next;
          pseudo_start = real_start;
          real_start = real_start->next;
          printcolor(head, (sum - term + 1), term);
     }
}
