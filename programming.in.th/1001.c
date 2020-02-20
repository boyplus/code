#include <stdio.h>
#include <string.h>
int main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    int num[m];
    char string[n][m+1];
    for(i=0;i<n;i++)
        scanf("%s",&string[i]);
    for(i=0;i<m;i++)
        scanf("%d",&num[i]);
    char temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(string[i][j] == 'O')
                num[j]=0;
            if(string[i][j] == '.')
            {
                if(num[j] >=1)
                {
                    string[i][j] = '#';
                    for(k=i+1;k<n;k++)
                    {
                        if(string[k][j] == '.' && string[k-1][j] == '#')
                        {
                            temp = string[k][j];
                            string[k][j] = string[k-1][j];
                            string[k-1][j] = temp;
                        }
                    }
                    num[j]--;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%c",string[i][j]);
        }
        printf("\n");
    }
    return 0;
}
