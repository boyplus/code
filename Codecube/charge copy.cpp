#include <cstdio>
int num[1000000];
using namespace std;
int main()
{
    int i,j,n,k,sum=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        sum = sum + num[i];
    }
    int start = sum/n;
    printf("tets = %d\n",start);
    int ans1 = 0;
    while(true)
    {
        printf("start = %d\n",start);
        int count=0,energy = 0;
        bool chk = false;
        for(int i=0;i<n;i++)
        {
            if(energy < num[i])
            {
                energy = start;
                count++;
            }
            if(energy < num[i])
            {
                chk = true;
                break;
            }
            energy-=num[i];
        }
        if(count == k && chk == false)
        {
            printf("can use %d\n",start);
            break;
        }
        printf("count = %d\n",count);
        start++;
    }
    printf("start = %d\n",start);
    return 0;
}
