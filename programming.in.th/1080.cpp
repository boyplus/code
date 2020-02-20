#include <cstdio>
#include <stdlib.h>
#include <math.h>
int compare(const void* a,const void* b)
{
    return (*(int *)a-*(int *)b);
}
using namespace std;
int num[30000];
int main()
{
    int i,j,k,n,m,count=0;
    scanf("%d",&n);
    for(i=0; i<n; ++i)
        scanf("%d",&num[i]);
    qsort(num,n,sizeof(int),compare);
    if(n<3)
    {
        printf("%d\n",n);
        return 0;
    }
    int max = num[n-1],count_po=n-1,max_ans=-1;
    int t_n = sqrt(n);
    for(i=0; i<t_n; ++i)
    {
        count=0;
        max = num[count_po];
        int t=n-1;
        for(j=0; j<t; ++j)
            if(num[j]+num[j+1]<=max)
                ++count;
        int my_num = count_po-count;
        if(my_num > max_ans)
            max_ans = my_num;
        --count_po;
    }
    printf("%d\n",max_ans+1);
    return 0;
}
