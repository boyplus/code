#include <stdio.h>
#include <string.h>
#include <math.h>
char str[10000001] = "";
int main()
{
    gets(str);
    int i,j,k;
    int sum3=0;
    int length = strlen(str);
    for(i=0;i<length;i++)
    {
        sum3 = sum3+str[i]-48;
    }
    int temp = sum3;
    int sum3_new =0;
    int sum11_odd=0,sum11_even=0;
    if(length>=1)
    {
        for(j=1;j<length;j+=2)
        {
            sum11_even = sum11_even+str[j]-48;
        }
    }
    for(i=0;i<length;i+=2)
    {
        sum11_odd = sum11_odd+str[i]-48;
    }
    int sum = fabs(sum11_even-sum11_odd);
    printf("%d ",sum3%3);
    if(length >=3)
    {
        printf("%d",sum%11);
    }
    else
    {
        int num=0;
        for(i=0;i<length;i++)
        {
            num = num*10 +(str[i] - '0');
        }
        printf("%d",num%11);
    }
    return 0;
}
