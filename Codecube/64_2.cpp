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
    long long sum=0,lcm = 1;
    for(i=0; i<n; i++)
    {
        sum = sum + (a[i]/b[i]);
        a[i]%=b[i];
        if(a[i]!=0)
        {
            long long gcd = GCD(a[i],b[i]);
            a[i]/=gcd;
            b[i]/=gcd;
            lcm = LCM(lcm,b[i]);
        }
    }
    long long s2=0;
    for(i=0; i<n; i++)
    {
        s2 = s2 + (a[i]*(lcm/b[i]));
    }
    printf("s2 = %lld\n",s2);
    long long s3 = ceil(float(s2)/lcm);
    sum = sum +s3;
    printf("%lld %lld\n",sum,lcm);
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
