#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
struct cmp{
	bool operator()(const pair<int,int>&p1,const pair<int,int>&p2){
		return p1.second > p2.second;
	}
};
int main(){
	int T;
	scanf("%d",&T);
	for(int x = 1;x<=T;x++){
		vector< pair<int,int> > vec[60000];
		int n,m,s,t,uu,vv,ww;
		scanf("%d %d %d %d",&n,&m,&s,&t);
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&uu,&vv,&ww);
			vec[uu].push_back(make_pair(vv,ww));
			vec[vv].push_back(make_pair(uu,ww));
		}
		int dist[60000] = {0};
		///reset dist
		for(int i=0;i<=n;i++){
			dist[i] = 12345678;
		}
		dist[s] = 0;
		priority_queue< pair<int,int> ,vector< pair<int,int> > ,cmp> pq;
		pq.push(make_pair(s,0));
		while(!pq.empty()){
			int u = pq.top().first;
			pq.pop();
			for(int i=0;i<vec[u].size();i++){
				int v = vec[u][i].first;
				int w = vec[u][i].second;
				if(dist[u] + w < dist[v]){
					dist[v] = dist[u] +w;
					pq.push(make_pair(v,dist[v]));
				}
			}
		}
		if(dist[t] == 12345678){
			printf("Case #%d: unreachable\n",x);
		}
		else{
			printf("Case #%d: %d\n",x,dist[t]);
		}
	}

	return 0;
}