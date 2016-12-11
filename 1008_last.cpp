#include<stdio.h>

#define MAX 255

int main()
{
    int a[MAX] = {0};
    int l, h, r;
    int n;
    int i, j;
    int max = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%d %d %d", &l, &h, &r);
        if(r > max)
        {
            max = r;
        }
        for(j = (l - 1); j < (r - 1); j ++)
        {
            if(a[j] < h)
            {
                a[j] = h;
            }
        }
    }
    for(i = 0; i < max; i ++)
    {
        if((a[i] != a[i - 1]) && (a[i] != 0))
        {
            printf("%d %d ", (i + 1), a[i]);
        }
        if((a[i + 1] == 0) && (a[i] != 0))
        {
            printf("%d %d ", (i + 2), 0);
        }
    }
    printf("\n");
    return 0;
}
