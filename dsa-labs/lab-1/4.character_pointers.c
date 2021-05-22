#include <stdio.h>
#include <stdlib.h>
struct studentInfo
{
     char *student_name;
     int age;
     char roll_no[10];
     char *address;
};

int main()
{
     struct studentInfo student1;
     student1.student_name = (char *)malloc(30 * sizeof(char));
     printf("Enter Your name: ");
     scanf("%s", student1.student_name);
     printf("Enter Your age: ");
     scanf("%d", &student1.age);
     printf("Enter Your Roll number: ");
     scanf("%s", student1.roll_no);
     printf("Enter your address: ");
     student1.address = (char *)malloc(50 * sizeof(char));
     scanf("%s", student1.address);
     printf("\nSTUDENT INFO\nName\t   : %s\nAge\t   : %d", student1.student_name, student1.age);
     printf("\nRoll Number: %s\nAddress\t   : %s\n", student1.roll_no, student1.address);
}