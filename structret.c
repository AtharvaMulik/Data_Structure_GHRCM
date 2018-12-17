#include<stdio.h>
#include<stdlib.h>
struct student
{
char name[20];
int rollno;
}obj;
void display(struct student);
struct student accept();
int main()
{
obj=accept();
display(obj);
}
struct student accept()
{
printf("\n Enter Name:");
scanf("%s",obj.name);
printf("\n Enter Roll_No:");
scanf("%d",&obj.rollno);
return(obj);
}
void display(struct student obj)
{
printf("Name is %s",obj.name);
printf("Roll_No is %d",obj.rollno);
}
