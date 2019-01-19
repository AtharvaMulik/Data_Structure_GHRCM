#include<stdio.h>
#include<stdlib.h>
struct student
{
char name[20];
int rollno;
};
struct student accept();
int main()
{
struct student obj;
obj=accept();
printf("\n %s %d",obj.name,obj.rollno);
}
struct student accept()
{
struct student obj1;
printf("\n Enter Name:");
scanf("%s",obj1.name);
printf("\n Enter Roll_No:");
scanf("%d",&obj1.rollno);
return(obj1);
}
