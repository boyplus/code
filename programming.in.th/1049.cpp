#include <cstdio>
int count[100002],loo[100002],max[100002],ans[100002];
int main()
{
    int i,j,k,m,n,a,l,s,max_round=-1;
    scanf("%d %d",&n,&m);
    for(i=0; i<n; ++i)
    {
        scanf("%d %d %d",&a,&l,&s);
        ++count[l];
        int round = count[l];
        if(round > max_round)
            max_round = round;
        if(s > max[round])
        {
            max[round] = s;
            loo[round] = l;
            ans[round] = a;
        }
        else if(s == max[round])
        {
            if(l < loo[round])
            {
                loo[round] = l;
                ans[round] = a;
            }
        }
    }
    for(i=1; i<=max_round; ++i)
        printf("%d\n",ans[i]);
    return 0;
}
