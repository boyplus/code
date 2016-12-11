#include<stdio.h>
#include<math.h>
int main()
{
    int d,m,i;
    scanf("%d %d",&d,&m);
    char day[7][20] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
   int sum=0;
   for(i=0;i<m-1;i++)
   {
       sum = sum+month[i];
   }
   sum = sum+d;
   sum = sum%7;
   sum = sum+3;
   if(sum >6)
   {
        sum = fabs(7-sum);
   }
   printf("%s",day[sum]);
    return 0;
}
