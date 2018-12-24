#include<stdio.h>
#include<stdlib.h>
void main()
{
int a[20],i,n,temp,j;
printf("\n Enter The Elements For Sorting:- ");
scanf("%d",&n);
printf("\n Enter Elements");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
printf("\n Sorted Elements are:-");
for(i=0;i<n;i++)
{
printf("\n %d",a[i]);
printf("\n");
}
}

