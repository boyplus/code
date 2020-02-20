#include<stdio.h>
int main()
{
   int i,j,k,n,m;
   scanf("%d",&n);
   scanf("%d",&m);
   int num_not[m];
   int chk=0;
   for(i=0;i<m;i++)
   {
       scanf("%d",&num_not[i]);
   }
   int num[n];
   for(i=0;i<n;i++)
   {
       num[i] = i+1;
       printf("%d ",num[i]);
   }
    for(i=0;i<n;i++)
    {

    }
    return 0;
}
