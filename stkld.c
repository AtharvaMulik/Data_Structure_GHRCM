#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *ptr;
}*top,*top1,*temp;

int topelement();
void push(int data);
void pop();
void empty();
void display();
void destroy();
void stack_count();
void create();
int count=0;

void main()
{
int no,ch,e;
printf("\n 1.Push");
printf("\n 2.Pop");
printf("\n 3.Top");
printf("\n 4.Empty");
printf("\n 5.Exit");
printf("\n 6.Display");
printf("\n 7.Stack_Count");
printf("\n 8.Destroy_Stack");

create();

while(1)
{
printf("\nEnter Your Choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter Data:");
scanf("%d",&no);
push(no);
break;
case 2:
pop();
break;
case 3:
if(top==NULL)
printf("\nNo Elements in Stack:");
else
{
e=topelement();
printf("\n Top Element:%d",e);
}
break;
case 4:
empty();
break;
case 5:
exit(0);
//break;
case 6:
display();
break;
case 7:
stack_count();
break;
case 8:
destroy();
break;
default:
printf("\n Wrong Choice");
break;
}
}
}


void create()
{
top==NULL;
}
void stack_count()
{
printf("\n No OF Elements in Stack:%d",count);
}
void push(int data)
{
if(top==NULL)
{
top=(struct node *)malloc(1*sizeof(struct node));
top->ptr=NULL;
top->info=data;
}
else
{
temp=(struct node *)malloc(1*sizeof(struct node));
temp->ptr=top;
temp->info=data;
top=temp;
}
count++;
}

void display()
{
top1=top;
if(top1==NULL)
{
printf("\n Stack is Empty:");
return;
}
while(top1 != NULL)
{
printf("%d",top1->info);
top1=top1->ptr;
}
}

void pop()
{
top1=top;
if(top1==NULL)
{
printf("\nError....");
return;
}
else
{
top1=top1->ptr;
printf("\nPopped Value:%d",top->info);
free(top);
top=top1;
count--;
}
}
int topelement()
{
return(top->info);
}
void empty()
{
if(top==NULL)
{
printf("\n Stack is Empty:");
}
else
{
printf("\n Stack is not Empty with %d elements:",count);
}
}
void destroy()
{
top1=top;
while(top1 != NULL)
{
top1=top->ptr;
free(top);
top=top1;
top1=top1->ptr;
}
free(top1);
top=NULL;
printf("\nAll Stack Elements Destroyed:");
count=0;
}
