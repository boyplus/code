#include <stdio.h>
int main() {
    int num[4] = {0}, count = 0,i,j,k,l,ans=0;
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            for(k=0;k<=2;k++)
            {
                for(l=0;l<=2;l++)
                {
                    //printf("%d%d%d%d\n",i,j,k,l);
                    num[0]=i;
                    num[1]=j;
                    num[2]=k;
                    num[3]=l;
                    if(i==0)
                        count++;
                    if(j==0)
                        count++;
                    if(k==0)
                        count++;
                    if(l==0)
                        count++;
                    if(count==2)
                    {
                        printf("test = %d%d%d%d\n",i,j,k,l);
                        //ans++;

                    }
                    count=0;
                }
                count=0;
            }
            count=0;
        }
        count=0;
    }
    printf("count = %d\n",ans);
    return 0;
}


