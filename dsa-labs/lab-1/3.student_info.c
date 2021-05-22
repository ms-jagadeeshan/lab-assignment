#include <stdio.h>
struct studentInfo
{
     char student_name[30];
     int age;
     char roll_no[10];
     char address[50];
};

int main()
{
     struct studentInfo student1;
     printf("Enter Your name: ");
     scanf("%s", student1.student_name);
     printf("Enter Your age: ");
     scanf("%d", &student1.age);
     printf("Enter Your Roll number: ");
     scanf("%s", student1.roll_no);
     printf("Enter your address: ");
     scanf("%s", student1.address);
     printf("\nSTUDENT INFO\nName\t   : %s\nAge\t   : %d",student1.student_name, student1.age);
     printf("\nRoll Number: %s\nAddress\t   : %s\n",student1.roll_no,student1.address);
}