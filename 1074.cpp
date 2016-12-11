#include <cstdio>
#include <math.h>
int land[102][102];
char str[102][102];
int main()
{
    int i,j,k,m,n,start_y1=0,start_x1=0,start_y2=0,start_x2=0,size_1=0,size_2=0;
    scanf("%d %d",&m,&n);
    for(i=0; i<m; i++)
    {
        scanf("%s",&str[i]);
        for(j=0; j<n; j++)
        {
            if(str[i][j] == '.')
                land[i][j] = 1;
            else
                land[i][j] = 2;
        }
    }
    bool chk = false,chk_inter = false,chk_2=false,chk_3=false;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(land[i][j] == 2)
            {
                start_y1 = i;
                start_x1 = j;
                int temp_x = j,temp_y = i,count_right = 0,count_down = 0;
                while(land[i][temp_x] == 2)
                {
                    temp_x++;
                    count_right++;
                }
                while(land[temp_y][j] == 2)
                {
                    temp_y++;
                    count_down++;
                }
                if(count_right < count_down)
                    size_1 = count_right;
                else
                    size_1 = count_down;
                for(int y = i; y < i+size_1; y++)
                    for(int x = j; x<j+size_1; x++)
                        land[y][x] = 3;
                chk = true;
                break;
            }
        }
        if(chk)
            break;
    }
    printf("%d %d %d\n",start_y1+1,start_x1+1,size_1);
    int count_two=0;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            if(land[i][j] == 2)
                count_two++;
    if(count_two == 0)
    {
        printf("%d %d %d\n",start_y1+1,start_x1+1,size_1);
        return 0;
    }
    float num_float = sqrt(count_two);
    int num_int = num_float;
    if(num_float != num_int)
        chk_inter = true;
    if(chk_inter)
    {
        int last_y=0,last_x=0;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(land[i][j] == 2)
                {
                    last_y = i;
                    last_x = j;
                }
            }
        }
        int count_left=0,count_up=0,ans_last=0;
        int temp_last_x = last_x,temp_last_y = last_y;
        while(land[last_y][temp_last_x] == 2)
        {
            temp_last_x--;
            count_left++;
        }
        while(land[temp_last_y][last_x] == 2)
        {
            temp_last_y--;
            count_up++;
        }
        if(count_left > count_up)
            ans_last = count_left;
        else
            ans_last = count_up;
        start_y2 = last_y - ans_last + 1;
        if(start_y2 < 0)
            start_y2 = 0;
        start_x2 = last_x - ans_last + 1;
        if(start_x2 < 0)
            start_x2 = 0;
        size_2 = ans_last;
    }
    else
    {
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(land[i][j] == 2)
                {
                    int temp_j_2 = j;
                    while(land[i][temp_j_2] == 2)
                    {
                        temp_j_2++;
                        size_2++;
                    }
                    start_y2 = i;
                    start_x2 = j;
                    chk_2 = true;
                    break;
                }
            }
            if(chk_2)
                break;
        }
    }
    printf("%d %d %d\n",start_y2+1,start_x2+1,size_2);
    return 0;
}
