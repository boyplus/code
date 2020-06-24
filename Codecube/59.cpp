#include <stdio.h>
int main()
{
    int i,j,k,m,n,count=65;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%c",count);
            count++;
            if(count > 'Z')
                count = 65;
        }
        printf("\n");
    }
    return 0;
}
