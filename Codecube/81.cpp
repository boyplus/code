#include <cstdio>
#include <math.h>
bool chk(long long);
int main()
{
    FILE *f1 = fopen("test.txt","w");
    int i,j,count=0,num=0;
    while(count <=500)
    {
        bool l =chk(num);
        if(l)
        {
            count++;
            fprintf(f1,"%d,",num);
            printf("%d\n",num);
        }
        num++;
    }

    return 0;
}
bool chk(long long num)
{
    int temp = num,count=0,i,j;
    while(temp >= 1)
    {
        count++;
        temp = temp/10;
    }
    int digit[1000] = {0},max1=1;
    for(int i=0; i<count; i++)
        max1 = max1*10;
    int max2 = max1/10;
    for(int i=0; i<count; i++)
    {
        digit[i] = (num%max1)/max2;
        max1/=10;
        max2/=10;
    }
    for(i=0; i<count; i++)
        if(digit[i]!= 0 && digit[i] != 1 && digit[i] != 6 && digit[i]!=8 && digit[i]!= 9)
            return false;
    if(count %2 ==1)
        if(digit[count/2] ==6 || digit[count/2] == 9)
            return false;
    int po = count-1,t = count/2;
    for(i=0; i<t; i++)
    {
        if(digit[i] !=6 && digit[i]!=9)
        {
            if(digit[i] != digit[po])
                return false;
        }
        else
        {
            if(digit[i] == 6)
            {
                if(digit[po] != 9)
                    return false;
            }
            else if(digit[i] == 9)
            {
                if(digit[po] != 6)
                    return false;
            }

        }
        po--;
    }
    return true;
}
