#include <stdio.h>
void print(int,int);
char str[100][100];
int table[100][100]={0};
int main()
{
    int i,j,k,n,m,w,h;
    scanf("%d %d",&w,&h);
    for(i=0;i<h;i++)
    {
        scanf("%s",&str[i]);
    }
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            if(str[i][j] == '.')
            {
                table[i][j] = 1;
            }
            else if(str[i][j]=='^')
            {
                table[i][j] = 2;
            }
            else if(str[i][j]=='<')
            {
                table[i][j] = 3;
            }
            else if(str[i][j]=='>')
            {
                table[i][j] = 4;
            }
            else if(str[i][j] == 'V')
            {
                table[i][j] = 5;
            }
            else if(str[i][j] == 'B')
            {
                table[i][j] = 6;
            }
            else
            {
                table[i][j] = -1;
            }
        }
    }
    //7 -> - from left or right
    //8 -> - from up or down
    //10 -> plus sign
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            if(table[i][j] == 2) //^
            {
                int temp_i = i-1;
                while(temp_i>=0&&table[temp_i][j]!=-1)
                {
                    if(table[temp_i][j]==1||table[temp_i][j]==8)
                    {
                        table[temp_i][j] = 8;
                    }
                    else if(table[temp_i][j]==7)
                    {
                        table[temp_i][j] = 10;
                    }
                    temp_i--;
                }
            }
            else if(table[i][j] == 5)//V
            {
                int temp_i = i+1;
                while(temp_i<h&&table[temp_i][j]!=-1)
                {
                    if(table[temp_i][j] == 1||table[temp_i][j]==8)
                    {
                        table[temp_i][j] = 8;
                    }
                    else if(table[temp_i][j] == 7)
                    {
                        table[temp_i][j] = 10;
                    }
                    temp_i++;
                }
            }
        }
    }
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            printf("%2d",table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    print(w,h);
    return 0;
}
void print(int w,int h)
{
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            printf("%c",str[i][j]);
        }
        printf("\n");
    }
}
