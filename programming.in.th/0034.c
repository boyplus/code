#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c,d;
    int i=0,j=0,k=0,l=0;
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    for(i=0-A; i<=A; i++)
    {
        //printf("%d %d %d %d\n",i,j,k,l);
        for(j=0-C; j<=C; j++)
        {
            //printf("%d %d %d %d\n",i,j,k,l);
            for(k=0-A; k<=A; k++)
            {
                //printf("%d %d %d %d\n",i,j,k,l);
                for(l=0-C; l<=C; l++)
                {
                    //printf("%d %d %d %d\n",i,j,k,l);
                    if(A==i*k && C== j*l && B==(i*l)+(j*k))
                    {
                        printf("%d %d %d %d\n",i,j,k,l);
                        return 0;
                    }
                }
            }
        }
    }
    printf("No Solution\n");
    return 0;
}
