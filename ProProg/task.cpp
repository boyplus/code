#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int m,n;
bool visited[110];
vector<int> vec[110];
stack<int> ans;
void dfs(int u){
	if(visited[u] == true){
		return;
	}
	visited[u] = true;
	for(int i=0;i<vec[u].size();i++){
		if(visited[vec[u][i]] == false){
			dfs(vec[u][i]);
		}
	}
	ans.push(u);
}
int main(){
	while(1){
		int u,v;
		scanf("%d %d",&n,&m);
		if(n == 0 && m == 0){
			return 0;
		}
		//clear
		while(!ans.empty()){
			ans.pop();
		}
		for(int i=1;i<=n;i++){
			vec[i].clear();
			visited[i] = false;
		}
		for(int i=0;i<m;i++){
			scanf("%d %d",&u,&v);
			vec[u].push_back(v);
		}
		for(int i=1;i<=n;i++){
			if(visited[i] == false){
				dfs(i);
			}
		}
		while(!ans.empty()){
			printf("%d ",ans.top());
			ans.pop();
		}
		printf("\n");
	}

	return 0;
}