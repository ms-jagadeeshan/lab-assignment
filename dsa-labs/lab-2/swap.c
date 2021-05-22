#include <stdio.h>
#include <stdlib.h>
void printsteps(int array[], int n, int a) //printing array with colour
{
     printf("\nAfter iteration %d: ", ((a / 2) + 1));
     for (int i = 0; i < n; ++i)
     {

          if (i == a || i == (n - a - 1)) //printing the comparing elements in colour
          {
               printf("\033[1;33m%d ", array[i]);
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
int main()
{
     int no_of_elements;
     printf("How much size of array do you want?  ");
     scanf("%d", &no_of_elements);
     int *array = (int *)malloc(no_of_elements * sizeof(int));
     printf("Elements of array: ");
     for (int i = 0; i < no_of_elements; ++i)
     {
          array[i] = rand() % 100;
          printf("\033[0;37m");
          printf("%d ", array[i]);
          printf("\033[0m");
     }
     int i = 0;
     for (i = 1; i < (no_of_elements / 2); i = i + 2)
     {
          int tmp = array[i];
          array[i] = array[no_of_elements - i - 1];
          array[no_of_elements - i - 1] = tmp;
          printsteps(array, no_of_elements, i);
     }
     printf("\nNumber of operations is %d\n",(i/2));
     free(array);
}