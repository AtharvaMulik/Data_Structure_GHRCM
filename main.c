#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct node
{
     char name[30];
    char phonenumber[30];
    int amount;
    char date[30];
    char address[30];
    char plan[10];

struct node *next;
}Node;
Node* insert_loc(Node*,Node*);
Node* rev(Node *head);
Node* sort(Node *head);
Node* sort1(Node *head);
Node* partition(Node* head,Node* end,Node** newHead,Node** newEnd);
Node *quickSortRecur(Node *head,Node *end);
Node* middle(Node* start, Node* last);
void BinarySearch(Node *head, int value);
void modify(Node* head,int x);
void create_queue();
void del_queue();
void display_queue(Node *front);
Node *rear=NULL;
Node *front=NULL;
Node *p,*head;
intn,item;
int ch,x,r,pr,n;
void main()
{
printf("\nEnter Number of Nodes:-");
scanf("%d",&n);
do
    {
printf("\n 1].create ");
printf("\n 2].Display ");
printf("\n 3].insert");
printf("\n 4].Delete");
printf("\n 5].reverse");
printf("\n 6].search");
printf("\n 7].sort");
printf("\n 8].Modify \n 9].Exit\n");
printf("\nEnter Your Choice :-");
scanf("%d",&ch);
switch(ch)
    {
case 1:

create_queue();
break;
case 2:
display_queue(front);
break;
case 3:
front= insert_loc(front,rear);
rear=rear->next;
        n=n+1;
break;
case 4:
del_queue();
        n=n-1;
break;
case 5:
        p=rev(front);
display_queue(p);
break;
case 6:
BinarySearch(front,x);
break;
case 7:
quickSortRecur(front,rear);
display_queue(front);
break;
case 8:
modify(front,x);
break;
case 9:
exit(0);
default:
printf("\nWrong Choice!!!!!");
    }
}while(ch!=10);
}


Node* insert_loc(Node *front,Node *rear)
{
Node *p,*q;
int i;
printf("Enter New :::");
p=(Node*)malloc(sizeof(Node));
printf("\nEnter Name:");
scanf("%s",(p->name));
printf("\nEnter mobile number:");
scanf("%s",(p->phonenumber));
printf("\nEnter Address :");
scanf("%s",(p->address));
printf("\nEnter user plan :");
scanf("%s",(p->plan));
printf("\nEnter user bill amount:");
scanf("%d",&(p->amount));
printf("\nEnter date:");
scanf("%s",(p->date));
p->next=NULL;
p->next=rear->next;
rear->next=p;
return(front);
}
Node* rev(Node *rear)
{
Node *P,*q,*r;
p=NULL;
q=front;
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
Node* middle(Node *start, Node *last)
{
if (start == NULL)
return NULL;

 Node *slow = start;
 Node *fast = start->next;

while (fast != last)
    {
fast = fast->next;
if (fast != last)
        {
slow = slow->next;
fast = fast->next;
        }
    }

return slow;
}

void BinarySearch(Node *front, int value)
{
     Node *start = front;
     Node *last = NULL;
    printf("\nEnter the Amount to be searched-");
    scanf("%d",&value);

    do
    {
        Node* mid = middle(start, last);
        if (mid == NULL)
            return NULL;
if (mid->amount == value)
    {
        printf("\n  USER NAME        MOBILE NO        USER ADDRESS         USER PLAN         BILL_AMOUNT           DATE      ");
    printf("\n*******************************************************************************************************");

    printf("\n********************************************************************************************************");
for(int i=0;i<n;i++)
{
printf("\n  %s",mid->name);
printf("         %s",mid->phonenumber);
printf("           %s",mid->address);
printf("              %s",mid->plan);
printf("        %d",mid->amount);
printf("        %s",mid->date);

    printf("\n******************************************************************************************************");
return;
}
        }
        else if (mid->amount< value)
            start = mid->next;
        else
            last = mid;

    } while (last == NULL || last != start);
    printf("\nElement is not found");
}

Node *getTail(Node *cur)
{
while (cur != NULL && cur->next != NULL)
cur = cur->next;
return cur;
}
Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
    Node *pivot = end;
    Node *prev = NULL, *cur = head, *tail = pivot;
while (cur != pivot)
    {
if (cur->amount< pivot->amount)
        {
if ((*newHead) == NULL)
                (*newHead) = cur;

prev = cur;
cur = cur->next;
        }
else
        {

if (prev)
prev->next = cur->next;
            Node *tmp = cur->next;
cur->next = NULL;
tail->next = cur;
tail = cur;
cur = tmp;
        }
    }

if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;
return pivot;
}

Node *quickSortRecur(Node *head, Node *end)
{
if (!head || head == end)
return head;

    Node *newHead = NULL, *newEnd = NULL;

    Node *pivot = partition(head, end, &newHead, &newEnd);

if (newHead != pivot)
    {
                Node *tmp = newHead;
while (tmp->next != pivot)
tmp = tmp->next;
tmp->next = NULL;

newHead = quickSortRecur(newHead, tmp);
tmp = getTail(newHead);
tmp->next =  pivot;
    }
pivot->next = quickSortRecur(pivot->next, newEnd);

return newHead;
}
voidquickSort(Node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
return;
}

void modify(Node* front,int x)
{
int i;
int m,flag=0;
Node *p;
p=front;
printf("\nEnter the a,amount to search and modify-");
scanf("%d",&x);

while(p!=NULL)
{
if(p->amount==x)
{

do
    {
        printf("\n 1].Name :");
        printf("\n 2].phone number :");
        printf("\n 3].Address:");
        printf("\n 4].Plan:");
        printf("\n 5].Amount:");
        printf("\n 6].Date:");
        printf("\n 7].Return :");
printf("\n Enter Choice That you want to Modity :");
scanf("%d",&m);
switch(m)
    {
 case 1:

    printf("\nEnter user Name:");
    scanf("%s",(p->name));
    break;
    case 2:
    printf("\nEnter phone number:");
    scanf("%s",(p->phonenumber));
    break;
    case 3:
    printf("\nEnter Address :");
    scanf("%s",(p->address));
    break;
    case 4:
    printf("\nEnter plan:");
    scanf("%s",(p->plan));
    break;
    case 5:
    printf("\nEnter amount:");
    scanf("%d",&(p->amount));
    break;
    case 6:
    printf("\nEnter date :");
    scanf("%s",&(p->date));
    break;
    case 7:
    return;
    default:
    break;

    }
}while(m!=8);

return;
}
p=p->next;
}
}

voidcreate_queue()
{
     Node *temp,*p;
int i;
for(i=0;i<n;i++)
     {
if (rear==NULL)
    {
rear=(Node*)malloc(sizeof(Node)*100);
 printf("\nEnter Name:");
scanf("%s",(rear->name));
printf("\nEnter mobile number:");
scanf("%s",(rear->phonenumber));
printf("\nEnter Address :");
scanf("%s",(rear->address));
printf("\nEnter user plan :");
scanf("%s",(rear->plan));
printf("\nEnter user bill amount:");
scanf("%d",&(rear->amount));
printf("\nEnter date:");
scanf("%s",(rear->date));

rear->next=rear;
front=rear;
    }
else
    {
temp=(Node*)malloc(sizeof(Node));
printf("\nEnter Name:");
scanf("%s",(temp->name));
printf("\nEnter mobile number:");
scanf("%s",(temp->phonenumber));
printf("\nEnter Address :");
scanf("%s",(temp->address));
printf("\nEnter user plan :");
scanf("%s",(temp->plan));
printf("\nEnter user bill amount:");
scanf("%d",&(temp->amount));
printf("\nEnter date:");
scanf("%s",(temp->date));
rear->next=temp;
temp->next=NULL;
rear=temp;
    }
     }
}

voiddisplay_queue(Node *front)
{
    Node *p;
int sum=0;
int j=0;

if(front==NULL)
    {
printf("\n*Queue Underflow*\n");
    }
else
    {
        p=front;
        { printf("\n  USER NAME        MOBILE NO        USER ADDRESS         USER PLAN         BILL_AMOUNT           DATE      ");
    printf("\n*******************************************************************************************************");

    printf("\n********************************************************************************************************");


while(p!=NULL)
        {
printf("\n  %s",p->name);
printf("         %s",p->phonenumber);
printf("           %s",p->address);
printf("              %s",p->plan);
printf("        %d",p->amount);
printf("        %s",p->date);


printf("\n******************************************************************************************************");
p=p->next;
        }
    }
}
}
void del_queue()
{
    Node *temp;
if(front==NULL)
    {
printf("\n*Queue Underflow*\n");
    }
else
    {
temp = front;
front=front->next;
printf("\n\nData At Front::\n\n");
   printf("\n\nData At Front::\n\n");
printf("\n  USER NAME        MOBILE NO        USER ADDRESS         USER PLAN         BILL_AMOUNT           DATE      ");
    printf("\n*******************************************************************************************************");

    printf("\n********************************************************************************************************");
printf("\n  %s",temp->name);
printf("         %s",temp->phonenumber);
printf("           %s",temp->address);
printf("              %s",temp->plan);
printf("        %d",temp->amount);
printf("        %s",temp->date);
free(temp);
    }
}


