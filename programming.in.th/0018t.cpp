#include <stdio.h>
int num_2[500]={0};
int main()
{
    int i,j,k,n;
    scanf("%d %d",&n,&k);
    int num[n-1];
    for(i=0;i<n-1;i++)
    {
        num[i] = i+2;
        //printf("%d ",num[i]);
    }
    printf("\n");
    bool chk=false;
    int count=0;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(num[j]%num[i] == 0)
            {
                if(chk == false)
                {
                    printf("%d ",num[j]);
                }
                chk = false;
            }
        }
    }
    printf("\n");
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            //printf("%d %d\n",i,j);
            if(num[i] == num[j])
            {
                //printf("%d = %d\n",num[i],num[j]);
            }
        }
    }
    printf("\n");
    for(i=0;i<n-1;i++)
    {
        if(num[i]!=-1);
            //printf("%d ",num[i]);
    }
    return 0;
}
