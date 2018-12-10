#include<stdio.h>


struct student

{

int rollno;

char name[20];

}obj;

void main()

{


int ch,n;

do

{

printf("\n Enter your choice:-");

scanf("%d",&ch);

switch(ch)

{

case 1:

printf("\n Enter Roll Number:-");

scanf("%d",&obj.rollno);

printf("\n Enter Name:-");

scanf("%s",obj.name);

break;

case 2:

printf("\n Roll No:-");

printf("%d \t",obj.rollno);

printf("\n Name:-");

printf("%s \t",obj.name);

}

}
while(ch!=3);

}

