#include <stdio.h>
#include <stdlib.h>
int no_of_operations=0;
int power_(int base, int power);
void printsteps(int *array, int n, int a);
int *delete (int position, int size, int *array);
int main()
{
     int no_of_elements;
     printf("How much size of array do you want?  ");
     scanf("%d", &no_of_elements);
     int *array = (int *)malloc(no_of_elements * sizeof(int));
     printf("Elements  of array: ");
     for (int i = 0; i < no_of_elements; ++i)
     {
          array[i] = rand() % 100;
          printf("\033[0;37m");
          printf("%d ", array[i]);
          printf("\033[0m");
     }
     int i;
     for (i = 0; (power_(2, i)) < no_of_elements; ++i)
     {
          printsteps(array, no_of_elements, i);
          int *tmp = delete (power_(2, i), no_of_elements, array);
          --no_of_elements;
          free(array);
          array = tmp;
     }
     printf("\nFinal   Answer    : ");
     for (int i = 0; i < no_of_elements; ++i)
     {
          printf("\033[0;34m");
          printf("%d ", array[i]);
          printf("\033[0m");
     }

     printf("\nNumber of operations performed is %d\n",no_of_operations);
     free(array);
}
int power_(int base, int power)
{
     if (power == 0)
     {
          return 1;
     }
     return base * (power_(base, power - 1));
}
void printsteps(int *array, int n, int a) //printing array with colour
{
     printf("\nBefore iteration %d: ", a + 1);
     for (int i = 0; i < n; ++i)
     {

          if (i == power_(2, a)) //printing the deleting elements in colour
          {
               printf("\033[4;91m%d ", array[i]);
               printf("\033[0m");
          }
          else
          {
               printf("\033[0;34m");
               printf("%d ", array[i]);
               printf("\033[0m");
               
          }
     }
}
int *delete (int position, int size, int *array)
{
     int *tmp = (int *)malloc((size - 1) * sizeof(int));
     int j = 0;
     for (int i = 0; i < size; ++i)
     {
          no_of_operations++;
          if (i == position)
          {
               continue;
          }
          tmp[j++] = array[i];
     }
     return tmp;
}