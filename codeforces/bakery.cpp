#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int Min[100010];
class graph{
public:
	int u,v,l;
	graph(int u,int v,int l){
		this->u = u;
		this->v = v;
		this->l = l;
	}
};
bool chk[100010];
vector<graph> vec;
bool cmp(const graph& left,const graph& right){
	return left.l < right.l;
}
int main(){
	int n,m,k,u,v,l,temp;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		Min[i] = 1e9+7;
	}
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&l);
		vec.push_back(graph(u,v,l));
	}
	for(int i=0;i<k;i++){
		scanf("%d",&temp);
		chk[temp] = true;
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i=0;i<vec.size();i++){
		int u = vec[i].u;
		int v = vec[i].v;
		int l = vec[i].l;
		if(chk[u] && chk[v] == false){
			printf("%d\n",l);
			return 0;
		}
		else if(chk[u] == false && chk[v]){
			printf("%d\n",l);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}