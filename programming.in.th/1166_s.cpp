#include <stdio.h>
int main()
{
    int i,j,k,n=30,m=30;
    scanf("%d %d",&n,&m);
    char num[n][m+1];
    for(i=0; i<n; ++i)
    {
        for(j=0; j<m; ++j)
        {
            scanf(" %c",&num[i][j]);
        }
    }
    int count=0;
    for(i=0; i<n; ++i)
    {
        for(j=0; j<m;++j)
        {
            int temp=0;
            if(num[i][j] == '.')
            {
                if(i)
                {
                    if(num[i-1][j] == '.' || num[i-1][j] == '@')
                    {
                        ++temp;
                    }
                }
                else
                    ++temp;
                if(j)
                {
                    if(num[i][j-1] == '.' || num[i][j-1] == '@')
                    {
                        temp++;
                    }
                }
                else
                    ++temp;
                if(i<n-1)
                {
                    if(num[i+1][j] == '.' || num[i+1][j] == '@')
                    {
                        ++temp;
                    }
                }
                else
                    ++temp;
                if(j<m-1)
                {
                    if(num[i][j+1] == '.' || num[i][j+1] == '@')
                    {
                        ++temp;
                    }
                }
                else
                    ++temp;
            }
            if(temp >=4)
            {
                num[i][j] = '@';
                ++count;
            }
        }
    }
    int save[n][m];
    int max=0;
    for(i=0; i<n; ++i)
    {
        for(j=0; j<m;++j)
        {
            if(!(num[i][j]-'@'))
            {
                for(int a=0; a<n; ++a)
                {
                    for(int b=0; b<m; ++b)
                    {
                        save[a][b]=num[a][b];
                    }
                }
                save[i][j]='3';
                int eiei=0;
                for(int zz=0; zz<count-(count-max)+20; ++zz)
                {
                    for(int a=0; a<n; ++a)
                    {
                        for(int b=0; b<m; ++b)
                        {
                            if(a>0&&save[a-1][b]=='3'&&save[a][b]=='@')
                                save[a][b]='3';
                            if(b>0&&save[a][b-1]=='3'&&save[a][b]=='@')
                                save[a][b]='3';
                            if(a<n-1&&save[a+1][b]=='3'&&save[a][b]=='@')
                                save[a][b]='3';
                            if(b<m-1&&save[a][b+1]=='3'&&save[a][b]=='@')
                                save[a][b]='3';
                        }
                    }
                }
                for(int a=0;a<n;++a)
                {
                    for(int b=0;b<m;++b)
                    {
                        if(save[a][b]=='3')
                                ++eiei;
                    }
                }
                if(eiei>max)
                    max=eiei;
                if(count/2<max)
                    break;
            }
            if(count/2<max)
                break;
        }
        if(count/2<max)
                break;
    }
    printf("%d",max);
    return 0;
}
