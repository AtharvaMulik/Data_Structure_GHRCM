#include<stdio.h>
#include<malloc.h>

typedef struct node
{
int data;
struct node *next;
}node;

node *head,*p;

int n;

node* create(int);
void display(node*,int n);
node* insert_loc(node*,int x,int loc);
node* delete_loc(node *head,int x);
void search(node *head,int x);
node* rev(node *head);
void main()
{

int ch,loc,x;


do
{
printf("\nSingly linked list operation");
printf("\n1.Create");
printf("\n2.Display");
printf("\n3.Insert");
printf("\n4.Delete");
printf("\n5.Reverse");
printf("\n6.Search");
printf("\nEnter your choice-");
scanf("%d",&ch);
switch(ch)
{
case 1:
 printf("Enter no. of item");
scanf("%d",&n);
head=create(n);
break;
case 2:
 display(head,n);
 break;
case 3:
insert_loc(head,x,loc);
break;
case 4:
delete_loc(head,loc);
break;
case 5:
 p=rev(head);
display(p,n);
break;
case 6:
search(head,x);
break;
default:
break;
}
}while(ch!=8);

}

node* create(int n)
{
node *p;
int i;
head=NULL;

if(head==NULL)
{
 head=(node*)malloc(sizeof(node));
 head->next=NULL;
 scanf("%d",&(head->data));
 p=head;
}

for(i=1;i<n;i++)
{
p->next=(node*)malloc(sizeof(node));
p=p->next;
scanf("%d",&(p->data));
p->next=NULL;
}
return(head);
}

void display(node *head,int n)
{
int i;
node *temp;
temp=head;
if(temp==NULL)
{
printf("list is empty");
}
else
{
printf("\n list is::");
for(i=0;i<n;i++)
{
printf("%d\t",temp->data);
temp=temp->next;
}
}
}

node* insert_loc(node *head,int x,int loc)
{
node *p,*q;
int i;
printf("Enter the new position-");
scanf("%d",&loc);
printf("Enter the new data-");
scanf("%d",&x);
 p=(node*)malloc(sizeof(node));
 p->data=x;
p->next=NULL;
if(loc==1)
{
p->next=head;
return(p);
}
q=head;
for(i=1;i<loc-1;i++)
{
if(q!=NULL)
{
q=q->next;
}
}
p->next=q->next;
q->next=p;
n=n+1;
return(head);
}
node* delete_loc(node *head,int loc)
{
node *p,*q;
int i;
printf("\nEnter ihe location-");
scanf("%d",&loc);
if(loc==1)
{
p=head;
head=head->next;
free(p);
return(head);
}
q=head;
for(i=1;i<loc-1;i++)
{
q=q->next;
}
p=q->next;
q->next=p->next;
free(p);
n=n-1;
return(head);
}
void search(node *head,int x)
{
int i;
node *p;
p=head;
printf("\nEnter the element to be searched-");
scanf("%d",&x);
while(p!=NULL)
{
if(p->data==x)
{
printf("\nEnter is found");
return;
}
p=p->next;
}
printf("\nElement is not found");
}

node* rev(node *head)
{
node *P,*q,*r;
p=NULL;
q=head;
r=q->next;
while(q!=NULL)
{
q->next=p;
p=q;
q=r;
if(r!=NULL)
{
r=r->next;
}


}
return(p);
}
