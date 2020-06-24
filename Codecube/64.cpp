#include <cstdio>
#include <string.h>
#include <math.h>
long long a[50],b[50];
char str[100000];
unsigned long long GCD(unsigned long long,unsigned long long);
unsigned long long LCM(unsigned long long,unsigned long long);
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(int x=0; x<n; x++)
    {
        scanf("%s",&str);
        unsigned long long length = strlen(str),index=0,count_a=0,count_b=0;
        char str_a[100000] = "";
        char str_b[100000] = "";
        while(str[index] != '/')
        {
            str_a[index] = str[index];
            count_a++;
            index++;
        }
        index++;
        for(i=index; i<length; i++)
        {
            str_b[count_b] = str[i];
            count_b++;
        }
        unsigned long long pow_a = 1,pow_b = 1;
        for(i = count_a-1; i>=0; i--)
        {
            a[x] = a[x] + ((str_a[i]-48)*pow_a);
            pow_a = pow_a*10;
        }
        for(i=count_b-1; i>=0; i--)
        {
            b[x] = b[x] + ((str_b[i]-48)*pow_b);
            pow_b = pow_b*10;
        }
    }
    for(i=0;i<n;i++)
    {
        long long gcd2 = GCD(a[i],b[i]);
        if(gcd2 !=0)
        {
            a[i]/=gcd2;
            b[i]/=gcd2;
        }
    }
    unsigned long long lcm = 1,prev1 = b[0],sum = 0;
    for(i=1; i<n; i++)
    {
        lcm = LCM(prev1,b[i]);
        prev1 = lcm;
    }
    for(i=0; i<n; i++)
        sum = sum + (a[i]*lcm/b[i]);
    if(n==1)
    {
        lcm = b[0];
        sum = a[0];
    }
    unsigned long long result = (float(sum)/float(lcm));
    float tp = (float(sum)/float(lcm));
    if(result != tp)
        result++;
    printf("%llu\n",result);
    unsigned long long temp = result * lcm;
    temp = temp - sum;
    unsigned long long gcd = GCD(temp,lcm);
    if(temp!=0)
        printf("%llu/%llu\n",temp/gcd,lcm/gcd);
    else
        printf("0\n");
    
    return 0;
}
unsigned long long GCD(unsigned long long n1,unsigned long long n2)
{
    if(n2!=0)
        return GCD(n2,n1%n2);
    return n1;
}
unsigned long long LCM(unsigned long long n1,unsigned long long n2)
{
    long long my_gcd = GCD(n1,n2);
    long long my_lcm = (n1*n2)/my_gcd;
    return my_lcm;
}
