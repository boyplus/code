#include <stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int side[N],i;
    for(i=0; i<=N-1; i++){
        scanf("%d",&side[i]);
    }
    int Plus1,Plus2,summary[N] [N];
    for(Plus1=0; Plus1<=N-1; Plus1++)
    {
        for(Plus2=0; Plus2<=N-1; Plus2++)
        {
            if(Plus1!=Plus2)
            {
                summary[Plus1] [Plus2]=side[Plus1]+side[Plus2];
            }
        }
    }
   int WTF;
    for(Plus1=0; Plus1<=N-1; Plus1++)
    {
        for(Plus2=0; Plus2<=N-1; Plus2++)
        {
                if(Plus1!=Plus2)
                {
                    for(WTF=1; WTF<=N-1; WTF++)
                    {
                        if(WTF!=Plus1 && WTF!=Plus2)
                        {
                            if(summary[Plus1] [Plus2] <  side[WTF])
                            {
                                printf("yes");
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        printf("no");
   }
