#include <stdio.h>
int main()
{
     unsigned int no_of_inputs;
     //getting no. of inputs
     printf("Enter the no. of inputs: ");
     scanf("%u", &no_of_inputs);
     //declaring array
     int arr[no_of_inputs];
     int sum_of_array = 0;
     //storing input to array and adding the terms in array
     for (int i = 0; i < no_of_inputs; ++i)
     {
          printf("Enter the input %d : ", i + 1);
          scanf("%d", &arr[i]);
          sum_of_array += arr[i];
     }
     printf("Summation of inputs is %d\n", sum_of_array);
}