#include <stdio.h>
//function to convert lower case to upper case
void toUpper(int length, char str[25])
{
     for (int i = 0; i < length; ++i)
     {
          if (str[i] >= 'a' && str[i] <= 'z')
          {
               str[i] -= 32;
          }
     }
}
int main()
{
     char str[25];
     int length = 0;
     int isPalindrome = 0;
     printf("Enter the string: ");
     scanf("%s", str);

     //finding the length of the string enter
     while (str[length] != '\0')
          length++;

     //converting the input string to upper case
     toUpper(length, str);

     //check for palindrome, final value of isPalindrome is 1 ,if string is palindrome
     for (int i = 0; i < (length / 2); ++i)
     {
          if (str[i] == str[length - i - 1])
               isPalindrome = 1;
          else
          {
               isPalindrome = 0;
               break;
          }
     }
     //if isPalindrome true or lenght equals to 1, it is palindrome
     if (isPalindrome || length == 1)
          printf("Given word is palindrome");
     else
          printf("Given word is not palindrome");
}