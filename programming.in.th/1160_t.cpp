#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int row_num[4] = {0,0,-1,1};
int column_num[4] = {-1,1,0,0};
bool save_start[160][160],save_end[160][160];
int map[160][160];
int m,n,start_y,start_x,end_y,end_x,t=0;
vector<int> save_way_y,save_way_x;
vector<int> save_wall_y,save_wall_x;
int walk();
void find_start(int,int);
void find_end(int,int);
bool check_valid(int,int);
void reset();
void print();
int main()
{
    int i,j,count_wall=0,min=999999;
    scanf("%d %d %d %d %d %d",&m,&n,&start_y,&start_x,&end_y,&end_x);
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    start_y--;
    start_x--;
    end_y--;
    end_x--;
    find_start(start_y,start_x);
    reset();
    find_end(end_y,end_x);
    reset();
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(save_start[i][j] && save_end[i][j])
            {
                save_wall_y.push_back(i);
                save_wall_x.push_back(j);
                count_wall++;
            }
        }
    }
    int wall_size = save_wall_y.size();

    for(i=0; i<wall_size; i++)
    {
        map[start_y][start_x] = 2;
        map[save_wall_y[i]][save_wall_x[i]] = 1;
        int num = walk();
        if(num<min)
            min = num;
        reset();
    }
    printf("%d\n%d",count_wall,min-1);
    //find way

    return 0;
}
int walk()
{
    for(int t=2; true; t++)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(map[i][j] == t)
                {
                    save_way_y.push_back(i);
                    save_way_x.push_back(j);
                }
            }
        }
        int save_size = save_way_y.size();
        for(int z=0; z<save_size; z++)
        {
            int n1 = save_way_y[z];
            int n2 = save_way_x[z];
            if(map[n1][n2-1]==1)
            {
                map[n1][n2-1] = t+1;
            }
            if(map[n1][n2+1]==1)
            {
                map[n1][n2+1] = t+1;
            }
            if(map[n1-1][n2]==1)
            {
                map[n1-1][n2] = t+1;
            }
            if(map[n1+1][n2]==1)
            {
                map[n1+1][n2] = t+1;
            }

        }
        save_way_y.clear();
        save_way_x.clear();
        if(map[end_y][end_x]!=1)
        {
            return map[end_y][end_x];
        }

    }
}
void find_start(int i,int j)
{
    map[i][j] = 2;
    for(int x=0; x<4; x++)
    {
        int row = i+row_num[x];
        int col = j+column_num[x];
        if(check_valid(row,col) && map[row][col]==0)
        {
            save_start[row][col] = true;
        }
    }
    for(int x=0; x<4; x++)
    {
        int row = i+row_num[x];
        int col = j+column_num[x];
        if(check_valid(row,col) && map[row][col]==1)
        {
            find_start(row,col);
        }
    }
}
void find_end(int i,int j)
{
    map[i][j] = 2;
    for(int x=0; x<4; x++)
    {
        int row = i+row_num[x];
        int col = j+column_num[x];
        if(check_valid(row,col) && map[row][col] == 0)
            save_end[row][col] = true;
    }
    for(int x=0; x<4; x++)
    {
        int row = i + row_num[x];
        int col = j + column_num[x];
        if(check_valid(row,col) && map[row][col] == 1)
            find_end(row,col);
    }
}
void reset()
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j] >= 2)
                map[i][j] = 1;
        }
    }

}
bool check_valid(int row,int col)
{
    return (row>=0) && (row<m) && (col>=0) && (col<n);
}
