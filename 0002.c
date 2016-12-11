#include<stdio.h>
int main()
{
    unsigned int a,i;
    scanf("%d",&a);
    int b[a];
    for(i=0;i<a;i++)
        scanf("%d",&b[i]);
    int min = b[0];
    int max = b[0];
    for(i=0;i<a;i++)
    {
        if(b[i] >= max)
            max = b[i];
        if(b[i] <= min)
            min = b[i];
    }
    printf("%d\n%d",min,max);
    return 0;
}
