#include<stdio.h>
#define MAXSIZE 10
void shelsort(int x[],int n,int inc[],int nofinc)
{
int i,j,k,span,temp;
static int nc=0;
for(i=0;i<nofinc;i++)
{
  span=inc[i];
for(j=span;j<n;j++)
{
nc++;
temp=x[i];
for(k=j-span;k>=0&&temp<x[k];k=k-span)
 x[k+span]=x[k];
x[k+span]=temp;
}
}
printf("number of comparisons required=%d",nc);
}

void main()
{
int x[MAXSIZE],n,i,nofinc,inc[MAXSIZE/2];
printf("enter number of elemnts");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&x[i]);
}
printf("enter no of increments");
scanf("%d",&nofinc);
printf("enter values of increment");
for(i=0;i<nofinc;i++)
{
scanf("%d",&inc[i]);
}
shelsort(x,n,inc,nofinc);
printf("Sorted array is as follws");
for(i=0;i<n;i++)
printf("%d\t",x[i]);
}
