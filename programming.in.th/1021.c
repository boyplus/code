#include <stdio.h>
#include <string.h>
int num[300000]={0};
int main()
{
    int i=0,j=0,k=0,n;
    scanf("%d",&n);
    char string;
    int count=0;
    int temp=0;
    int max=0;
    for(i=0;i<n;i++)
    {
        scanf(" %c",&string);
        if(string == 'P')
        {
            scanf(" %d",&num[count]);
            count++;

        }
        if(string == 'Q')
        {
            
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(num[i] <= num[j])
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    for(i=0;i<count;i++)
    {
        printf("%d ",num[i]);
    }
    printf("count = %d\n");
    return 0;
}
