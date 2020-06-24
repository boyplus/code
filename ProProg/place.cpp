#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class graph{
public:
	long long u;
	long long v;
	long long dist;
	graph(long long u,long long v,long long dist){
		this->u = u;
		this->v = v;
		this->dist = dist;
	}
};
vector<graph> vec;
bool cmp(const graph& left,const graph& right){
	return left.dist > right.dist;
}
long long parent[1000001],high[1000001];
int main(){
	long long n,m,tu,tv,td,index=0,sum=0,nowSize = 1;
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%lld %lld %lld",&tu,&tv,&td);
		vec.push_back(graph(tu,tv,td));
	}
	///sort graph with max dist to min dist
	sort(vec.begin(),vec.end(),cmp);
	///set defalut parent for each node
	for(int i=1;i<=n;i++){
		parent[i] = i;
	}
	while(nowSize < n){
		long long u = vec[index].u;
		long long v = vec[index].v;
		long long dist = vec[index].dist;
		///find parent of node
		while(u != parent[u]){
			u = parent[u];
		}
		while(v != parent[v]){
			v = parent[v];
		}
		///not have same parent
		if(u != v){
			if(high[u] > high[v]){
				parent[v] = u;
			}
			else{
				parent[u] = v;
				if(high[u] == high[v]){
					high[v]++;
				}
			}
			nowSize++;
			sum = sum + vec[index].dist;
		}
		index++;
	}
	printf("%lld\n",sum-n+1);
	return 0;
}