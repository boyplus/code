#include <cstdio>
#include <queue>
using namespace std;
queue<int> save_y,save_x;
char str[70][70];
int map[70][70],m,n;
int main()
{
    int i,j,k,t,y_start,x_start;
    scanf("%d %d",&m,&n);
    for(i=0; i<m; i++)
    {
        scanf("%s",&str[i]);
        for(j=0; j<n; j++)
        {
            if(str[i][j] == 'S')
            {
                map[i][j] = 4;
                y_start = i;
                x_start = j;
            }
            else if(str[i][j] == '.')
                map[i][j] = 3;
            else if(str[i][j] == '*')
                map[i][j] = 6;
            else if(str[i][j] == 'X')
                map[i][j] = 2;
            else if(str[i][j] == 'D')
                map[i][j] = 5;
        }
    }
    if(map[y_start][x_start-1] == 5 || map[y_start][x_start+1] == 5 ||map[y_start-1][x_start] == 5 || map[y_start+1][x_start] == 5)
    {
        printf("%d\n",1);
        return 0;
    }
    for(t=6; true; t++)
    {
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(map[i][j] == 6)
                {
                    if(map[i][j-1] == 3 || map[i][j-1] == 4)
                    {
                        save_y.push(i);
                        save_x.push(j-1);
                    }
                    if(map[i][j+1] == 3 || map[i][j-1] ==4)
                    {
                        save_y.push(i);
                        save_x.push(j+1);
                    }
                    if(map[i-1][j] == 3 || map[i-1][j] == 4)
                    {
                        save_y.push(i-1);
                        save_x.push(j);
                    }
                    if(map[i+1][j] == 3 || map[i+1][j] == 4)
                    {
                        save_y.push(i+1);
                        save_x.push(j);
                    }
                }
            }
        }
        while(!save_y.empty())
        {
            map[save_y.front()][save_x.front()] = 6;
            save_y.pop();
            save_x.pop();
        }
        //walk
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(map[i][j] == 4)
                {
                    if(map[i][j-1] == 3)
                    {
                        save_y.push(i);
                        save_x.push(j-1);
                    }
                    if(map[i][j+1] == 3)
                    {
                        save_y.push(i);
                        save_x.push(j+1);
                    }
                    if(map[i-1][j] == 3)
                    {
                        save_y.push(i-1);
                        save_x.push(j);
                    }
                    if(map[i+1][j] == 3)
                    {
                        save_y.push(i+1);
                        save_x.push(j);
                    }
                }
            }
        }
        while(!save_y.empty())
        {
            map[save_y.front()][save_x.front()] = 4;
            save_y.pop();
            save_x.pop();
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(map[i][j] == 4)
                {
                    if(map[i][j-1] == 5 || map[i][j+1] == 5 ||map[i-1][j] == 5 || map[i+1][j] == 5)
                    {
                        printf("%d\n",t-4);
                        return 0;
                    }
                }
            }
        }
        if(t>300)
        {
            printf("KAKTUS\n");
            return 0;
        }
    }
    return  0;
}