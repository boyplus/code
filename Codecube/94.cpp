#include <stdio.h>
char str[100001];
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    scanf("%s",&str);
    for(i=0;i<n-1;i++)
    {
        if(str[i] == str[i+1])
        {
            printf("Wrong Answer\n");
            return 0;
        }
    }
    printf("Accepted");
    return 0;
}
