#include <stdio.h>
#include <math.h>
#include <conio.h>
int main()
{
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    int a,b,c,d;
    double num_a=sqrt(A);
    if((B*B)-(4*A*C) < 0)
    {
        printf("No Solution\n");
        return 0;
    }
    for(a=1; a<=num_a; ++a)
    {
        for(b=-1*fabs(B); b<=fabs(B); ++b)
        {
            for(c=1; c<=A; ++c)
            {
                for(d = -1*fabs(C); d<=fabs(C); ++d)
                {
                    if(A==(a*c) && B == ((a*d)+(b*c)) && C == (b*d))
                    {
                        printf("%d %d %d %d\n",a,b,c,d);
                        return 0;
                    }
                }
            }
        }
    }
    printf("No Solution\n");
    return 0;
}
