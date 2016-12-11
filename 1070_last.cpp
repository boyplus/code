#include <stdio.h>
using namespace std;
int main()
{
    int i,n,min_1=100001,min_2=100001,num,max=-1;
    scanf("%d",&n);
    for(i=0; i<n; ++i)
    {
        scanf("%d",&num);
        if(num < min_1)
            min_1 = num;
        else if(num < min_2)
            min_2 = num;
        if(num > max)
            max = num;
    }
    if(min_1+min_2 <= max)
        printf("yes");
    else
        printf("no");
    return 0;
}
