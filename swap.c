#include<stdio.h>

void sswap(int x,int y)

{

int temp;

temp=x;

x=y;

y=temp;

printf("\nA = %d",x);

printf("\nB = %d",y);

}

void main()

{

int a,b;

printf("Enetr Value The A:-\n");

scanf("%d",&a);

printf("Enetr Value The B:-\n");

scanf("%d",&b);
sswap(a,b);

}
