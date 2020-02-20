#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int num,i,j,k,x,y,z;
    int count=2;
    scanf("%d",&num);
    if(num >=100000)
    {
        printf("1003001");
        return 0;
    }
    while(1)
    {
        for(i=2;i<=sqrt(num);i++)
        {
            if(num%i==0)
            {
                count++;
                break;
            }
        }
        if(count==2)
        {
            k=0;
            j=0;
            char string[8];
            snprintf(string,10,"%d",num);
            int length = strlen(string);
            if(length%2==0)
            {
                char str1[length/2];
                char str2[length/2];
                for(i=0;i<length/2;i++)
                {
                    str1[i] = string[i];
                }
                for(i=length-1;i>=length/2;i--)
                {
                    str2[k] = string[i];
                    k++;
                }
                str1[length/2] = '\0';
                str2[length/2] = '\0';
                int count_1=0;
                for(i=0;i<strlen(str1);i++)
                {
                    if(str1[i] == str2[i])
                    {
                        count_1++;
                    }
                }
                if(count_1 >= length/2)
                {
                    printf("%s\n",string);
                    return 0;
                }
            }
            if(length%2==1)
            {
                int count_1=0;
                char str1[(length/2)+1];
                char str2[(length/2)+1];
                for(i=0;i<length/2+1;i++)
                {
                    str1[i] = string[i];
                }
                k=0;
                for(i=length-1;i>=length/2;i--)
                {
                    str2[k] = string[i];
                    k++;
                }
                str1[length/2+1] = '\0';
                str2[length/2+1] = '\0';
                for(i=0;i<strlen(str1);i++)
                {
                    if(str1[i] == str2[i])
                    {
                        count_1++;
                    }
                }
                if(count_1 >= length/2+1)
                {
                    printf("%s\n",string);
                    return 0;
                }
            }
        }
        count=2;
        num++;
    }
    return 0;
}
