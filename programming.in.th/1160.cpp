#include <bits/stdc++.h>
using namespace std;
void find1(int,int);
void find2(int,int);
void reset();
int map1[160][160],m,n;
bool save_des1[160][160]= {false};
bool save_des2[160][160]= {false};
vector<int> des_y,des_x;
struct Point
{
    int x;
    int y;
};
struct queueNode
{
    Point pt;
    int dist;
};
bool isValid(int row, int col)
{
    return (row >= 0) && (row < m) && (col >= 0) && (col < n);
}
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};
int BFS(Point src, Point dest)
{
    bool visited[m][n];
    memset(visited, false, sizeof visited);
    visited[src.x][src.y] = true;
    queue<queueNode> q;
    queueNode s = {src, 0};
    q.push(s);
    while (!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;
        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
            if (isValid(row, col) && map1[row][col] && !visited[row][col])
            {
                visited[row][col] = true;
                queueNode Adjcell = { {row, col},curr.dist + 1};
                q.push(Adjcell);
            }
        }
    }
}
int main()
{
    int i,j,k,y_start,x_start,y_end,x_end,count_ans=0,min1=INT_MAX;
    scanf("%d %d %d %d %d %d",&m,&n,&y_start,&x_start,&y_end,&x_end);
    for(i=0; i<m; ++i)
        for(j=0; j<n; ++j)
            scanf("%d",&map1[i][j]);
    --y_start;
    --x_start;
    --y_end;
    --x_end;
    find1(y_start,x_start);
    reset();
    find2(y_end,x_end);
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            if(save_des1[i][j] && save_des2[i][j])
            {
                ++count_ans;
                des_y.push_back(i);
                des_x.push_back(j);
            }
        }
    }
    int my_size = des_y.size();
    for(i=0;i<my_size;++i)
    {
        map1[des_y[i]][des_x[i]] = 1;
        Point source = {y_start, x_start};
        Point dest = {y_end, x_end};
        int dist = BFS(source, dest);
        if(dist<min1)
            min1 = dist;
        map1[des_y[i]][des_x[i]] = 0;
    }
    printf("%d\n%d",count_ans,min1+1);
    return 0;
}
void find1(int i,int j)
{
    map1[i][j] = 2;
    if(map1[i][j-1] == 0 && j>0)
        save_des1[i][j-1] = true;
    if(map1[i][j+1] == 0 && j<n)
        save_des1[i][j+1] = true;
    if(map1[i-1][j] == 0 && i>0)
        save_des1[i-1][j] = true;
    if(map1[i+1][j] == 0 && i<m)
        save_des1[i+1][j] = true;
    if(map1[i][j-1] == 1 && j>0)
        find1(i,j-1);
    if(map1[i][j+1] == 1 && j<n)
        find1(i,j+1);
    if(map1[i-1][j] == 1 && i>0)
        find1(i-1,j);
    if(map1[i+1][j] == 1 && i<m)
        find1(i+1,j);
}
void find2(int i,int j)
{
    map1[i][j] = 2;
    if(map1[i][j-1] == 0 &&j >0)
        save_des2[i][j-1] = true;
    if(map1[i][j+1] == 0 &&j <n)
        save_des2[i][j+1] = true;
    if(map1[i-1][j] == 0 &&i >0)
        save_des2[i-1][j] = true;
    if(map1[i+1][j] == 0 && i<m)
        save_des2[i+1][j] = true;
    if(map1[i][j-1] == 1 && j>0)
        find2(i,j-1);
    if(map1[i][j+1] == 1 &&j<n)
        find2(i,j+1);
    if(map1[i-1][j] == 1 &&i>0)
        find2(i-1,j);
    if(map1[i+1][j] == 1 &&i<m)
        find2(i+1,j);
}
void reset()
{
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(map1[i][j] == 2)
                map1[i][j] = 1;
}
