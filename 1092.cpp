#include <cstdio>
int n_solider[100001];
int num[100001];
int main()
{
    int i,j,k,n,m;
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
        scanf("%d",&n_solider[i]);
    for(i=1; i<=m; i++)
    {
        int vs1,vs2;
        scanf("%d %d",&vs1,&vs2);
        int choose_1 = vs1;
        int choose_2 = vs2;
        while(num[choose_1]!=0)
            choose_1 = num[choose_1];
        while(num[choose_2]!=0)
            choose_2 = num[choose_2];
        if(choose_1 == choose_2)
            printf("-1\n");
        else if(n_solider[choose_1] > n_solider[choose_2])
        {
            printf("%d\n",choose_1);
            n_solider[choose_1] = n_solider[choose_1] + (n_solider[choose_2]/2);
            num[choose_2] = choose_1;
        }
        else if(n_solider[choose_2] > n_solider[choose_1])
        {
            printf("%d\n",choose_2);
            n_solider[choose_2] = n_solider[choose_2] + (n_solider[choose_1]/2);
            num[choose_1] = choose_2;
        }
        else if(n_solider[choose_1] == n_solider[choose_2])
        {
            if(choose_1 < choose_2)
            {
                printf("%d\n",choose_1);
                n_solider[choose_1] = n_solider[choose_1] + (n_solider[choose_2]/2);
                num[choose_2] = choose_1;
            }
            else
            {
                printf("%d\n",choose_2);
                n_solider[choose_2] = n_solider[choose_2] + (n_solider[choose_1]/2);
                num[choose_1] = choose_2;
            }
        }
    }
    return 0;
}
