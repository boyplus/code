#include <stdio.h>
#include <math.h>
int absolute(int);
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    int num_s[n],num_b[n];
    int sol = pow(2,n);
    int temp_2=0,temp[n],first=1,last=0,min_dif=999999;
    for(i=0;i<n;i++)
        temp[i]=0;
    for(i=0;i<n;i++)
        scanf("%d %d",&num_s[i],&num_b[i]);
    for(i=1;i<sol;i++)
    {
        temp_2 = i;
        for(j=0;j<n;j++)
        {
            temp[j] = temp_2%2;
            temp_2=temp_2/2;
        }
        for(j=0;j<n;j++)
        {
            if(temp[j] == 1)
            {
                first = first*num_s[j];
                last = last+num_b[j];
            }
        }
        int ans = absolute(first-last);
        if(ans < min_dif)
            min_dif = ans;
        first = 1;
        last =0;
    }
    printf("%d",min_dif);
    return 0;
}
int absolute(int num)
{
    if(num <0)
        return -num;
    else
        return num;
}
