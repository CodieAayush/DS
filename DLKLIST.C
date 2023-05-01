#include<stdio.h>
#include<conio.h>
typedef struct dlklist
{
struct dlkist *prev;
int info;
struct dlklist *next;
}
node;
void main()
{
void insert_at_beg(node**,node**,int);
void insert_at_end(node**,node**,int);
void traverse(node*);
void rev_traverse(node*);
void insert_after(node**,node**,int);
node* search(node **,int );
int ch,item;
node *head,*tail;

head=NULL;
tail=NULL;
while(1)
{
printf("Enter choice");
printf("1-Insert at beg\n");
printf("2-Insert at end\n");
printf("3-Traverse\n");
printf("4-Reverse Traverse\n");
printf("5-Search Element\n");
printf("6-Insert After\n");
printf("7-Insert Before");
printf("10-exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter");
scanf("%d",&item);
insert_at_beg(&head,&tail,item);break;
case 2:
printf("Enter");
scanf("%d",&item);
insert_at_end(&head,&tail,item);break;
case 3:
if(head==NULL)
printf("List is empty");
else
traverse(head);
break;
case 4:
if(head==NULL)
printf("List is empty");
else
rev_traverse(tail);
break;
case 5:
if(head==NULL)
printf("List is empty");
else
{printf("Enter element to search");
scanf("%d",&item);
search(&head,item); }
break;
case 6:
printf("Enter element to insert after");
scanf("%d",&item);
insert_after(&head,&tail,item);break;
case 7:
printf("Enter element to insert after");
scanf("%d",&item);
//insert_before(&head,&tail,item);break;



case 10:exit(1);
default:printf("wrong Input");exit(2);
}
}
}
void insert_at_beg(node** start,node** end,int item)
{
node *temp;
temp=(node*)malloc(sizeof(node));
temp->info=item;
temp->prev=NULL;
if(*start==NULL)
{
temp->next=NULL;
*end=temp;
}
else
{
(*start)->prev=temp;
temp->next=*start;
}
*start=temp;
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

void insert_at_end(node **start,node **end,int item)
{
node *temp;
temp=(node*)malloc(sizeof(node));
temp->info=item;
temp->next=NULL;
if(*start==NULL)
{
temp->prev=NULL;
*start=temp;
}
else
{
temp->prev=end;
(*end)->next=temp;
}
*end=temp;
}
void insert_after(node **start,node **end,int item)
{
node *temp,*loc;
int a;
loc=search(*start,item);
if(loc==NULL)
{
printf("Element not found");
}
else
{
printf("Enter element to insert");
scanf("%d",&a);
temp=(node*)malloc(sizeof(node));
temp->info=a;
//temp->prev=loc;
//temp->next=loc->next;
 if(loc->next==NULL)
 {
 loc->next=temp;
 *end=temp;
 }
 else
 {
 (loc->next)->prev=temp;
 loc->next=temp;
 }
}
}
/*
void insert_before(node** start,node** end,int item)
{
node *temp,*loc;
int a;
loc=search(*start,item);
if(loc==NULL)
{
printf("Element not found");
}
else
{
printf("Enter element to insert");
scanf("%d",&a);
temp=(node*)malloc(sizeof(node));
temp->info=a;
temp->next=
 */

void traverse(node *start)
{
while(start!=NULL)
{
printf("%d",start->info);
start=start->next;
}
}
void rev_traverse(node *end)
{
while(end!=NULL)
{
printf("%d",end->info);
end=end->prev;
}
}