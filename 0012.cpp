#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char msg[20];
    scanf("%s",msg);
    int i,j,k,n;
    int length = strlen(msg);
    int count=0;
    for(i=0;i<5;i++)
    {
        if(i==0||i==4)
        {
            if(i==4)
            {
                printf("\n");
            }
            for(j=0;j<length;j++)
            {
                printf("..");
                if((j+1)%3==0&&j>=2)
                {
                    printf("*");
                }
                else
                {
                    printf("#");
                }
                if(j!=length-1)
                {
                    printf(".");
                }
                else
                    printf("..");
            }
        }
        else if(i==1||i==3)
        {
            printf("\n");
            for(j=1;j<=length*2;j++)
            {
                printf(".");
                if((((j/2)%3==0)||(((j+1)/2)%3==0))&&j>=3&&j%7!=0&&j%13!=0&&j%19!=0&&j%25!=0)
                {
                    printf("*");
                }
                else
                {
                    printf("#");
                }
            }
            printf(".");
        }
        else if(i==2)
        {
            printf("\n");
            for(j=1;j<=length*2;j++)
            {
                if(j%2==0)
                {
                    printf("%c.",msg[count]);
                    count++;
                }
                else if((((j/2)%3==0)||(((j+1)/2)%3==0))&&j>=3)
                {
                    printf("*.");
                }
                else
                {
                    printf("#.");
                }
            }
            if((j-1)%3==0)
            {
                printf("*");
            }
            else
            {
                printf("#");
            }
        }
    }
    return 0;
}
