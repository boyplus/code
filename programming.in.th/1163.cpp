#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int i,n,j,checki=1,round,k;
    char str[60],str2[60];
    scanf("%d",&n);
    round=pow(2,n);
    str[n]=0;
    for(i=0; i<round; ++i)
    {
        checki=1;
        for(k=0; k<n; ++k)
        {
            if((i&checki)==checki)
                str[n-k-1]='1';
            else
                str[n-k-1]='0';
            checki<<=1;
        }
        strcpy(str2,str);
        for(j=n; j>=0; --j)
        {
            if(str[j]=='0')
            {
                str2[j]='1';
                printf("%s %s\n",str,str2);
                str2[j]='0';
            }
        }
    }
    return 0;
}
