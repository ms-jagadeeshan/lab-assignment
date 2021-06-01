#include <stdio.h>
#include <stdlib.h>
typedef struct stacklist
{
     char ch;
     struct stacklist *next;
} stacklist;
int isEmpty(stacklist *head);
char top(stacklist *head);
void push(stacklist **head_ref, char ch);
void pop(stacklist **head_ref);
void print(char *s, stacklist *head);
int isVowel(char ch);
void printcolor(stacklist *head, int iscolor);
int main()
{
     stacklist *head = NULL;
     char *str;
     printf("Enter the string: ");
     scanf("%s", str);
     printf("%s", str);
     int step = 1;
     for (int i = 0; str[i] != '\0'; ++i)
     {
          if (isVowel(str[i]))
          {
               printf("\nB e f o r e   iteration %2d: ", step++);
               printcolor(head, 1);
               pop(&head);
          }
          else
          {
               printf("\nB e f o r e   iteration %2d: ", step++);
               printcolor(head, 0);
               push(&head, str[i]);
          }
     }
     print("\n\nAfter  f i n a l iteration:", head);
     printf("\n");
}

void push(stacklist **head_ref, char ch)
{
     stacklist *temp = (stacklist *)malloc(sizeof(stacklist));
     temp->ch = ch;
     temp->next = *head_ref;
     *head_ref = temp;
}
void pop(stacklist **head_ref)
{
     if (!isEmpty(*head_ref))
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
          printf(" %c", head->ch);
          head = head->next;
     }
}
void printcolor(stacklist *head, int iscolor)
{
     if (!isEmpty(head))
     {
          if (iscolor)
               printf("\033[1;31m %c\033[0m", head->ch);
          else
               printf(" %c", head->ch);
          head = head->next;
     }
     while (!isEmpty(head))
     {
          printf(" %c", head->ch);
          head = head->next;
     }
}
int isVowel(char ch)
{
     char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
     for (int i = 0; i < 5; i++)
     {
          if (ch == vowel[i] || ch == (vowel[i] - ' '))
               return 1;
     }
     return 0;
}
char top(stacklist *head)
{
     if (!isEmpty(head))
     {
          return head->ch;
     }
}
int isEmpty(stacklist *head)
{
     if (head == NULL)
          return 1;
     else
          return 0;
}