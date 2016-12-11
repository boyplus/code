#include <cstdio>
int num[1001][1001];
int sum_row[1001][1001];
int qsum[1001][1001];
using namespace std;
int main()
{
    int i,j,k,n,m,y,x,max_y=-1,max_x=-1;
    scanf("%d %d",&n,&m);
    for(i=0; i<n; ++i)
    {
        scanf("%d %d",&y,&x);
        ++num[y][x];
        if(y > max_y)
            max_y = y;
        if(x > max_x)
            max_x = x;
    }
    for(i=0; i<=max_y; ++i)
        sum_row[i][0] = num[i][0];
    for(i=0; i<=max_y; ++i)
        for(j=1; j<=max_x; ++j)
            sum_row[i][j]= sum_row[i][j-1] + num[i][j];
    for(i=0; i<=max_x; ++i)
        qsum[0][i] = sum_row[0][i];
    for(i=0; i<=max_x; ++i)
        for(j=1; j<=max_y; ++j)
            qsum[j][i] = qsum[j-1][i] + sum_row[j][i];
    for(i=0; i<m; ++i)
    {
        scanf("%d %d %d",&y,&x,&k);
        int mark_plus_y = y + k;
        int mark_plus_x = x + k;
        int mark_minus_left_y = y + k;
        int mark_minus_left_x = x - k - 1;
        int mark_minus_up_y = y - k - 1;
        int mark_minus_up_x = x + k;
        int mark_inter_y = y - k - 1;
        int mark_inter_x = x - k - 1;
        int sum_minus_left = 0;
        int sum_minus_up = 0;
        int sum_inter = 0;
        if(mark_plus_y > max_y)
            mark_plus_y = max_y;
        if(mark_plus_x > max_x)
            mark_plus_x = max_x;
        int sum_plus = qsum[mark_plus_y][mark_plus_x];
        if(mark_minus_left_y > max_y)
            mark_minus_left_y = max_y;
        if(mark_minus_left_x < 0)
            sum_minus_left = 0;
        else
            sum_minus_left = qsum[mark_minus_left_y][mark_minus_left_x];
        if(mark_minus_up_x > max_x)
            mark_minus_up_x = max_x;
        if(mark_minus_up_y < 0)
            sum_minus_up = 0;
        else
            sum_minus_up = qsum[mark_minus_up_y][mark_minus_up_x];
        if(mark_inter_y < 0)
            sum_inter =0;
        if(mark_inter_x < 0)
            sum_inter =0;
        if(mark_inter_y>=0 && mark_inter_x>=0)
            sum_inter = qsum[mark_inter_y][mark_inter_x];
        printf("%d\n",sum_plus-sum_minus_left-sum_minus_up+sum_inter);
    }
    return 0;
}
