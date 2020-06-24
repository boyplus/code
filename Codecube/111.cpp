#include <stdio.h>
int main()
{
    int num[3],i;
    scanf("%d %d %d",&num[0],&num[1],&num[2]);
    if(num[0]+num[1]+num[2] != 100)
    {
        printf("BUG");
        return 0;
    }
    int max = -1,ans=0;
    for(i=0;i<3;i++)
    {
        if(num[i] > max)
        {
            max=  num[i];
            ans = i;
        }
    }
    if(num[0] == num[1]&&max==num[0])
    {
        printf("I DON'T KNOW");
        return 0;
    }
    if(num[0]==num[2]&&max==num[0])
    {
        printf("I DON'T KNOW");
        return 0;
    }
    if(num[1] == num[2] && max == num[1])
    {
        printf("I DON'T KNOW");
        return 0;
    }
    if(ans == 0)
    {
        printf("PAPER");
    }
    else if(ans==1)
    {
        printf("SCISSORS");
    }
    else if(ans==2)
    {
        printf("ROCK");
    }
    return 0;
}
