#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
class graph{
public:
	int u,v,w;
	graph(int u,int v,int w){
		this->u = u;
		this->v = v;
		this->w = w;
	}
};
int Head[2000];
int findHead(int u){
	if(u == Head[u]){
		return u;
	}
	return Head[u] = findHead(Head[u]);
}
int max(int a,int b){
	if(a > b){
		return a;
	}
	return b;
}
bool cmp(const graph& left,const graph& right){
	return left.w < right.w;
}
vector< pair<int,int> > newVec[2000];
vector<graph> vec;
void dfs(int first,int last,int now);
bool chk[2000];
int minAns = -1;
int main(){
	int nowTT = 1;
	while(1){
		int n,m,q,uu,vv,ww,first,last;
		scanf("%d %d %d",&n,&m,&q);
		if(n == 0 && m == 0 && q == 0){
			return 0;
		}
		
		///clear
		vec.clear();
		memset(Head,0,sizeof(Head));
		for(int i=1;i<=n;i++){
			Head[i] = i;
		}
		for(int i=1;i<=n;i++){
			newVec[i].clear();
			chk[i] = false;
		}
		///input graph
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&uu,&vv,&ww);
			vec.push_back(graph(uu,vv,ww));
		}
		sort(vec.begin(),vec.end(),cmp);
		///create new graph by minimum spanning tree
		int nowSize = 1,index = 0;
		while(nowSize < n && index < m){
			int u = vec[index].u,v = vec[index].v,w = vec[index].w;
			int headU = findHead(u),headV = findHead(v);
			if(headU != headV){
				newVec[u].push_back(make_pair(v,w));
				newVec[v].push_back(make_pair(u,w));
				Head[headU] = Head[headV];
				nowSize++;
			}
			index++;
		}
		if(nowTT != 1){
			printf("\n");
		} 
		printf("Case #%d\n",nowTT);
		while(q--){
			scanf("%d %d",&first,&last);
			///BFS to find shortest path
			for(int i=1;i<=n;i++){
				chk[i] = false;
			}
			minAns = -1;
			dfs(first,last,0);
			if(minAns == -1){
				printf("no path\n");
			}
			else{
				printf("%d\n",minAns);
			}
		}
		nowTT++;
	}
	return 0;
}
void dfs(int first,int last,int now){
	chk[first] = true;
	if(first == last){
		minAns = now;
		return;
	}
	else{
		for(int i=0;i<newVec[first].size();i++){
			if(chk[newVec[first][i].first] == false){
				dfs(newVec[first][i].first,last,max(newVec[first][i].second,now));
			}
		}
	}
}