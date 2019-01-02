#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
int i, n =1000, a[1000], b[1000], sum;

for (i=0; i < n; i++)
a[i] = b[i] = i;
sum = 0.0;

#pragma omp parallel for reduction(+:sum)
for (i=0; i < n; i++)
sum = sum + (a[i] + b[i]);
printf(" Sum = %d\n",sum);

}
