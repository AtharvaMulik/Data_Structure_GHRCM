#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct node
{
char name[50],add[50],mnum[50],gender[50],blood_grp[50],basic_sym[50];
int age,weight,height;
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
int n,item;
int ch,x,r,pr;
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
    printf("\nEnter Patient Name:");
    scanf("%s",&(p->name));
    printf("\nEnter Age of Patient:");
    scanf("%d",&(p->age));
    printf("\nEnter Patient Address :");
    scanf("%s",&(p->add));
    printf("\nEnter Mobile Number :");
    scanf("%s",&(p->mnum));
    printf("\nEnter Gender :");
    scanf("%s",&(p->gender));
    printf("\nEnter Blood Group :");
    scanf("%s",&(p->blood_grp));
    printf("\nEnter Symptoms :");
    scanf("%s",&(p->basic_sym));
    printf("\nEnter Height of Patient:");
    scanf("%d",&(p->height));
    printf("\nEnter Weight of Patient:");
    scanf("%d",&(p->weight));
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
    printf("\nEnter the Age to be searched-");
    scanf("%d",&value);

    do
    {
        Node* mid = middle(start, last);
        if (mid == NULL)
            return NULL;
if (mid->age == value)
        {printf("\n PATIENT NAME  PATIENT AGE  PATIENT ADDRESS PATIENT MOBILE_NO GNEDER BLOOD_GRP SYMPTOMS HEIGHT WEIGHT");
    printf("\n******************************************************************************************************");

    printf("\n******************************************************************************************************");
int i;
for(i=0;i<n;i++)
{
printf("\n  %s",mid->name);
printf("         %d",mid->age);
printf("           %s",mid->add);
printf("              %s",mid->mnum);

printf("        %s",mid->gender);
printf("   %s",mid->blood_grp);
        printf("         %s",mid->basic_sym);

        printf("    %d",mid->height);

        printf("   %d",mid->weight);
return;
}
        }
        else if (mid->age < value)
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

// Partitions the list taking the last element as the pivot
Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
    Node *pivot = end;
    Node *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->age < pivot->age)
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else // If cur LLNode is greater than pivot
        {
            // Move cur LLNode to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            Node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    // Update newEnd to the current last node
    (*newEnd) = tail;

    // Return the pivot LLNode
    return pivot;
}

//here the sorting happens exclusive of the end node
Node *quickSortRecur(Node *head, Node *end)
{
    // base condition
    if (!head || head == end)
        return head;

    Node *newHead = NULL, *newEnd = NULL;

    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    Node *pivot = partition(head, end, &newHead, &newEnd);

    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the LLNode before the pivot LLNode as NULL
        Node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);

        // Change next of last LLNode of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }

    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(Node **headRef)
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
printf("\nEnter the age to search and modify-");
scanf("%d",&x);

while(p!=NULL)
{
if(p->age==x)
{

    do
    {
        printf("\n 1].Name :");
        printf("\n 2].Age :");
        printf("\n 3].Address:");
        printf("\n 4].Mobile_No:");
        printf("\n 5].Gender:");
        printf("\n 6].Blood_Grp:");
        printf("\n 7].Symptoms:");
        printf("\n 8].Height");
        printf("\n 9].Weight");
        printf("\n 10].Return :");
        printf("\n Enter Choice That you want to Modity :");
        scanf("%d",&m);
    switch(m)
    {
        case 1:

    printf("\nEnter Patient Name:");
    scanf("%s",&(p->name));
    break;
    case 2:
    printf("\nEnter Age:");
    scanf("%d",&(p->age));
    break;
    case 3:
    printf("\nEnter Address :");
    scanf("%s",&(p->add));
    break;
    case 4:
    printf("\nEnter Mobile Number :");
    scanf("%s",&(p->mnum));
    break;
    case 5:
    printf("\nEnter Gender:");
    scanf("%s",&(p->gender));
    break;
    case 6:
    printf("\nEnter Blood Group :");
    scanf("%s",&(p->blood_grp));
    break;
    case 7:
    printf("\nEnter Basic Symptoms:");
    scanf("%s",&(p->basic_sym));
    break;
    case 8:
    printf("\nEnter Height:");
    scanf("%d",&(p->height));
    break;
    case 9:
    printf("\nEnter Weight:");
    scanf("%d",&(p->weight));
    break;
    case 10:
    return;
    default:
    break;

    }
}while(m!=12);
return;
}
p=p->next;
}
}

void create_queue()
{
     Node *temp,*p;
     int i;
     for(i=0;i<n;i++)
     {
      if (rear==NULL)
    {
        rear=(Node*)malloc(sizeof(Node)*100);
    printf("\nEnter Patient Name:");
    scanf("%s",&(rear->name));
    printf("\nEnter Age of Patient:");
    scanf("%d",&(rear->age));
    printf("\nEnter Patient Address :");
    scanf("%s",&(rear->add));
    printf("\nEnter Mobile Number :");
    scanf("%s",&(rear->mnum));
    printf("\nEnter Gender :");
    scanf("%s",&(rear->gender));
    printf("\nEnter Blood Group :");
    scanf("%s",&(rear->blood_grp));
    printf("\nEnter Symptoms :");
    scanf("%s",&(rear->basic_sym));
    printf("\nEnter Height of Patient:");
    scanf("%d",&(rear->height));
    printf("\nEnter Weight of Patient:");
    scanf("%d",&(rear->weight));
        rear->next=rear;
        front=rear;
    }
    else
    {
        temp=(Node*)malloc(sizeof(Node));
printf("\nEnter Patient Name:");
    scanf("%s",&(temp->name));
    printf("\nEnter Age of Patient:");
    scanf("%d",&(temp->age));
    printf("\nEnter Patient Address :");
    scanf("%s",&(temp->add));
    printf("\nEnter Mobile Number :");
    scanf("%s",&(temp->mnum));
    printf("\nEnter Gender :");
    scanf("%s",&(temp->gender));
    printf("\nEnter Blood Group :");
    scanf("%s",&(temp->blood_grp));
    printf("\nEnter Symptoms :");
    scanf("%s",&(temp->basic_sym));
    printf("\nEnter Height of Patient:");
    scanf("%d",&(temp->height));
    printf("\nEnter Weight of Patient:");
    scanf("%d",&(temp->weight));
            rear->next=temp;
        temp->next=NULL;
        rear=temp;
    }
     }
}

void display_queue(Node *front)
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
        {printf("\n PATIENT NAME  PATIENT AGE  PATIENT ADDRESS PATIENT MOBILE_NO GNEDER BLOOD_GRP SYMPTOMS HEIGHT WEIGHT");
    printf("\n******************************************************************************************************");

    printf("\n******************************************************************************************************");
while(p!=NULL)
        {
        printf("\n  %s",p->name);
printf("         %d",p->age);
printf("           %s",p->add);
printf("              %s",p->mnum);

printf("        %s",p->gender);
printf("   %s",p->blood_grp);
        printf("         %s",p->basic_sym);

        printf("    %d",p->height);

        printf("   %d",p->weight);
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
 printf("\n PATIENT NAME  PATIENT AGE  PATIENT ADDRESS PATIENT MOBILE_NO GNEDER BLOOD_GRP SYMPTOMS HEIGHT WEIGHT");
    printf("\n******************************************************************************************************");
       printf("\n  %s",temp->name);
printf("         %d",temp->age);
printf("           %s",temp->add);
printf("              %s",temp->mnum);

printf("        %s",temp->gender);
printf("   %s",temp->blood_grp);
        printf("         %s",temp->basic_sym);

        printf("    %d",temp->height);

        printf("   %d",temp->weight);
         free(temp);
    }
}
