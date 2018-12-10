#include<stdio.h>

#include<stdlib.h>

struct student

{

int rollno;

char name[20];

}*obj;

void main()

{

int ch,n,i,j;

printf("\n Enter the Values:-");

scanf("%d",&n);

obj=(struct student *)malloc(sizeof(struct student)*n);

do

{

printf("\n Enter your choice:-");

scanf("%d",&ch);


switch(ch)

{

case 1:

for(i=0;i<n;i++)

{

printf("\n Enter Roll Number:-");

scanf("%d",&obj[i].rollno);

printf("\n Enter Name:-");

scanf("%s",obj[i].name);

}

break;

case 2:

printf("\n Roll No");

printf("  Name");

for(j=0;j<n;j++)

{

printf("\n %d",obj[j].rollno);

printf("\t   %s",obj[j].name);

}

}

}while(ch!=3);

}