#include <stdio.h>
#include <malloc.h>
#define NAN (__builtin_nanf(""))
#define nan (char)0

//PROBLEM IN 3a is resolved


typedef struct stacklist
{
     float num;
     char op;
     struct stacklist *next;
} stacklist;
float power(int base, int power);
float evalprefix(stacklist *head);
void reverselist(stacklist **head_ref);
int isnanc(char ch);
int getPriority(char ch);
void exprToPrefix(char *str, int len);
int isoperator(char ch);
void push(stacklist **head_ref, float num, char op);
float top(stacklist *head);
void pop(stacklist **head_ref);
int reverse(int num);
int isEmpty(stacklist *head);
void print(char *str, stacklist *head);
int main()
{
     char *str = NULL;
     int ch;
     printf("Enter the expression: ");
     size_t size = 0, len = 0;

     //making first element as '('
     if (len + 1 >= size)
     {
          size = size * 2 + 1;
          str = realloc(str, sizeof(char) * size);
     }
     str[len++] = '(';

     //getting expression from user
     while ((ch = getchar()) != EOF && ch != '\n')
     {
          if (len + 1 >= size)
          {
               size = size * 2 + 1;
               str = realloc(str, sizeof(char) * size);
          }
          str[len++] = ch;
     }

     //making last element as ')'
     if (len + 1 >= size)
     {
          size = size * 2 + 1;
          str = realloc(str, sizeof(char) * size);
     }
     str[len++] = ')';

     exprToPrefix(str, len);
     free(str);
}

void exprToPrefix(char *str, int len)
{
     stacklist *prefix = NULL;
     stacklist *operators = NULL;
     int i = len - 1;

     printf("\nGiven expresion: %s", str);
     for (i; i >= 0;)
     {

          if (str[i] == ')')
          {
               push(&operators, NAN, '(');
               i--;
          }
          else if (str[i] == '(')
          {
               while (top(operators) != '(')
               {
                    push(&prefix, NAN, top(operators));
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
                              push(&prefix, NAN, top(operators));
                              pop(&operators);
                         }
                    }
                    else
                    {
                         while (getPriority(str[i]) < getPriority(top(operators)))
                         {
                              push(&prefix, NAN, top(operators));
                              pop(&operators);
                         }
                    };
                    push(&operators, NAN, str[i]);
                    i--;
               }
               else
               {
                    int number = str[i] - '0';
                    int correcter = 1;
                    if (str[i] == '0')
                    {
                         correcter *= 10;
                    }
                    while ( !(isoperator(str[(i - 1)]) || str[(i - 1)] == '(' || str[(i - 1)] == ')'))
                    {
                         if (str[i - 1] == '0')
                         {
                              correcter *= 10;
                         }
                         number = 10 * number + (str[(i - 1)] - '0');
                         i--;
                    }
                    number = reverse(number);
                    number *= correcter;
                    i--;

                    push(&prefix, (float)number, nan);
               }
          }
     }

     print("\nPrefix notation: ", prefix);
     reverselist(&prefix);
     printf("\n\nResult of %s is %.10g\n", str, evalprefix(prefix));
}
float evalprefix(stacklist *head)
{
     stacklist *number;
     float result;
     while (!isEmpty(head))
     {
          if (isoperator(top(head)))
          {
               float o1 = top(number);
               pop(&number);
               float o2 = top(number);
               pop(&number);
               switch ((int)top(head))
               {
               case '+':
                    push(&number, (o1 + o2), nan);
                    break;
               case '-':
                    push(&number, ((float)o1 - o2), nan);
                    break;
               case '*':
                    push(&number, ((float)o1 * o2), nan);
                    break;
               case '/':
                    push(&number, ((float)o1 / o2), nan);
                    printf("\nhell=%f", ((float)o1 / o2));
                    break;
               case '^':
                    push(&number, (power(o1, o2)), nan);
                    break;
               }
               pop(&head);
          }
          else
          {
               push(&number, top(head), nan);
               pop(&head);
          }
     }
     result = top(number);
     pop(&number);
     return result;
}
float power(int base, int power)
{
     int result = 1;
     for (; power > 0; power--)
          result = result * base;
     return result;
}
int isEmpty(stacklist *head)
{
     if (head == NULL)
          return 1;
     else
          return 0;
}
void reverselist(stacklist **head_ref)
{
     if (*head_ref != NULL)
     {
          stacklist *current = *head_ref;
          stacklist *prev = NULL, *next = NULL;
          while (current != NULL)
          {
               next = current->next;
               current->next = prev;
               prev = current;
               current = next;
          }
          *head_ref = prev;
     }
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
          return 1;
     else if (ch == '*' || ch == '/')
          return 2;
     else if (ch == '^')
          return 3;
     else
          return 0;
}
void print(char *str, stacklist *head)
{
     printf("%s", str);
     while (head != NULL)
     {
          if (!isnanc(head->op))
               printf(" %c", head->op);
          else
               printf(" %.10g", head->num);
          head = head->next;
     }
}
int isoperator(char ch)
{
     char operator[5] = {'+', '-', '*', '/', '^'};
     for (int i = 0; i < 5; i++)
          if (ch == operator[i])
               return 1;

     return 0;
}
void push(stacklist **head_ref, float num, char op)
{
     stacklist *temp = (stacklist *)malloc(sizeof(stacklist));
     temp->num = num;
     temp->op = op;
     temp->next = *head_ref;
     *head_ref = temp;
}
float top(stacklist *head)
{
     if (!isEmpty(head))
     {
          if (isnanc(head->op))
               return head->num;
          else
               return head->op;
     }
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
int isnanc(char ch)
{
     if ((int)ch == 0)
          return 1;
     else
          return 0;
}