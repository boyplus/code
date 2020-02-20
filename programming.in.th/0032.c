#include<stdio.h>
int main()
{
    int a,i,j;
    scanf("%d",&a);
    int temp;
    for(i=0;i<a;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<10;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(b[i] >= b[j])
            {
                temp = b[j];
                b[j] = b[i];
                b[i] = temp;
            }
        }
    }
    for(i=0;i<a;i++)
        printf("%d",b[i]);
    return 0;
}
