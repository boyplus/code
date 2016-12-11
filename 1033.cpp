#include <stdio.h>
int table[100][100]={0};
bool check_walk[100][100] = {false};
void print_table(int);
int main()
{
    int i,j,k,n,m;
    scanf("%d %d",&n,&k);
    int num = 4*k;
    char str[4*k];
    for(i=0;i<num;i++)
        scanf(" %c",&str[i]);
    table[0][n-1] = 1;
    table[n-1][n-1] = 2;
    table[n-1][0] = 3;
    table[0][0] = 4;
    int now_r[4]={0,n-1,n-1,0};
    int now_c[4]={n-1,n-1,0,0};
    char walk[num];
    int count=0;
    int count_1=1;
    for(i=0;i<num;i++)
    {
        walk[i] = str[count];
        count+=k;
        if(count > k*4-1)
        {
            count = count_1;
            count_1++;
        }
    }
    int tar = 1;
    check_walk[0][n-1] = true;
    check_walk[n-1][n-1] = true;
    check_walk[n-1][0] = true;
    check_walk[0][0] = true;
    for(i=0;i<num;i++)
    {
        if(walk[i] == 'S' && check_walk[now_r[tar-1]+1][now_c[tar-1]] == false && now_r[tar-1] < n-1)
        {
            table[now_r[tar-1]+1][now_c[tar-1]] = tar;
            check_walk[now_r[tar-1]][now_c[tar-1]] = false;
            check_walk[now_r[tar-1]+1][now_c[tar-1]] = true;
            now_r[tar-1] = now_r[tar-1]+1;
        }
        if(walk[i] == 'W' && check_walk[now_r[tar-1]][now_c[tar-1]-1] == false && now_c[tar-1] >=1)
        {
            table[now_r[tar-1]][now_c[tar-1]-1] = tar;
            check_walk[now_r[tar-1]][now_c[tar-1]] = false;
            check_walk[now_r[tar-1]][now_c[tar-1]-1] = true;
            now_c[tar-1] = now_c[tar-1]-1;
        }
        if(walk[i] == 'N' && check_walk[now_r[tar-1]-1][now_c[tar-1]] == false && now_r[tar-1] >=1)
        {
            table[now_r[tar-1]-1][now_c[tar-1]] = tar;
            check_walk[now_r[tar-1]][now_c[tar-1]] = false;
            check_walk[now_r[tar-1]-1][now_c[tar-1]] = true;
            now_r[tar-1] = now_r[tar-1]-1;
        }
        if(walk[i] == 'E' && check_walk[now_r[tar-1]][now_c[tar-1]+1] == false && now_c[tar-1] < n-1)
        {
            table[now_r[tar-1]][now_c[tar-1]+1] = tar;
            check_walk[now_r[tar-1]][now_c[tar-1]] = false;
            check_walk[now_r[tar-1]][now_c[tar-1]+1] = true;
            now_c[tar-1] = now_c[tar-1]+1;
        }
        tar++;
        if(tar > 4)
            tar = 1;
    }
    int max = -9999999;
    int sum[4]={0,0,0,0};
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(table[i][j] == 0)
            {
                printf("No\n");
                return 0;
            }
            sum[table[i][j]-1]++;
        }
    }
    for(i=0;i<4;i++)
        if(sum[i] > max)
            max = sum[i];
    int count_win=0;
    for(i=0;i<4;i++)
        if(sum[i] == max)
            count_win++;
    printf("%d %d\n",count_win,max);
    for(i=0;i<4;i++)
        if(sum[i] == max)
            printf("%d\n",i+1);
    return 0;
}

