#include<stdio.h>
int main()
{
    int a[4],i,k,temp;
    int fix[4] ={0};
    for(i=0;i<4;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<3;i++)
    {
        for(k=i+1;k<4;k++)
        {
            if(a[i] < a[k])
            {
                temp = a[i];
                a[i] = a[k];
                a[k] = temp;
            }
        }
    }
    fix[0] = a[0];
    fix[1] = a[3];
    fix[2] = a[1];
    fix[3] = a[2];
    int sum = fix[1] *fix[2];
    printf("%d",sum);
    return 0;
}
