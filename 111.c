#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
int main()
{
    int a,b,c,d,input[3],i,max=0,check=0;
    scanf("%d %d %d",&input[0],&input[1],&input[2]);
    int front,back,j,f2,b2;
    for(i=1; (i<=input[0])&&(check==0); i++)
    {
        if(input[0]%i==0)
        {
            front=i;
            back=input[0]/i;
            if(front<=back)
            {
                for(j=-(int)fabs(input[2]); (j<=(int)fabs(input[2]))&&(check==0); j++)
                {
                    if(j!=0&&input[2]%j==0)
                    {
                        f2=j;
                        b2=input[2]/j;
                        if(f2<=b2)
                        {
                            if((b2*front)+(f2*back)==input[1])
                            {
                                printf("%d %d %d %d",front,f2,back,b2);
                                check=1;
                                break;
                            }
                            if((f2*front)+(b2*back)==input[1])
                            {
                                printf("%d %d %d %d",front,b2,back,f2);
                                check=1;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if(check==0)
        printf("No Solution");
    return 0;
}
