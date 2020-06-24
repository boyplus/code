#include <cstdio>
char str[2010][2010];
int main()
{
    int i,j,n;
    scanf("%d",&n);
    int round = 1,y = 1000,x = 1000,di = 1,w = 1,h=1;
    for(i=0; i<2000; ++i)
        for(j=0; j<2000; ++j)
            str[i][j] = '-';
    str[y][x] = 'A';
    char fre = 'B';
    while(round < n)
    {
        if(di == 1) //right
        {
            int now_w = h;
            int temp_1 = y+now_w,temp_2 = x+now_w;
            for(i=y; i<temp_1; ++i)
                for(j=x+1; j<=temp_2; ++j)
                    str[i][j] = fre;
            y = i-1;
            x = j-1;
            w = w + now_w;
        }
        else if(di == 2) //down
        {
            int now_w = w,temp_1 = y+now_w,temp_2 = x-now_w;
            for(i = y+1; i<=temp_1; ++i)
                for(j = x; j>temp_2; --j)
                    str[i][j] = fre;
            y = i-1;
            x = j+1;
            h = h + now_w;
        }
        else if(di == 3) //left
        {
            int now_w = h,temp_1 = y - now_w,temp_2 = x-now_w;
            for(i = y; i>temp_1; --i)
                for(j = x-1; j>=temp_2; --j)
                    str[i][j] = fre;
            y = i+1;
            x = j+1;
            w = w + now_w;
        }
        else if(di == 4) //up
        {
            int now_w = w,temp_1 = y - now_w,temp_2 = x+now_w;
            for(i = y-1; i>=temp_1; --i)
                for(j = x; j<temp_2; ++j)
                    str[i][j] = fre;
            y = i+1;
            x = j-1;
            h = h + now_w;
        }
        ++di;
        if(di > 4)
            di = 1;
        ++fre;
        ++round;
    }
    for(int i=0; i<2000; ++i)
    {
        bool chk = false;
        for(int j=0; j<2000; ++j)
        {
            if(str[i][j]!= '-')
            {
                printf("%c",str[i][j]);
                chk = true;
            }
        }
        if(chk)
            printf("\n");
    }
    return 0;
}
