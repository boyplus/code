#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,1,-1};
    void dfs(int y,int x,vector<vector<char>>& grid){
        grid[y][x] = '0';
        for(int j=0;j<4;j++){
            int yy = y+dy[j];
            int xx = x+dx[j];
            if(yy < 0 || xx < 0 || yy >= grid.size() || xx >= grid[0].size()) continue;
            if(grid[yy][xx] == '1'){
                dfs(yy,xx,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};
int main(){
	Solution s;
	vector<vector<char>> v = {
        {'1','1','1'},
        {'0','1','0'},
        {'1','1','1'}
    };
    cout << s.numIslands(v) << endl;
}