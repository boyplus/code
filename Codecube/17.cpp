#include <stdio.h>
int main()
{
    int i,j,k,n,m,count=0,count_2=0;
    scanf("%d %d",&n,&m);
    char str_1[n+1],str_2[m+1];
    scanf("%s",&str_1);
    scanf("%s",&str_2);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(str_1[i+j] == str_2[j])
            {
                count++;
            }
        }
        if(count == m)
        {
            count_2++;
        }
        count=0;
    }
    printf("%d\n",count_2);
    return 0;
}
