#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec[2010],use;
bool visited[2010];
class grid{
public:
	int u,count;
	grid(int u,int count){
		this->u = u;
		this->count = count;
	}
};
int bfs(int u){
	int mx = 0;
	queue<grid> q;
	q.push(grid(u,1));
	while(!q.empty()){
		int v = q.front().u,count = q.front().count;
		visited[v] = true;
		if(count > mx){
			mx = count;
		}
		q.pop();
		for(int i=0;i<vec[v].size();i++){
			if(visited[vec[v][i]] == false){
				q.push(grid(vec[v][i],count+1));
			}
		}
	}
	return mx;
}
int main(){
	int n,temp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&temp);
		if(temp != -1){
			vec[temp].push_back(i);
		}
		else{
			use.push_back(i);
		}
	}
	int Mx = 0;
	for(int i=0;i<use.size();i++){
		if(visited[use[i]] == false){
			//printf("in start %d\n");
			Mx = max(bfs(use[i]),Mx);
		}
	}
	printf("%d\n",Mx);
	return 0;
}