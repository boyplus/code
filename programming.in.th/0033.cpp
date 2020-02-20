#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;
int main()
{
    priority_queue<int> queue;
    int n,i,j,k;
    scanf("%d",&n);
    int num[n];
    for(i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
        queue.push(num[i]);
    }
    int num_2[n];
    j = n-1;
    for(i=0; i<n; i++)
    {
        num_2[j] = queue.top();
        queue.pop();
        j--;
    }
    int sum[n];
    for(i=0; i<n; i++)
        sum[i] =0;
    for(i=0; i<n; i++)
        for(j=i+1;j<n;j++)
            if(num_2[i] == num_2[j])
                sum[i]++;
    int max = sum[0];
    for(i=0;i<n;i++)
        if(sum[i] >= max)
            max = sum[i];
    for(i=0;i<n;i++)
        if(sum[i] >= max)
            printf("%d ",num_2[i]);
    return 0;
}
