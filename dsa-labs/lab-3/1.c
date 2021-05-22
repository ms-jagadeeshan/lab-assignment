#include <stdio.h>
#include <stdlib.h>

void initialize(int, int, int *);
void encript(int, int, int *);
void decript(int, int, int *);
void print(int, int, int *);

int main()
{
     int row, column;
     printf("Enter the number of rows: ");
     scanf("%d", &row);
     printf("Enter the number of column : ");
     scanf("%d", &column);

     int *matrix = (int *)malloc(row * column * sizeof(int));
     initialize(row, column, matrix);
     printf("\nGenerated %d✕ %d matrix:\n", row, column);
     print(row, column, matrix);

     encript(row, column, matrix);
     decript(row, column, matrix);
     free(matrix);
}

//funtion to initialize the matrix with random numbers
void initialize(int row, int column, int *matrix)
{

     for (int i = 0; i < row; i++)
     {
          for (int j = 0; j < column; j++)
          {
               *((matrix + j) + (i * column)) = rand() % 10;
          }
     }
}

//funtion to encript matrix
void encript(int row, int column, int *matrix)
{
     for (int i = 0; i < row; i++)
     {
          for (int j = 0; j < column; j++)
          {
               if (i == 0 || j == 0 || i == (row - 1) || j == (column - 1))
                    *((matrix + j) + (i * column)) += (i + 1);
               else
                    *((matrix + j) + (i * column)) -= (i + j + 2);
          }
     }
     printf("\n\nEncripted matrix :\n");
     print(row, column, matrix);
}

//function to decript the matrix
void decript(int row, int column, int *matrix)
{
     for (int i = 0; i < row; i++)
     {
          for (int j = 0; j < column; j++)
          {
               if (i == 0 || j == 0 || i == (row - 1) || j == (column - 1))
                    *((matrix + j) + (i * column)) -= (i + 1);
               else
                    *((matrix + j) + (i * column)) += (i + j + 2);
          }
     }
     printf("\n\nDecripted matrix :\n");
     print(row, column, matrix);
}

//function to print the matrix
void print(int row, int column, int *matrix)
{
     for (int i = 0; i < row; i++)
     {
          printf("\t");
          for (int j = 0; j < column; j++)
          {
               printf("%-2d ", *((matrix + j) + (i * column)));
          }
          printf("\n");
     }
}
