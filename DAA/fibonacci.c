#include<stdio.h>
int fibonacci(int n)
{
if(n==0)
{
return 0;
}
if(n==1)
{
return 1;
}
return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
int n,first=0,second=1,next,i;
printf("enter no.of terms:\n");
scanf("%d",&n);
printf("\nfibonacci series using iterative:\n");
for(i=0;i<n;i++)
{
if(i<=1)
{
next=i;
}
else
{
next=first+second;
first=second;
second=next;
}
printf("%d  ",next);
}
printf("\nFibonacci series using recursive:\n");
for(i=0;i<n;i++)
{
printf("%d  ",fibonacci(i));
}
}
