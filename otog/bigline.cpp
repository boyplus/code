#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100005;
int group[maxn],cnt = 1;
vector<int> vec[maxn];
void dfs(int u){
	group[u] = cnt;
	for(int v:vec[u]){
		if(group[v] == 0){
			dfs(v);
		}
	}
}
int main(){
	int n,m,q,u,v;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(group[i] == 0){
			dfs(i);
			cnt++;
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&u,&v);
		if(group[u] == group[v]){
			printf("true\n");
		} else{
			printf("false\n");
		}
	}
    return 0;
}