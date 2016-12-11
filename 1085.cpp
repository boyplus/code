#include <cstdio>
#include <vector>
using namespace std;
bool power[500001]= {false};
vector<int> warp[500001];
bool link[500001]= {false};
int main()
{
    int i,j,k,n,m,a,b,rock;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0; i<m; ++i)
    {
        scanf("%d%d",&a,&b);
        warp[a].push_back(b);
    }
    for(i=0; i<k; ++i)
    {
        scanf("%d",&rock);
        link[rock] = true;
    }
    power[1] = true;
    for(i=1; i<n; ++i)
    {
        if(power[i])
        {
            if(!link[i])
                power[i+1] = true;
            int my_size = warp[i].size();
            for(j=0;j<my_size;j++)
                power[warp[i].at(j)] = true;
        }
    }
    for(i=n;i>=1;--i)
    {
        if(power[i])
        {
            if(i==n)
                printf("1\n");
            else
                printf("0 %d\n",i);
            return 0;
        }
    }
}
