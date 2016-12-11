#include <stdio.h>
int main()
{
    int i=1,j,k,n,count=1;
    scanf("%d",&n);
    char str[n+1],s1,s2;
    scanf(" %c",&s1);
    char temp = s1;
    str[0] = s1;
    while(i != n)
    {
        scanf(" %c",&s2);
        i++;
        if(temp != s2)
        {
            str[count] = s2;
            ++count;
        }
        if(temp == s2)
        {
            temp = str[count-2];
            str[count] = '-';
            str[count-1] = '-';
            --count;
        }
        else
            temp = s2;
    }
    printf("%d\n",count);
    if(count==0)
    {
        printf("empty\n");
        return 0;
    }
    for(j=count-1; j>=0; --j)
        printf("%c",str[j]);
    return 0;
}
