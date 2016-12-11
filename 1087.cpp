#include <cstdio>
using namespace std;
int m,n,k;
int get_sum(int,int);
int num[301][301];
int sum_row_even[301][301];
int main()
{
    int i,j,max=-1;
    scanf("%d %d",&m,&n,&k);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&num[i][j]);
            int my_sum = get_sum(i,j);
            if(my_sum>max)
                max = my_sum;
        }
    }
    return 0;
}
int get_sum(int i,int j)
{
    int sum=0;
    int start_left = j-k;
    int end_left = j+k;
    int start_up = i-k;
    int end_up = i+k;
    if(start_left<0)
        start_left =0;
    if(end_left >= n)
        end_left = n-1;
    if(start_up <0)
        start_up =0;
    if(end_up >=m)
        end_up = m-1;
    int count=0;
    //if()
    for(int x = start_left;x<=end_left;x++)
    {
        //sum = sum+()
    }
}
