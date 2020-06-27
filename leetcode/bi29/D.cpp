#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
	//This ssolution get wrong answer
	int color[20] = {0};
	int adj[20][20] = {{0}};
	int d[20] = {0}, f[20] = {0}, time = 0;
	vector<int> vec[20];
	stack<int> s;
	int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
		vector<int> ord;
		for(int i=0;i<dependencies.size();i++){
			int u = dependencies[i][0], v = dependencies[i][1];
			vec[u].push_back(v);
			adj[u][v] = 1;
		}
		time = 0;
		for(int i=1;i<=n;i++){
			if(color[i] == 0){
				tsort(i);
			}
		}
		while(!s.empty()){
			ord.push_back(s.top());
			s.pop();
		}
		int idx = 0, ans = 0;
		while(idx < ord.size()){
			int cnt = 1;
			ans++;
			int u = ord[idx];
			while(cnt < k && idx+1 < ord.size()){
				u = ord[idx];
				int v = ord[idx+1];
				if(adj[u][v] == false){
					cnt++;
				}
				if(adj[u][v] == true){
					break;
				}
				idx++;
			}
			idx++;
		}
		return ans;
	}
	void tsort(int u){
		color[u] = 1;
		d[u] = ++time;
		for(int i=0;i<vec[u].size();i++){
			int v = vec[u][i];
			if(color[v] == 0){
				tsort(v);	
			}
		}
		color[u] = 2;
		f[u] = ++time;
		s.push(u);
	}
};
int main(){
	Solution s;
	vector<vector<int>> vec = {{5,1},{3,1},{5,4},{4,1},{2,3}};
	int ans = s.minNumberOfSemesters(5,vec,3);
	cout << ans;
}