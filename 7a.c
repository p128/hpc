#include <stdio.h>
#include <omp.h>
#include<stdlib.h>

int main()
{
int *array, i, N, max, c;
printf("Enter the number of elements\n");
scanf("%d", &N);

if (N <= 0)
{
printf("The array elements cannot be stored\n");
exit(1);
}

array = (int *) malloc(sizeof(int) * N);

for (i = 0; i < N; i++)
array[i] = rand()%1000;

if (N== 1)
{
printf("The Largest Number In The Array is %d", array[0]);
exit(1);
}

max = 0;
omp_set_num_threads(8);
#pragma omp parallel for
for (i = 0; i < N; i = i + 1)
{
if (array[i] > max)
#pragma omp critical
if (array[i] > max)
max = array[i];
}

/* Serial Calculation */
c = array[0];
for (i = 1; i < N ; i++)
if (array[i] > c )
c  = array[i];

printf("The Input Array Elements Are \n");
for (i = 0; i < N ; i++)
printf("\t%d", array[i]);
printf("\n");

/* Checking For Output Validity */
if (c  == max)
printf("The Max Value Is Same From Serial And Parallel OpenMP Directive");
else
{
printf("The Max Value Is Not Same In Serial And Parallel OpenMP Directive");
exit(1);
}
printf("\n");
free(array);
printf("The Largest Number In The Given Array Is %d\n", max);
}
