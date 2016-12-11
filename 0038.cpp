#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    char string[n][31];
    for(i=0;i<n;i++)
    {
        scanf("%s",string[i]);
    }
    char temp[31]="";
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(string[i],string[j]) == 1)
            {
                strcpy(temp,string[i]);
                strcpy(string[i],string[j]);
                strcpy(string[j],temp);
            }
        }
    }
    bool chk = false;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(string[i],string[j]) == 0)
            {
                strcpy(string[j],"00");
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(strcmp(string[i],"00") == 1)
            printf("%s\n",string[i]);
    }
    return 0;
}
/*
ข้างหน้ามาก่อนข้างหลัง ได้ -1
ข้างหลังมาก่อนข้างหน้า ได้ 1
เหมือนกันไ้ด้ 0
*/
