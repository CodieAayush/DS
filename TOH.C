#include<stdio.h>
#include<conio.h>
static int i;
void main()
{
 void toh(char ,char,char,int);
 long double n;
 char a,b,c;
 a='a';
 b='b';
 c='c';
 printf("Input number of disc");
 scanf("%Ld",&n); // fflush(stdin);
 toh(a,b,c,n);
 printf("\nStatic %d",i);
 getch();
}
void toh(char a,char b,char c,int n)
{
i++;
if(n==1)
{printf("\nmove disc from %c to %c",a,b);  }
else
{
//fflush(stdin);
toh(a,c,b,n-1);
printf("\nmove disc from %c to %c",a,b);
toh(c,b,a,n-1);
}

}
