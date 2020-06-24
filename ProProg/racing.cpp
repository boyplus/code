#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
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
bool cmp(const graph& left,const graph& right){
	return left.w > right.w;
}
int Head[200000];
vector<graph> vec;
int findHead(int u){
	if(u == Head[u]){
		return u;
	}
	return Head[u] = findHead(Head[u]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,tu,tv,td,nowSize = 1,index = 0,sumAll=0,sumTemp = 0;
		scanf("%d %d",&n,&m);
		///reset
		vec.clear();
		memset(Head,0,sizeof(Head));
		for(int i=1;i<=n;i++){
			Head[i] = i;
		}
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&tu,&tv,&td);
			vec.push_back(graph(tu,tv,td));
			sumAll+=td;
		}
		sort(vec.begin(),vec.end(),cmp);
		while(nowSize < n && index < m){
			int u = vec[index].u;
			int v = vec[index].v;
			int hu = findHead(u);
			int hv = findHead(v);
			if(hu != hv){
				Head[hu] = Head[hv];
				nowSize++;
				sumTemp += vec[index].w;
			}
			index++;

		}
		printf("%d\n",sumAll-sumTemp);
	}
	scanf("%d",&T);
	return 0;
}