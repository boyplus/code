#include <stdio.h>
int gcd(int,int);
int main()
{
    int n1,n2,i,j;
    scanf("%d %d",&n1,&n2);
    int great = gcd(n1,n2);
    //printf("%d",great);
    for(i=1; i<=great; ++i)
    {
        if(n1%i==0 && n2%i==0)
            printf("%d %d %d\n",i,n1/i,n2/i);
    }
    return 0;
}
int gcd(int n1,int n2)
{
    if(n2!=0)
        return gcd(n2,n1%n2);
    return n1;
}
