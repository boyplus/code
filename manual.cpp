#include <stdio.h>
#include <math.h>
long long num[12] = {5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828124,244140624};
int main()
{

    long long x,y,k;
    long long sum_all=0;
    scanf("%lld %lld %lld",&x,&y,&k);
    for(x=x;x<=y;x++)
    {
        long long sum=0;
        long long count=0,num_2;
        sum = (x/num[0])+(x/num[1])+(x/num[2])+(x/num[3])+(x/num[4])+(x/num[5])+(x/num[6])+(x/num[7])+(x/num[8])+(x/num[9])+(x/num[10])+(x/num[11]);
        printf("digit of %lld! = %lld\n",x,sum);
        sum_all = sum_all+sum;
    }
    printf("sum_all = %lld\n",sum_all);
    sum_all = sum_all%k;
    printf("%lld\n",sum_all);
    return 0;
}
