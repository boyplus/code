#include <stdio.h>
bool magnet[100000001];
int main()
{
    int i,j,k,m,n,q,start,num;
    scanf("%d %d %d",&n,&m,&q);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&start,&num);
        magnet[start] = !magnet[start];
        int end = start+num;
        magnet[end+1] = !magnet[start];
    }
    bool now = true;
    for(i=0;i<m;i++)
    {
        magnet[i] = magnet[i]&&now;
    }
    return 0;
}
