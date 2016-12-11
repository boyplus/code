#include <cstdio>
#include <string.h>
char str1[300],str2[300];
int length1,length2;
int main()
{
    scanf("%s %s",&str1,&str2);
    length1 = strlen(str1),length2 = strlen(str2);
    int i,j,k,size,start=0,end=0,max=-1,count=0;
    for(i=0;i<length1;i++)
    {
        for(j=0;j<length2;j++)
        {
            count = 0;
            if(str1[i] == str2[j])
            {
                for(k=i;k<length1 && count + j < length2;k++)
                {
                    if(str1[k] == str2[count+j])
                    {
                        count++;
                        if(count > max)
                        {
                            start = i;
                            end = k;
                            max = count;
                        }
                    }
                    else
                    {
                        count = 0;
                        break;
                    }
                }
            }
        }
    }
    for(i=start;i<=end;i++)
        printf("%c",str1[i]);
    return 0;
}

