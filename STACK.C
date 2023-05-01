#include<stdio.h>
#include<conio.h>
#define MAX 10
typedef struct Stacktype
{
int a[MAX];
int top;
}Stack;

void main()
{
int isoverflow(Stack);
int isunderflow(Stack);
void Push(Stack*,int);
int Pop(Stack*);
int Peep(Stack);
int ch,item,a;
Stack S;
S.top=-1;
while(1)
{
printf("1-Push");
printf("2-Pop");
printf("3-Peep");
printf("4-Exit");
printf("Enter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
if(isoverflow(S))
printf("Stack over flow");
else
{
printf("Enter Item to push");
scanf("%d",&item);
Push(&S,item); }
break;
case 2:
if(isunderflow(S))
printf("Stack underflow");
else
{
item=Pop(&S);
printf("Pop item in %d",item);
}
break;
case 3:

item=Peep(S);
printf("%d",item);  break;
case 4:
exit(1);break;
default:printf("Wrong Input");getch();exit(2);
}
}
}
void Push(Stack*stk,int item)
{
stk->top=stk->top+1;
stk->a[stk->top]=item;
}
int Pop(Stack *stk)
{
int item;
item=stk->a[stk->top];
stk->top=stk->top-1;
return item;
}
int isoverflow(Stack s)
{
if(s.top==MAX-1)
return 1;
else
return 0;
}
int isunderflow(Stack s)
{
if(s.top==-1)
return 1;
else
return 0;
}
int Peep(Stack s)
{
return s.a[s.top];
}