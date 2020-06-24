#include <cstdio>
#include <vector>
using namespace std;
vector<int> num[30010];
int my_size[30010];
int c[30010];
int main()
{
    int i,j,k,m,n,a,b,max=-1,count=0;
    scanf("%d %d",&n,&m);
    for(i=1; i<n; i++)
    {
        scanf("%d %d",&a,&b);
        num[a].push_back(b);
    }
    for(i=1; i<=n; i++)
    {
        my_size[i] = num[i].size();
        for(j=0; j<my_size[i]; j++)
            c[num[i].at(j)]++;
    }
    for(i=1; i<=n; i++)
    {
        if(c[i] + my_size[i] == 1)
        {
            count++;
            for(j=i+1;j<=n;j++)
            {
                if(my_size[j] == 0)
                {
                    my_size[j]++;
                    break;
                }
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
