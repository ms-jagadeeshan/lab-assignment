#include <stdio.h>
#include <stdlib.h>
int binary_operations = 0;
int binary_position = -3;
int no_of_elements;
void linearSearch(int *array, int no_of_elements, int target);
int binarySearch(int first, int last, int target, int *array);
int main()
{
     int target;
     printf("How much size of array do you want?  ");
     scanf("%d", &no_of_elements);
     int *array = (int *)malloc(no_of_elements * sizeof(int));
     printf("Elements of array: ");
     for (int i = 0; i < no_of_elements; ++i)
     {
          array[i] = i + 1;
          printf(" %d", array[i]);
     }
     printf("\nWhat number you want to search? : ");
     scanf("%d", &target);

     //Linear search
     //which takes array,no of elements and the number we want to search as parameter and prints the result
     linearSearch(array, no_of_elements, target);

     //binary search
     int isfound = binarySearch(0, no_of_elements - 1, target, array);
     printf("\n\nBINARY SEARCH\n");
     if (isfound)
     {
          printf("'%d' is found in position %d\nAnd no. of operations is %d", target, binary_position + 1, binary_operations);
     }
     else
     {
          printf("%d is not found in the array\nAnd no. of operations is %d\n", target, binary_operations);
     }
     free(array);
}

void linearSearch(int *array, int no_of_elements, int target)
{
     int position = -1;
     for (int i = 0; i < no_of_elements; ++i)
     {
          if (array[i] == target)
          {
               position = i + 1;
               break;
          }
     }
     printf("\nLINEAR SEARCH\n");
     if (position > 0)
     {
          printf("'%d' is found in position %d\nAnd no. of operations is %d", target, position, position);
     }
     else
     {
          printf("%d is not found in the array\nAnd no. of operations is %d\n", target, no_of_elements);
     }
}

int binarySearch(int first, int last, int target, int *array)
{
     binary_operations++;
     int mid = (first + last) / 2;
     if(mid<0||mid>=no_of_elements)
     {
          return 0;
     }
     else if (array[mid] == target)
     {
          binary_position = mid;
          return 1;
     }
     else if (array[mid]  > target)
     {
          return binarySearch(first, mid - 1, target, array);
     }
     else if (array[mid] < target)
     {
          return binarySearch(mid + 1, last, target, array);
     }
     else
     {
          return 0;
     }
}