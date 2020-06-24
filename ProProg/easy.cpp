#include <cstdio>
int num[10001];
int my_abs(int a)
{
    if(a < 0)
        return a*-1;
    return a;
}
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        if(num[i] < 0){
            printf("Not Easy\n");
            return 0;
        }
    }
    int start = num[0]-num[1];
    if(start < 0)
        start = start*-1;
    for(i=2;i<n;i++)
    {
        int temp = num[i]-num[i-1];
        if(temp < 0)
            temp = temp*-1;
        if(temp != start)
        {
            printf("Not Easy\n");
            return 0;
        }
    }
    printf("Easy\n");
    return 0;
}