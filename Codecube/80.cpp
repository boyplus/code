#include <stdio.h>
#include <string.h>
char str[100001];
char str_temp[100001];
int length;
bool check(int);
int main()
{
    for(int z=0; z<5; z++)
    {
        scanf("%s",&str);
        int i,j,k,n,m,count=0;
        length = strlen(str);
        for(j=0; j<=0; ++j)
            str_temp[j] = str[j];
        bool chk = check(1);
        if(chk)
        {
            int le = 1;
            for(j=le; j<=length; j+=le)
                if(length%j==0)
                    count++;
            printf("%d\n",count);
            continue;
        }
        for(i=1; i<length; ++i)
        {
            if(length%(i+1)==0)
            {
                for(j=0; j<=i; ++j)
                    str_temp[j] = str[j];
                bool chk = check(i+1);
                if(chk)
                {
                    int le = i+1;
                    for(j=le; j<=length; j+=le)
                        if(length%j==0)
                            count++;
                    printf("%d\n",count);
                    break;
                }
            }
        }
    }
    return 0;
}
bool check(int length_temp)
{
    int round = (length/length_temp),num=0;
    if(length%length_temp!=0)
        round++;
    int count=0,i,start=0,temp_start=0;
    for(i=0; i<round; ++i)
    {
        temp_start = start;
        int nn = length_temp+temp_start;
        for(;start<nn; ++start)
        {
            if(str[start]!=str_temp[num])
                return false;
            num++;
            if(num>=length_temp)
                num = 0;
        }
    }
    return true;
}
