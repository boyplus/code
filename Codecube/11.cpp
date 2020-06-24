#include <cstdio>
int num[1010][1010];
int count_empty[1010];
int main()
{
    int i,j,m,n,k,fre=0;
    scanf("%d %d %d",&m,&n,&k);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&num[i][j]);
            if(num[i][j] == 0)
                count_empty[i]++;
        }
    }
    for(i=m-1;i>=0;i--)
    {
        if(fre+count_empty[i] >=k)
        {
            //check
            //base case
            int count_zero = 0,count_one = 0;
            int left = num[i][0];
            for(j=0;j<k;j++)
            {
                if(num[i][j])
                    count_one++;
                else
                    count_zero++;
            }
            if(count_one<=fre)
            {
                printf("%d\n",i+1);
                return 0;
            }
            for(j=k;j<n;j++)
            {
                if(num[i][j])
                    count_one++;
                else
                    count_zero++;
                if(left)
                    count_one--;
                else
                    count_zero--;
                if(count_one<=fre)
                {
                    printf("%d\n",i+1);
                    return 0;
                }
                left = num[i][j-k+1];
            }
            
        }
        fre = fre + count_empty[i];
    }
    return 0;
}
