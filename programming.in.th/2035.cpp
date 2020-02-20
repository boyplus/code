#include <cstdio>
#include <math.h>
using namespace std;
int cost[110],weight[2010],q[4040],park[110],n,m;
bool chk_out[110];
void print();
int main()
{
    long long ans=0;
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=0; i<n; ++i)
        scanf("%d",&cost[i]);
    for(i=0; i<m; ++i)
        scanf("%d",&weight[i]);
    int temp = m*2;
    for(i=0; i<temp; ++i)
        scanf("%d",&q[i]);
    for(i=0; i<temp; ++i)
    {
        int choose_park = 0;
        bool chk_park = false;
        if(q[i] > 0)
        {
            for(j=0; j<n; ++j)
            {
                if(park[j] == 0)
                {
                    choose_park = j;
                    chk_park = true;
                    break;
                }
            }
            if(chk_park)
            {
                park[choose_park] = q[i];
                ans = ans +(weight[q[i]-1] * cost[choose_park]);
            }
            else
            {
                int temp_i = i;
                int num = fabs(q[temp_i]);
                while(q[temp_i] > 0 || chk_out[num])
                {
                    ++temp_i;
                    num = fabs(q[temp_i]);
                }
                int temp_q = -1*q[temp_i];
                for(j=0; j<n; ++j)
                {
                    if(park[j] == temp_q)
                    {
                        chk_out[temp_q] = true;
                        park[j] = 0;
                        choose_park = j;
                        break;
                    }
                }
                park[choose_park] = q[i];
                ans = ans +(weight[q[i]-1] * cost[choose_park]);
            }
        }
        else
        {
            int temp_q = -1*q[i];
            for(j=0; j<n; ++j)
            {
                if(park[j] == temp_q)
                {
                    chk_out[temp_q] = true;
                    park[j] = 0;
                    break;
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
