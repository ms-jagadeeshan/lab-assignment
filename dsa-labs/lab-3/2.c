#include <stdio.h>
#include <stdlib.h>
void print(int, int *);

int main()
{
     int order;
     printf("Enter the number of  order : ");
     scanf("%d", &order);
     int no_of_elem = ((order * order) + order) * 0.5;
     int *matrix = (int *)malloc(no_of_elem * sizeof(int));
     printf("\nGenerated elements");
     for (int i = 0; i < no_of_elem; i++)
     {
          matrix[i] = rand() % 20;
          printf("% d", matrix[i]);
     }
     printf("\nGenerated %d✕ %d symmatric matrix:\n", order, order);
     print(order, matrix);

     free(matrix);
}

//function to print the matrix
void print(int order, int *matrix)
{
     for (int i = 0; i < order; i++)
     {
          printf("\t");
          for (int j = 0; j < order; j++)
          {
               if (i <= j)
               {
                    int correction = ((i) * (i + 1) * 0.5);
                    printf("%02d ", *((matrix + j) + (i * order) - correction));
               }
               else
               {
                    if (i != j)
                    {
                         int correction = ((j) * (j + 1) * 0.5);
                         printf("%02d ", *((matrix + i) + (j * order) - correction));
                    }
               }
          }
          printf("\n");
     }
}