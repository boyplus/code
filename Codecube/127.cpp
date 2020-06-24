#include <cstdio>
int main()
{
    int n,x,i,j;
    scanf("%d %d",&n,&x);
    bool chk = false;
    if(x==1)
    {
        if(n==2)
        {
            printf("2-1");
            chk = true;
        }
        else if(n==3)
        {
            printf("3-2*1");
            chk = true;
        }
        else if(n==4)
        {
            printf("2+3-4*1");
            chk = true;
        }
        else
        {
            printf("5-4+2-3");
            for(i=6; i<=n; i++)
                if(i!=x)
                    printf("*%d",i);
            printf("+1");
            chk = true;
        }
    }
    else if(x==2)
    {
        if(n==2)
        {
            printf("1*2");
            chk = true;
        }
        else if(n==3)
        {
            printf("3-2+1");
            chk = true;
        }
        else
        {
            printf("4-3-1");
            for(i=5; i<=n; i++)
                if(i!=x)
                    printf("*%d",i);
            printf("+2");
            chk = true;
        }
    }
    else if(x==3)
    {
        if(n==3)
        {
            printf("2-1*3");
            chk = true;
        }
        else if(n==4)
        {
            printf("4-2-1*3");
            chk = true;
        }
        else
        {
            printf("5+1-4-2");
            for(i=6; i<=n; i++)
                if(i!=x)
                    printf("*%d",i);
            printf("+3");
            chk = true;
        }
    }
    else
    {
        printf("3-2-1");
        for(i=4; i<=n; i++)
            if(i!=x)
                printf("*%d",i);
        printf("+%d",x);
        chk = true;
    }
    if(!chk)
        printf("IMPOSSIBLE");
    return 0;
}
