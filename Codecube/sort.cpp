#include <cstdio>
int num[200010],ch[200010];
int main()
{
    int i,n,count=0;
    scanf("%d",&n);
    for(i=0;i<n;++i)
        scanf("%d",&num[i]);
    for(i=0;i<n;++i)
        scanf("%d",&ch[i]);
    for(int j=0;j<n;++j)
        if(num[count] == ch[j])
            ++count;
    printf("%d",n-count);
    return 0;
}
