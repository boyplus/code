#include <bits/stdc++.h>
using namespace std;
int color[1000000];
vector<int> vec[1000000];
int cnt = 0;
bool dfs(int u,int parent){
	color[u] = 1;
	for(int i=0;i<vec[u].size();i++){
		int v = vec[u][i];
		if(color[v] == 0 && vec[v].size() == 2){
			dfs(v,u);
		}
		else if(color[v] == 1 && v != parent){
			return true;
		}
	}
	color[u] = 2;
	return false; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
    cout << fixed;
    int n,m,a,b;
    cin >> n >> m;
    for(int i=0;i<m;i++){
    	cin >> a >> b;
    	vec[a].push_back(b);
    	vec[b].push_back(a);
    }	
    for(int i=1;i<=n;i++){
    	if(color[i] == 0 && vec[i].size() == 2){
    		bool tt = dfs(i,-1);
    		if(tt){
    			cnt++;
    		}
    	}
    }
    cout << cnt << "\n";
	return 0;
}