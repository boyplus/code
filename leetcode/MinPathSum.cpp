#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid){
		int n = grid.size();
		int m = grid[0].size();
		int dp[n+5][m+5];
		for(int i=0;i<=n+1;i++){
			for(int j=0;j<=m+1;j++){
				dp[i][j] = 0;
			}
		}
		
		for(int i=0;i<grid.size();i++){
			for(int j=0;j<grid[0].size();j++){
				dp[i+1][j+1] = grid[i][j];
			}
		}

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i == 1 && j == 1){

				} else if(j == 1){
					dp[i][j] += dp[i-1][j];
				} else if(i == 1){
					dp[i][j] += dp[i][j-1];
				} else{
					dp[i][j] = min(dp[i][j]+dp[i-1][j],dp[i][j]+dp[i][j-1]);
				}

			}
		}

		return dp[n][m];
	}
};
int main(){
	Solution s;
	vector<vector<int>> v = {
		{1,3,1},
		{1,5,1},
		{4,2,1}
	};
	cout << s.minPathSum(v) << endl;
}