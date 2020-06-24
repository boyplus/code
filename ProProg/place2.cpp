#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
long long Head[200001];
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
long long findHead(long long u){
	if(Head[u] == u){
		return u;
	}
	return Head[u] = findHead(Head[u]);
}
int main(){
	long long n,m,tu,tv,td,nowSize = 1,index = 0,sum=0;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%lld %lld %lld",&tu,&tv,&td);
		vec.push_back(graph(tu,tv,td));
	}
	///get default Head
	for(int i=1;i<=n;i++){
		Head[i] = i;
	}
	sort(vec.begin(),vec.end(),cmp);
	while(nowSize < n){
		long long u = vec[index].u;
		long long v=  vec[index].v;
		long long headU = findHead(u);
		long long headV = findHead(v);
		if(headU != headV){
			sum = sum + vec[index].dist;
			Head[headV] = headU;
			nowSize++;
		}
		index++;
	}
	printf("%lld\n",sum - n+1);
	return 0;
}