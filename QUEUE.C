#include<stdio.h>
#include<conio.h>
#define MAX 10
typedef struct queuetype
{
int a[MAX];
int front,rear;
}queue;
void main()
{
int isunderflow(queue);
int isoverflow(queue);
void enqueue(queue *,int);
int dequeue(queue*);
 queue q;

 int n;
 int item;
  q.front=q.rear=-1;
 while(1)
 {
 printf("Enter your choice \n 1-Insert in queue\n");
 printf("2-Delete from queue\n 3-exit");

 scanf("%d",&n);
 switch(n)
 {
 case 1:if(isoverflow(q))
 printf("Over flop detected");
 else
{ printf("Enter item to insert");
 scanf("%d",&item);
 enqueue(&q,item);    }
 break;
 case 2:
 if(isunderflow(q))
 printf("Under flow detected");
 else
 item=dequeue(&q);
 printf("%d",item);
 break;
 case 3:exit(1); break;
 default:printf("Wrong choice");
 getch();
 exit(2);
}
}
}
int isunderflow(queue q)
{
if(q.front==-1)
return 1;
else
return 0;
}
int isoverflow(queue q)
{
if(q.rear==MAX-1)
return 1;
else
return 0;
}
void enqueue(queue *q,int item)
{
int i;
if(q->front==-1)
{
q->front=0;
q->rear=0;
}
else if(q->rear<MAX-1)
{
q->rear=q->rear+1;

}
else if(q->front>0&&q->rear==MAX-1)
{
for(i=q->front;i<=q->rear;i++)
{
q->a[i-q->front]=q->a[i];
}
q->rear=q->rear-q->front;
q->front=0;
q->rear=q->rear+1;

}
q->a[q->rear]=item;
}
int dequeue(queue *q)
{
int item;
item=q->a[q->front];
if(q->front==q->rear)
{
q->front=q->rear=-1;
}
else
{
q->front=q->front+1;
}
return item;
}
