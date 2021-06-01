#include <stdio.h>
#include <stdlib.h>
#define NAN (__builtin_nanf(""))
#define nul (char)0
#define nal -1.0

// WORKS FORKS FOR TWO DIGIT NUMBERS,
// BUT NOT FOR NUMBERS LIKE 10,100,20
// e.g 100+3 is takes as 1+3

typedef struct stacklist
{
     float num;
     char op;
     struct stacklist *next;
} stacklist;
void reverselist(stacklist **head_ref);
int isnanc(char ch);
int getPriority(char ch);
void exprToPrefix(char *str, int len);
int isoperator(char ch);
void push(stacklist **head_ref, float num, char op);
int top(stacklist *head);
void pop(stacklist **head_ref);
int reverse(int num);
void print(char *str, stacklist *head);
int main()
{
     char *str = NULL;
     int ch;
     printf("Enter the expression: ");
     size_t size = 0, len = 0;
     if (len + 1 >= size)
     {
          size = size * 2 + 1;
          str = realloc(str, sizeof(char) * size);
     }
     str[len++] = '(';
     while ((ch = getchar()) != EOF && ch != '\n')
     {
          if (len + 1 >= size)
          {
               size = size * 2 + 1;
               str = realloc(str, sizeof(char) * size);
          }
          str[len++] = ch;
     }
     if (len + 1 >= size)
     {
          size = size * 2 + 1;
          str = realloc(str, sizeof(char) * size);
     }
     str[len++] = ')';

     exprToPrefix(str, len);
}
void exprToPrefix(char *str, int len)
{
     stacklist *operands = NULL;
     stacklist *prefix = NULL;
     stacklist *operators = NULL;
     int i = len - 1;
     printf("\nGiven expresion: %s", str);
     for (i; i >= 0;)
     {

          if (str[i] == ')')
          {
               push(&operators, nal, '(');
               i--;
          }
          else if (str[i] == '(')
          {
               while (top(operators) != '(')
               {
                    push(&prefix, nal, top(operators));
                    pop(&operators);
               }
               pop(&operators);
               i--;
          }
          else
          {
               if (isoperator(str[i]))
               {
                    if (str[i] == '^')
                    {
                         while (getPriority(str[i]) <= getPriority(top(operators)))
                         {

                              push(&prefix, nal, top(operators));
                              pop(&operators);
                         }
                    }
                    else
                    {
                         while (getPriority(str[i]) < getPriority(top(operators)))
                         {

                              push(&prefix, nal, top(operators));
                              pop(&operators);
                         }
                    };
                    push(&operators, nal, str[i]);
                    i--;
               }
               else
               {
                    int number = str[i] - '0';
                    while ((i >= 0) && !(isoperator(str[(i - 1)]) || str[(i - 1)] == '(' || str[(i - 1)] == ')'))
                    {
                         number = 10 * number + (str[(i - 1)] - '0');
                         i--;
                    }
                    number = reverse(number);
                    i--;

                    push(&prefix, (float)number, nul);
               }
          }
     }
     print("\nPrefix: ", prefix);
     printf("\n");
}
int reverse(int num)
{
     int rem, result;
     result = 0;
     while (num >= 1)
     {
          rem = num % 10;
          num = num / 10;
          result = (10 * result) + rem;
     }
     return result;
}
int getPriority(char ch)
{
     if (ch == '+' || ch == '-')
     {
          return 1;
     }
     else if (ch == '*' || ch == '/')
     {
          return 2;
     }
     else if (ch == '^')
     {
          return 3;
     }
     else
     {
          return 0;
     }
}
void print(char *str, stacklist *head)
{
     printf("%s", str);
     while (head != NULL)
     {
          if (!isnanc(head->op))
               printf(" %c", head->op);
          else
               printf(" %d", (int)head->num);

          head = head->next;
     }
}
int isoperator(char ch)
{
     char operator[5] = {'+', '-', '*', '/', '^'};
     for (int i = 0; i < 5; i++)
     {
          if (ch == operator[i])
               return 1;
     }
     return 0;
}
void push(stacklist **head_ref, float num, char op)
{
     stacklist *temp = (stacklist *)malloc(sizeof(stacklist));
     if (num == nal)
     {
          temp->num = NAN;
     }
     else
     {
          temp->num = num;
     }

     temp->op = op;
     temp->next = *head_ref;
     *head_ref = temp;
}
int top(stacklist *head)
{
     if (head != NULL)
     {
          if (isnanc(head->op))
          {
               return head->num;
          }
          else
          {
               return head->op;
          }
     }
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
int isnanc(char ch)
{
     if ((int)ch == 0)
          return 1;
     else
          return 0;
}