#include <cstdio>
#include <limits.h>
#include <string.h>
int cost[10];
char result[1000010] = "";
int main()
{
    int i,j,money,pay_now=0,index=0,min = INT_MAX,max_ans = -1;
    scanf("%d",&money);
    for(i=0; i<=9; ++i)
        scanf("%d",&cost[i]);
    bool have = false;
    for(i=1; i<=9; ++i)
        if(cost[i] <= money)
            have = true;
    if(have == false)
    {
        printf("-1");
        return 0;
    }
    for(i=1; i<=9; ++i)
    {
        char ans[1000010] = "";
        int choose = 0;
        index = 0;
        pay_now = 0;
        min = INT_MAX;
        ans[index++] = i+48;
        pay_now = pay_now + cost[i];
        for(j=0; j<=9; ++j)
        {
            if(cost[j] <= min)
            {
                min = cost[j];
                choose = j;
            }
        }
        while(pay_now < money)
        {
            ans[index] = choose+48;
            ++index;
            pay_now = pay_now + cost[choose];
        }
        while(pay_now > money)
        {
            ans[index-1] = '\0';
            --index;
            pay_now = pay_now - cost[choose];
        }
        for(j=1; j<index; ++j)
        {
            pay_now = pay_now - cost[ans[j]-48];
            int max = -1;
            for(int k=0; k<=9; ++k)
                if(k > max && pay_now+cost[k] <= money)
                    max = k;
            if(max != -1)
            {
                ans[j] = max+48;
                pay_now = pay_now + cost[max];
            }
        }
        if(index >= max_ans)
        {
            max_ans = index;
            strcpy(result,ans);
        }
    }
    printf("%s",result);
    return 0;
}
