#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
     int roll_no;
     float percentage;
     char grade;
     struct student *next;
} student;
int count[7] = {0, 0, 0, 0, 0, 0, 0};
char grades(float p);
void createList(student *head, unsigned int n);
void print(student *head);
void createArrList(student *head, student **gradearr);
void printarrlist(student **gradearr);
int grade2index(char grade);
void freemem(student *node, student **gradearr);

int main()
{
     student *head = (student *)malloc(sizeof(student));
     if (head == NULL)
     {
          printf("Memory not allocated");
          exit(1);
     }
     unsigned int n; //number of term
     printf("Enter the no. of students:");
     scanf("%u", &n);
     createList(head, n);
     printf("\nStudent list and grade:\n");
     print(head);
     student **gradearr = (student **)malloc(7 * sizeof(student *));
     for (int i = 0; i < 7; i++)
     {
          gradearr[i] = (student *)malloc(sizeof(student));
          if (gradearr == NULL)
          {
               printf("Memory not allocated");
               exit(0);
          }
          gradearr[i]->next = NULL;
     }
     createArrList(head, gradearr);
     printarrlist(gradearr);
     freemem(head, gradearr);
}

void createList(student *head, unsigned int n)
{
     if (n == 0)
     {
          exit(0);
     }
     int i = 1;
     head->roll_no = i;
     head->percentage = ((1000 + (random() % 9001)) * 0.01);
     head->grade = grades(head->percentage);
     head->next = NULL;
     for (int i = 2; i <= n; i++)
     {
          student *tmp = (student *)malloc(sizeof(student));
          if (tmp == NULL)
          {
               printf("memory not allocated");
               exit(0);
          }
          head->next = tmp;
          head = tmp;
          head->roll_no = i;
          head->percentage = ((1000 + (random() % 9001)) * 0.01);
          head->grade = grades(head->percentage);
          head->next = NULL;
     }
}

void print(student *head)
{
     for (head; head != NULL; head = head->next)
     {
          printf("Student Roll Number %4d | Percentage= %3.2f | Grade %c\n", head->roll_no, head->percentage, head->grade);
     }
}

char grades(float p)
{
     if (p >= 90)
     {
          return 'A';
     }
     else if (p < 90 && p >= 80)
     {
          return 'B';
     }
     else if (p < 80 && p >= 70)
     {
          return 'C';
     }
     else if (p < 70 && p >= 60)
     {
          return 'D';
     }
     else if (p < 60 && p >= 50)
     {
          return 'E';
     }
     else if (p < 50 && p >= 35)
     {
          return 'P';
     }
     else
     {
          return 'F';
     }
}
int grade2index(char grade)
{
     char grades[7] = {'A', 'B', 'C', 'D', 'E', 'P', 'F'};
     for (int i = 0; i < 7; i++)
     {
          if (grades[i] == grade)
          {
               return i;
          }
     }
}
char index2grade(int index)
{
     char grades[7] = {'A', 'B', 'C', 'D', 'E', 'P', 'F'};
     for (int i = 0; i < 7; i++)
     {
          if (i == index)
          {
               return grades[i];
          }
     }
}
void createArrList(student *head, student **gradearr)
{
     for (head; head != NULL; head = head->next)
     {
          student *dummy_head = NULL; //dummy dummy head
          int i = grade2index(head->grade);
          dummy_head = gradearr[i];
          if (count[i] == 0)
          {
               dummy_head->roll_no = head->roll_no;
               dummy_head->percentage = head->percentage;
               dummy_head->grade = head->grade;
               dummy_head->next = NULL;
               count[i]++;
          }
          else
          {
               while (dummy_head->next != NULL)
               {
                    dummy_head = dummy_head->next;
               }
               student *tmp = (student *)malloc(sizeof(student));
               dummy_head->next = tmp;
               dummy_head = tmp;
               dummy_head->roll_no = head->roll_no;
               dummy_head->percentage = head->percentage;
               dummy_head->grade = head->grade;
               dummy_head->next = NULL;
               count[i]++;
          }
     }
}
void printarrlist(student **gradearr)
{
     printf("\033[1;37m\nSTUDENTS IN GROUP WISE BASED ON GRADES\033[0m\n");
     for (int i = 0; i < 7; i++)
     {
          if (count[i] == 0)
          {
               continue;
          }
          printf("Students who got '%c' grades:\n", index2grade(i));
          print(gradearr[i]);
          printf("\n");
     }
}
void freemem(student *head, student **gradearr)
{
     while (head != NULL)
     {
          student *tmp = head->next;
          free(head);
          head = tmp;
     }
     for (int i = 0; i < 7; i++)
     {
          student *dummy_head = gradearr[i];
          while (dummy_head != NULL)
          {
               student *tmp = dummy_head->next;
               free(dummy_head);
               dummy_head = tmp;
          }
     }
     free(gradearr);
}