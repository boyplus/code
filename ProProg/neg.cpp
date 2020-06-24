#include <cstdio>
#include <vector>
using namespace std;
class graph{
public:
	int u,v,w;
	graph(int u,int v,int w){
		this->u = u;
		this->v = v;
		this-> w = w;
	}
};
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		vector<graph> vec;
		int n,m,uu,vv,ww;
		scanf("%d %d",&n,&m);
		vec.clear();
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&uu,&vv,&ww);
			vec.push_back(graph(uu,vv,ww));
		}
		int dist[3000] = {0};
		for(int i=0;i<=n;i++){
			dist[i] = 1e9;
		}
		dist[0] = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int u = vec[j].u;
				int v = vec[j].v;
				int w = vec[j].w;
				if(dist[u] != 1e9){
					if(dist[u] + w < dist[v]){
						dist[v] = dist[u]+w;
					}
				}
			}
		}
		bool chk = false;
		for(int i=0;i<m;i++){
			int u = vec[i].u;
			int v = vec[i].v;
			int w = vec[i].w;
			if(dist[u] != 1e9){
				if(dist[u] + w < dist[v]){
					chk = true;
					break;
				}
			}
			if(chk){
				break;
			}
		}
		if(chk == true){
			printf("possible\n");
		}
		else{
			printf("not possible\n");
		}
	}
	return 0;
}