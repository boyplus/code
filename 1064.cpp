#include <cstdio>
#include <vector>
#include <limits.h>
using namespace std;
vector <int> save_tree_y,save_tree_x;
bool visit[100][100];
bool land_pool[100][100];
char str[100][100];
int land[100][100],m,n;
bool walk_size(int,int,int);
void find_land(int,int);
void find_pool(int,int,int);
void reset();
int main()
{
    int i,j,k,max_area=-1,min_pool = INT_MAX,count_s=0;
    scanf("%d %d",&n,&m);
    for(i=0; i<m; ++i)
    {
        scanf("%s",&str[i]);
        for(j=0; j<n; ++j)
        {
            if(str[i][j] == 'S')
            {
                land[i][j] = 1;
                count_s++;
            }
            else if(str[i][j] == 'P')
            {
                land[i][j] = 2;
                land_pool[i][j] = true;
                ++count_s;
            }
            else
                land[i][j] = 3;
        }
    }
    if(count_s == 0)
    {
        printf("0 0\n");
        return 0;
    }
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            int size_now = 0;
            if(land[i][j] != 3) //not Tree
            {
                int count=0,count_pool=0;
                bool chk = true;
                while(chk)
                {
                    ++count;
                    chk = walk_size(i,j,++size_now);
                }
                find_pool(i,j,--count);
                int my_size = save_tree_y.size();
                for(int x=0; x<my_size; x++)
                {
                    if(land_pool[save_tree_y[x]][save_tree_x[x]] && !visit[save_tree_y[x]][save_tree_x[x]])
                    {
                        find_land(save_tree_y[x],save_tree_x[x]);
                        ++count_pool;
                    }
                }
                if(count > max_area)
                {
                    max_area = count;
                    min_pool = count_pool;
                }
                if(count == max_area)
                    if(count_pool < min_pool)
                        min_pool = count_pool;
                reset();
                save_tree_y.clear();
                save_tree_x.clear();
            }
        }
    }
    printf("%d %d\n",max_area*max_area,min_pool);
    return 0;
}
void find_pool(int i,int j,int size)
{
    int n1 = i + size,n2 = j+size;
    for(int y=i; y < n1; ++y)
    {
        for(int x=j; x < n2; ++x)
        {
             if(land[y][x] == 2)
            {
                save_tree_y.push_back(y);
                save_tree_x.push_back(x);
            }
        }
    }
}
void reset()
{
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            visit[i][j] = false;
}
void find_land(int i,int j)
{
    visit[i][j] = true;
    if(land_pool[i][j-1] && !visit[i][j-1])
        find_land(i,j-1);
    if(land_pool[i][j+1] && !visit[i][j+1])
        find_land(i,j+1);
    if(land_pool[i-1][j] && !visit[i-1][j])
        find_land(i-1,j);
    if(land_pool[i+1][j] && !visit[i+1][j])
        find_land(i+1,j);
}
bool walk_size(int i,int j,int size)
{
    int n1 = i + size,n2 = j + size;
    for(int y = i; y < n1; ++y)
        for(int x = j; x < n2; ++x)
            if(land[y][x] == 3 || land[y][x] ==0) //Tree or end of stage
                return false;
    return true;
}
