#include <cstdio>
char ans[1000000];
int max_win = 0,max_lose = 0;
void fill(int,int);
int main()
{
    int i,j,k1,k2,n,m;
    scanf("%d %d %d",&n,&k1,&k2);
    max_win = n-k1;
    max_lose = n-k2;
    fill(0,0);
    return 0;
}
void fill(int w,int l)
{
    if(w == max_win || l == max_lose)
    {
        int num = w+l;
        for(int j=0;j<num;++j)
            printf("%c ",ans[j]);
        printf("\n");
    }
    else
    {
        ans[w+l] = 'W';
        fill(w+1,l);
        ans[w+l] = 'L';
        fill(w,l+1);
    }
}
