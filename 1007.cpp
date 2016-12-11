#include <stdio.h>
int main()
{
    int year_1=0,year=0,bee_work=1,bee_sol=0,bee_mom=1;
    int bee_work_young=0,bee_sol_young=0;
    while(1)
    {
        scanf("%d",&year_1);
        if(year_1 == -1)
        {
            break;
        }
        else
        {
            bee_sol_young=0;
            bee_work_young=0;
            bee_work=1;
            bee_sol=0;
            for(int i=0;i<year_1;i++)
            {
                bee_work_young = bee_sol+bee_work+bee_mom;
                bee_sol_young =bee_work;
                bee_sol = bee_sol_young;
                bee_work = bee_work_young;
            }
            printf("%d %d\n",bee_work,bee_work+1+bee_sol);
        }
    }
    return 0;
}
