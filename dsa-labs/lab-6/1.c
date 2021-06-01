#include <stdio.h>
#include <stdlib.h>
typedef struct stacklist
{
     int num;
     struct stacklist *next;
} stacklist;
int isEmpty(stacklist*head);
void push(stacklist **head_ref, int num);
void pop(stacklist **head_ref);
int top(stacklist *head);
void print(char *s, stacklist *head);
int main()
{
     stacklist *head = NULL;
     int N;
     printf("Enter non-negative integer: ");
     scanf("%d", &N);
     long long int fact_n = 1;
     for (int i = N; i >= 1; --i)
     {
          push(&head, i);
     }

     print("Value stored in stack:", head);
     while (!isEmpty(head))
     {
          fact_n = fact_n * top(head);
          pop(&head);
     }
     printf("\nFactorial of %d is %lld\n", N, fact_n);
}
int top(stacklist *head)
{
     if (!isEmpty(head))
     {
          return head->num;
     }
}
void push(stacklist **head_ref, int num)
{
     stacklist *temp = (stacklist *)malloc(sizeof(stacklist));
     temp->num = num;
     temp->next = *head_ref;
     *head_ref = temp;
}
int isEmpty(stacklist *head)
{
     if (head == NULL)
          return 1;
     else
          return 0;
}

void pop(stacklist **head_ref)
{
     if (*head_ref != NULL)
     {
          stacklist *temp = *head_ref;
          *head_ref = temp->next;
          free(temp);
     }
}
void print(char *s, stacklist *head)
{
     printf("%s", s);
     while (!isEmpty(head))
     {
          printf(" %d", head->num);
          head = head->next;
     }
}