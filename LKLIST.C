#include<stdio.h>
#include<conio.h>
typedef struct lklist
{
int info;
struct lklist *next;
}node;
void main()
{
void insertatbeg(node**,int);
void insertatend(node**,int);
void traverse(node*);
void deleteatbeg(node**);
void deleteatend(node**);
void insertafter(node**,int);
void deleteafter(node**,int);
node* search(node**,int);
int choice,item,aadd;
node *head=NULL;
node **add;
clrscr();
while(1)
{
printf("1-Insert beg\n2-Insert end\n3-traverse\n4-delete beg\n5-delete end\n6-Search element\n7-Insert After\n8-delete after\n9-exit");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("ENter");
scanf("%d",&item);
insertatbeg(&head,item);
break;
case 2:printf("ENter");
scanf("%d",&item);
insertatend(&head,item);
break;
case 3:if(head==NULL)
printf("List is empty");
else
traverse(head);
break;
case 4:
if (head==NULL)
printf("List empty");
else
deleteatbeg(&head);
break;
case 5:if(head==NULL)
printf("List is empty");
else
deleteatend(&head);
break;
case 6:
if(head==NULL)
printf("List is empty");

else
{printf("Enter element to search");
scanf("%d",&item);
search(&head,item); }
case 7:
if(head==NULL)
printf("List Empty");
else
{printf("Enter element to insert after");
scanf("%d",&item);
insertafter(&head,item);}break;
case 8:if(head==NULL)
printf("List empty");
else
{
printf("Enter element to delete after");
scanf("%d",&item);
deleteafter(&head,item);
} break;
case 9:exit(1);
default:printf("Invalid choice");getch();exit(2);
}
//getch();
}
}
void insertatbeg(node** start,int item)
{
node *temp;
temp=(node*)malloc(sizeof(node));
temp->info=item;
if(*start==NULL)
{
temp->next=NULL;
}
else
{
temp->next=*start;
}
*start=temp;
}
void insertatend(node **start,int item)
{
node *temp,*loc;
temp=(node*)malloc(sizeof(node));
temp->info=item;
temp->next=NULL;
if(*start==NULL)
{
*start=temp;
}
else
{
loc=*start;
while(loc->next!=NULL)
{
loc=loc->next;
}
loc->next=temp;
}
}

void traverse(node *start)
{
while(start!=NULL)
{
printf("%d",start->info);
start=start->next;
}
}
void deleteatbeg(node **start)
{
node *temp;
temp=*start;
*start=(*start)->next;
free(temp);
}
void deleteatend(node **start)
{
node *temp,*loc;
loc=*start;
if((*start)->next==NULL)
{
temp=*start;
*start=NULL;
}
else
{
while(((loc->next)->next)!=NULL)
{
loc=loc->next;
}
temp=loc->next;
loc->next=NULL;
}
free(temp);
}
node* search(node **start,int target)
{
node *loc;
loc=*start;
while(loc!=NULL)
{
if(loc->info==target)
{
//printf("Element found");
return loc;
}
loc=loc->next;
}
}

void insertafter(node** start,int item)
{
node *loc,*temp;
int newitem;
loc =search(start,item);
temp=(node*)malloc(sizeof(node));
printf("Enter element to insert");
scanf("%d",&newitem);
temp->info=newitem;
temp->next=loc->next;
loc->next=temp;
}
void deleteafter(node** start,int item)
{
node *loc,*temp;
loc=search(start,item);
temp=loc->next;
loc->next=temp->next;
free(temp);
}
