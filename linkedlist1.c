#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *next;
}Node;
Node* create(int);
void display(Node *,int);
Node *p,*head;
int n;
void main()
{

printf("Enter Number of Nodes:-");
scanf("%d",&n);
head=create(n);
display(head,n);
}
Node* create(int n)
{
int i;
head =NULL;
if(head==NULL)
{
head=(Node*)malloc(sizeof(Node));
head->next=NULL;
printf("Enter Data");
scanf("%d",&(head->data));
p=head;
}
for(i=1;i<n;i++)
{
p->next=(Node*)malloc(sizeof(Node));
p=p->next;
printf("Enter Data");
scanf("%d",&(p->data));
p->next=NULL;
}
return(head);
}
void display(Node* head,int n)
{
int i;
Node *temp;
temp=head;
if(temp==NULL)
{
printf("List is Empty");
}
else
{
for(i=0;i<n;i++)
{
printf("Data is %d",temp->data);
temp=temp->next;
}
}
}
