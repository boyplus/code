#include <cstdio>
#include <vector>
using namespace std;
vector< pair<int,int> > num;
int main()
{
    int i,j,k,m,n,x,y,flip;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;++i)
    {
        scanf("%d %d",&x,&y);
        num.push_back(make_pair(x,y));
    }
    for(i=0;i<m;++i)
    {
        scanf("%d",&flip);
        for(j=0;j<n;++j)
        {
            if(num[j].first <= flip)
            {
                int temp = num[j].first;
                num[j].first = num[j].second;
                num[j].second = temp;
            }
        }
    }
    for(i=0;i<n;++i)
        printf("%d\n",num[i].first);
    return 0;
}
