#include <stdio.h>
int main()
{
    int N,loop,space;
    scanf("%d",&N);
    for(loop=1; loop<=N; loop++)
    {
        for(space=N; space<=N/2; space--)
        {
        printf("-");
        }
        printf("\n");
    }
}
