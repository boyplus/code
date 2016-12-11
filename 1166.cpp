#include <cstdio>
using namespace std;
char str[40][40];
void Trav(int,int);
int m,n,sum=0;
int main()
{
    int i,j,k;
    scanf("%d %d",&m,&n);
    for(i=0; i<m; i++)
        scanf("%s",&str[i]);
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(str[i][j] == '#')
            {
                if(j>0&&str[i][j-1]=='.')
                    str[i][j-1] = '-';
                if(str[i][j+1]=='.')
                    str[i][j+1] = '-';
                if(i>0&&str[i-1][j]=='.')
                    str[i-1][j] = '-';
                if(str[i+1][j]=='.')
                    str[i+1][j] = '-';
            }
        }
    }
    int count=0,max=-1;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(str[i][j] == '.')
            {
                Trav(i,j);
                if(sum>max)
                    max = sum;
            }
            sum=0;
        }
    }
    printf("%d\n",max);
    return 0;
}
void Trav(int i,int j)
{
    sum++;
    str[i][j] = 'x';
    if(str[i][j+1] == '.')
        Trav(i,j+1);
    if(str[i][j-1] == '.')
        Trav(i,j-1);
    if(str[i-1][j]=='.')
        Trav(i-1,j);
    if(str[i+1][j]=='.')
        Trav(i+1,j);
}
