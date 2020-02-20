//function แบบที่ 1
#include<stdio.h>
#include<string.h>
int main()
{
    unsigned short a[3];
    unsigned short i,j;
    unsigned short temp;
    char x[4];
    for(i=0;i<3;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<3;j++)
        {
            if(a[i]<=a[j])
            {
              temp = a[i];
              a[i] = a[j];
              a[j] = temp;
            }
        }
    }
    scanf("%s",&x);
    if(strcmp(x,"ABC") ==0)
        printf("%d %d %d",a[2],a[1],a[0]);
    else if(strcmp(x,"ACB") ==0)
        printf("%d %d %d",a[2],a[0],a[1]);
    else if(strcmp(x,"BAC") ==0)
        printf("%d %d %d",a[1],a[2],a[0]);
    else if(strcmp(x,"BCA") ==0)
        printf("%d %d %d",a[1],a[0],a[2]);
    else if(strcmp(x,"CAB") ==0)
        printf("%d %d %d",a[0],a[2],a[1]);
    else if(strcmp(x,"CBA") ==0)
        printf("%d %d %d",a[0],a[1],a[2]);
    return 0;
}
