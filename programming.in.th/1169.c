#include <stdio.h>
#include <string.h>
int main()
{
    int i,j;
    char string[201];
    int count=0;
    scanf("%s",string);
    int length = strlen(string);
    for(i=0;i<length;i++)
    {
        if(string[i] == '(' && string[i]!='-')
        {
            for(j=i+1;j<length;j++)
            {
                if(string[j] == ')' && string[j] != '-')
                {
                    string[i] = '-';
                    string[j] = '-';
                    break;
                }
            }
        }
    }
    for(i=0;i<length;i++)
    {
        if(string[i]!= '-')
        {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}