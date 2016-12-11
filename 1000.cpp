#include <stdio.h>
#include <string.h>
char string_1[1001]="";
char temp[1001] = "";
int main()
{
    int length,n,i,j;
    scanf("%d %d",&length,&n);
    scanf(" %s",string_1);
    if(n==1)
    {
        printf("%s\n",string_1);
        return 0;
    }
    int dif=0;
    strcpy(temp,string_1);
    for(i=0; i<n-1; ++i)
    {
        scanf(" %s",string_1);
        for(j=0; j<length; ++j)
        {
            if(string_1[j]!=temp[j])
            {
                ++dif;
                if(dif > 2)
                {
                    printf("%s",temp);
                    return 0;
                }
            }
        }
        dif=0;
        strcpy(temp,string_1);
    }
    printf("%s",string_1);
    return 0;
}
