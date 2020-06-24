#include <stdio.h>
int main()
{
    int i,j,k,n,m,all,start=0,temp=0;
    scanf("%d",&all);
    for(i=0; i<all; i++)
    {
        scanf("%d %d",&m,&n);
        if(m>=n)
        {
            start = n;
            //printf("Case #%d: %d\n",i+1,(n/20)+1);
        }
        else
        {
            printf("in if1\n");
            start = m;
            if((n-m)%20!=0)
            {
                printf("in if2\n");
                if(m%20!=0)
                {
                    printf("in if m\n");
                    temp = m%20;
                    start = start - temp;
                }
                if(n%20!=0)
                {
                    printf("in if n\n");
                    temp = n%20;
                    start = start-(20-temp);
                }
                printf("start = %d\n",start);
            }
        }
        printf("Case #%d: %d\n",i+1,(start/20)+1);
    }
    return 0;
}
