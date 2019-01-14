#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int arr[],int n)
{
int i,key,j;
for(i=1;i<n;i++)
{
key=arr[i];
j=i-1;
while(j>=0&&arr[j]>key)
{
arr[j+1]=arr[j];
j=j-1;
}
arr[j+1]=key;
}
printf("\n Sorted Array:-");
for(i=0;i<n;i++)
{
printf("%d\t",arr[i]);
}
}
int main()
{
int arr[20],n,i;
printf("\n Enter number of Elements:-");
scanf("%d",&n);
printf("\n Enter Array Elements:-");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
insertion_sort(arr,n);
}
