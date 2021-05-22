#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Note: To compile program which has math.h in linux/unix
// math library needs to be linked like this
// 'gcc 3.c -o 3 -lm' 
typedef struct node
{
     int number;
     struct node *next;
} node;

void print(node *head, int count);
int createList(node *head);

int main()
{
     node *head = NULL;
     head = (node *)malloc(sizeof(node));
     if (head == NULL)
     {
          printf("Memory not allocated");
          return 1;
     }
     int count = createList(head);
     print(head, count);
}

//creates linked list and returns the number of inputs
int createList(node *ptr)
{

     char ch;
     int i = 1;
     printf("Creating the linked list................\n\n");
     printf("Enter element %d: ", i);
     scanf("%d", &ptr->number);
     ptr->next = NULL;

     printf("Press q to quit,any key to continue:");
     scanf("\n%c", &ch);
     while (ch != 'q')
     {
          node *tmp = NULL;
          tmp = (node *)malloc(sizeof(node));
          if (tmp == NULL)
          {
               printf("Memory not allocated");
               exit(1);
          }
          ptr->next = tmp;
          ptr = tmp;
          printf("Enter element %d: ", ++i);
          scanf("%d", &ptr->number);
          ptr->next = NULL;
          printf("Press q to quit,any key to continue:");
          scanf("\n%c", &ch);
     }
     return i;
}

//prints the elements stored in list and
//frees the memory allocated and
//prints the mean and deviation
void print(node *head, int count)
{
     printf("Elements in linked list: ");
     int sum, sq_sum;
     sum = 0;
     sq_sum = 0;
     while (head != NULL)
     {
          node *tmp;
          tmp = head->next;
          printf(" %d", head->number);
          sum += head->number;
          sq_sum += (head->number) * (head->number);

          free(head);
          head = tmp;
     }
     float mean = (float)sum / count;
     float sq_avg = (float)sq_sum / count;
     float sd = sqrt((sq_avg) - (mean * mean));
     printf("\nThe mean and standard deviation are %.6f %.6f respectively\n", mean, sd);
}
