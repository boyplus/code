#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue <int> queue;
    int i,j,k,n;
    scanf("%d %d",&n,&k);
    int num[n];
    int max = -999999;
    int time=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        queue.push(num[i]);
    }
    for(i=0;i<n;i++)
    {
        num[i] = queue.top();
        queue.pop();
    }
    for(i=0;i<n;i+=k)
        time = time+num[i];
    printf("%d",time);
    return 0;
}
