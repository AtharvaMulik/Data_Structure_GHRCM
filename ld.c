#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int r_no;
    char name[20],add[20],brch[20];
    struct node *next;
}Node;

Node *p,*head;
Node* create(int);
void display(Node*,int n);
Node* insert(Node*,int x,int loc);
Node* delete_loc(Node *head,int loc);
Node* rev(Node *head);
int n;
void main()
{
    int ch,loc,x;
    do
    {
        printf("\n1.Create");
        printf("\n2.Display");
        printf("\n3.Insert");
        printf("\n4.Delete");
        printf("\n5.Reverse");
        printf("\nEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n Enter No of Item:");
            scanf("%d",&n);
            head=create(n);
            break;
        case 2:
            display(head,n);
            break;
        case 3:
            head=insert(head,x,loc);
            n=n+1;
            break;
        case 4:
            delete_loc(head,loc);
            n=n-1;
            break;
        case 5:
            p=rev(head);
            display(p,n);
            break;
        default:
            break;
        }
    }while(ch!=6);
}

Node* create(int n)
{
    int i;
    if(head==NULL)
    {
        head=(Node*)malloc(sizeof(Node));
        head->next=NULL;
        printf("\nEnter Roll_no:");
        scanf("%d",&(head->r_no));
        printf("\nEnter Name:");
        scanf("%s",&(head->name));
        printf("\nEnter Address:");
        scanf("%s",&(head->add));
        printf("\nEnter Branch:");
        scanf("%s",&(head->brch));
        p=head;
    }
for(i=1;i<n;i++)
{
    p->next=(Node*)malloc(sizeof(Node));
    p=p->next;
        printf("\nEnter Roll_no:");
        scanf("%d",&(p->r_no));
        printf("\nEnter Name:");
        scanf("%s",&(p->name));
        printf("\nEnter Address:");
        scanf("%s",&(p->add));
        printf("\nEnter Branch:");
        scanf("%s",&(p->brch));
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
        printf("\nList is Empty:");
    }
else
{
    printf("\n Roll_No    Name     Address    Branch");
    for(i=0;i<n;i++)
    {
        printf("\n %d",temp->r_no);
        printf("     %s",temp->name);
        printf("        %s",temp->add);
        printf("           %s",temp->brch);
        temp=temp->next;
    }
}
}

Node* insert(Node *head,int x,int loc)
{
    Node *p,*q;
    int i;
    printf("\nEnter the New Position:");
    scanf("%d",&loc);
    printf("\n Enter New...");
    p=(Node*)malloc(sizeof(Node));
        printf("\nEnter Roll_no:");
        scanf("%d",&(p->r_no));
        printf("\nEnter Name:");
        scanf("%s",&(p->name));
        printf("\nEnter Address:");
        scanf("%s",&(p->add));
        printf("\nEnter Branch:");
        scanf("%s",&(p->brch));
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
     return(head);
}

Node* delete_loc(Node *head,int loc)
{
    Node *p,*q;
    int i;
    printf("\n Enter The Location:");
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
    return(head);
}

Node* rev(Node *head)
{
    Node *p,*q,*r;
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
