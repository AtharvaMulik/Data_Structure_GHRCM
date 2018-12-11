#include<stdio.h>
#include<stdlib.h>

void inc(int);

void incre(int *);

void main()
{
int n=10;
printf("\n Value of n in main::%d",n);
inc(n);
printf("\n Value of n after call by value::%d",n);
incre(&n);
printf("\n Value of n after call by reference::%d",n);
}
void inc(int n)
{
n++;
}
void incre(int *n)
{
*n=*n+1;
}
