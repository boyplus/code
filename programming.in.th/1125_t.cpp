#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec_x,vec_y;
int main()
{
    long long ans=0;
    int i,n,j,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        vec_x.push_back(x);
        vec_y.push_back(y);
    }
    sort(vec_x.begin(),vec_x.end());
    sort(vec_y.begin(),vec_y.end());
    for(i=0;i<n;i++)
        ans = ans+(vec_x[i]+vec_y[i])*(2*i-n+1);
    printf("%lld\n",ans);
    return 0;
}
