#include <cstdio>
#include <algorithm>
int num[1001];
using namespace std;
int main()
{
    int i,j,n,po=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    sort(num,num+n);
    while(num[0]==0)
    {
        int temp = num[po];
        num[0] = num[po];
        num[po] = 0;
        po++;
    }
    for(i=0;i<n;i++)
        printf("%d",num[i]);
    return  0;
}
