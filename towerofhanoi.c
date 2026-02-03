#include<stdio.h>
 void towerofhanoi(int n, int s, int a, int d)
 {
    if(n==1)
    {
   printf("move the disk 1 from %c to %c\n",s,d);
   return;
    }
    towerofhanoi(n-1 ,s ,d ,a);
    printf("move disk %d from %c to %c\n",n,s,d);
   
    towerofhanoi(n-1,a,s,d);
 }
int main()
{
int n;
printf("enter the no of disk");
scanf("%d",&n);
printf("\nrequired moves:\n");
towerofhanoi(n, 's', 'a', 'd');


}
