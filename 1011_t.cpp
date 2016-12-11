#include <stdio.h>
#include <iostream>
#include <vector>
int score=0;
void print(int,int);
void check_block_fall(int,int);
void find_block(int,int);
void find_block_left(int,int,int,int);
void find_block_right(int,int,int,int);
void find_block_up(int,int,int,int);
void find_block_down(int,int,int,int);
char str[5][5];
char command,temp;
void f_delete();
using namespace std;
vector <int>save_position_x;
vector <int>save_position_y;
int main()
{
    int i,j,k,n,m,n_request,position_x,position_y;
    bool chk = false;
    scanf("%d %d",&n,&m);
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf(" %c",&str[i][j]);
    check_block_fall(n,m);
    scanf("%d",&n_request);
    for(i=0; i<n_request; i++)
    {
        save_position_y.clear();
        save_position_x.clear();
        chk = false;
        scanf("%d %d %c",&position_y,&position_x,&command);
        if(str[position_y][position_x] == '#' || str[position_y][position_x] == '-')
        {
            score-=5;
            continue;
        }
        if(command == 'L')
        {
            if(str[position_y][position_x-1] != '-' || position_x == 0)
            {
                score-=5;
                continue;
            }
            temp = str[position_y][position_x];
            str[position_y][position_x-1] = temp;
            str[position_y][position_x] = '-';
            position_x--;
            check_block_fall(n,m);
            find_block(n,m);

        }
        else if(command == 'R')
        {
            if(str[position_y][position_x+1] != '-' || position_x > m-2)
            {
                score-=5;
                continue;
            }
            temp = str[position_y][position_x];
            str[position_y][position_x+1] = temp;
            str[position_y][position_x] = '-';
            position_x++;
            check_block_fall(n,m);
            find_block(n,m);
        }
        check_block_fall(n,m);
        f_delete();
        check_block_fall(n,m);
        save_position_y.clear();
        save_position_x.clear();
    }
    check_block_fall(n,m);
    find_block(n,m);
    f_delete();
    printf("%d\n",score);
    print(n,m);
    return 0;
}
void print(int n,int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            printf("%c ",str[i][j]);
        printf("\n");
    }
}
void check_block_fall(int n,int m)
{
    int i,j,k,position_x,position_y;
    char temp;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(str[i][j] >= 'A' && str[i][j] <= 'Z')
            {
                position_y = i;
                position_x = j;
                while(position_y < n-1 && str[position_y+1][position_x] == '-')
                {
                    temp = str[position_y][position_x];
                    str[position_y+1][position_x] = temp;
                    str[position_y][position_x] = '-';
                    position_y++;
                }
            }
        }
    }
}
void find_block_left(int n,int m,int position_y,int position_x)
{
    if(str[position_y][position_x+1] == str[position_y][position_x] && str[position_y][position_x]!='#' && str[position_y][position_x]!='-')
    {
        save_position_y.push_back(position_y);
        save_position_x.push_back(position_x+1);
        save_position_y.push_back(position_y);
        save_position_x.push_back(position_x);
        if(position_x > 0)
            find_block_left(n,m,position_y,position_x-1);
    }
}
void find_block_right(int n,int m,int position_y,int position_x)
{
    if(str[position_y][position_x-1] == str[position_y][position_x] && str[position_y][position_x]!='#' && str[position_y][position_x]!='-')
    {
        save_position_y.push_back(position_y);
        save_position_x.push_back(position_x-1);
        save_position_y.push_back(position_y);
        save_position_x.push_back(position_x);
        if(position_x < n-1)
            find_block_right(n,m,position_x+1,position_y);
    }
}
void find_block_up(int n,int m,int position_y,int position_x)
{
    if(str[position_y+1][position_x] == str[position_y][position_x] && str[position_y][position_x]!='#' && str[position_y][position_x]!='-')
    {
        save_position_y.push_back(position_y+1);
        save_position_x.push_back(position_x);
        save_position_y.push_back(position_y);
        save_position_x.push_back(position_x);
        if(position_y > 0)
            find_block_up(n,m,position_y-1,position_x);
    }
}
void find_block_down(int n,int m,int position_y,int position_x)
{
    if(str[position_y-1][position_x] == str[position_y][position_x] && str[position_y][position_x]!='#' && str[position_y][position_x]!='-')
    {
        save_position_y.push_back(position_y-1);
        save_position_x.push_back(position_x);
        save_position_y.push_back(position_y);
        save_position_x.push_back(position_x);
        if(position_y < n-1)
            find_block_down(n,m,position_y+1,position_x);
    }
}
void find_block(int n,int m)
{
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            if(str[a][b] >= 'A' && str[a][b] <= 'Z')
            {
                if(b > 0)
                    find_block_left(n,m,a,b-1);
                if(b < n-1)
                    find_block_right(n,m,a,b+1);
                if(a > 0)
                    find_block_up(n,m,a-1,b);
                if(a < n-1)
                    find_block_down(n,m,a+1,b);
            }
        }
    }
}
void f_delete()
{
    for(int i=0; i<save_position_y.size(); i++)
    {
        if(str[save_position_y[i]][save_position_x[i]] != '-')
        {
            score+=5;
            str[save_position_y[i]][save_position_x[i]] = '-';
        }
    }
}
