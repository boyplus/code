#include <stdio.h>
#include <string.h>
int main()
{
    int i=0,j=0,k=0,n;
    scanf("%d",&n);
    char string[n];
    int length =0;
    for(i=0;i<n;++i)
    {
        scanf(" %c",&string[i]);
        ++length;
    }
    string[length] = '\0';
    while(1)
    {
        int num = length-1;
        for(i=0;i<num;++i)
        {
            if(string[i] == string[i+1])
            {
                k = k+2;
                int num_2 = length-k;
                for(j=i;j<num_2;++j)
                {
                    string[j] = string[j+2];
                }
                string[length-k] = '\0';
                i=0;
            }
        }
        if(string[0]!=string[1])
        {
            break;
        }
    }
    printf("%d\n",strlen(string));
    if(k>=length)
    {
        printf("empty\n");
        return 0;
    }
    int start = strlen(string)-1;
    for(i=start;i>=0;--i)
    {
        printf("%c",string[i]);
    }
    return 0;
}
