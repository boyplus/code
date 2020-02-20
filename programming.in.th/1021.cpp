#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;
int main()
{
    priority_queue<int> queue;
    int i,j,k,n;
    scanf("%d",&n);
    int num[n];
    int count=0;
    int have=0;
    char command;
    for(i=0; i<n;++i)
    {
        scanf(" %c",&command);
        if(command == 'P')
        {
            scanf("%d",&num[count]);
            queue.push(num[count]);
            ++count;
            ++have;
        }
        else if(command == 'Q')
        {
            if(have <=0)
            {
                printf("-1\n");
                have=0;
            }
            else if(have > 0)
            {
                printf("%d\n",queue.top());
                queue.pop();
                --have;
            }
        }
    }
    return 0;
}
