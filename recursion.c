#include<stdio.h>
#include<stdlib.h>
int fact(int);
void main()
{
int n,factorial;
printf("Enter the n:");
scanf("%d",&n);
factorial=fact(n);
printf("Factorial is.. %d",factorial);
}
int fact(int n)
{
if(n==0)
{
return(1);
}
return(n*fact(n-1));
}
