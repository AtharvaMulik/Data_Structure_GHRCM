#include<stdio.h>
void swap1(int x,int y)
{
int temp;
temp=x;
x=y;
y=temp;
}

void swap2(int *x,int *y)
{
int temp;
temp=*x;
*x=*y;
*y=temp;
}
void main()
{
int a,b;
printf("Enter the value of A:");
scanf("%d",&a);
printf("Enter the value of B:");
scanf("%d",&b);
swap1(a,b);
printf("\nA = %d",a);
printf("\nB = %d",b);
swap2(&a,&b);
printf("\nA = %d",a);
printf("\nB = %d",b);
}
