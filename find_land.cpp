#include <cstdio>
#include <vector>
using namespace std;
vector<int> sy,sx;
int land[100][100],m,n;
bool visit[100][100] = {false};
void find_land(int,int);
void reset();
int main()
{
    int i,j,k,count=0;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&land[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(land[i][j] == 1 && visit[i][j] == false)
            {
                find_land(i,j);
                count++;
            }
            //reset();
        }
    }
    for(i=0;i<sy.size();i++)
    {
        printf("%d %d\n",sy[i],sx[i]);
    }
    printf("count = %d\n",count);
    return 0;
}
void reset()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            visit[i][j] = false;
        }
    }
}
void find_land(int i,int j)
{
    visit[i][j] = true;
    sy.push_back(i);
    sx.push_back(j);
    if(land[i][j-1] == 1 && j>0 && visit[i][j-1] == false)
    {
        find_land(i,j-1);
    }
    if(land[i][j+1] == 1 && j<n && visit[i][j+1] == false)
    {
        find_land(i,j+1);
    }
    if(land[i-1][j] == 1 && i>0 && visit[i-1][j] == false)
    {
        find_land(i-1,j);
    }
    if(land[i+1][j] == 1 && i<m && visit[i+1][j] == false)
    {
        find_land(i+1,j);
    }
}
