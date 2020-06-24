#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;
long long Head[3000];
long long findHead(long long u){
	if(u == Head[u]){
		return u;
	}
	return Head[u] = findHead(Head[u]);
}
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

int main(){
	long long n,m,tu,tv,td,first,last,people,mm = INT_MAX;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%lld %lld %lld",&tu,&tv,&td);
		vec.push_back(graph(tu,tv,td));
		if(td < mm){
			mm = td;
		}
	}
	scanf("%lld %lld %lld",&first,&last,&people);
	///set default head
	for(int i=1;i<=n;i++){
		Head[i] = i;
	}
	sort(vec.begin(),vec.end(),cmp);
	///After sort
	long long ans = mm;
	for(int i=0;i<m;i++){
		ans = vec[i].dist;
		long long hu = findHead(vec[i].u);
		long long hv = findHead(vec[i].v);
		Head[hu] = Head[hv];
		if(findHead(first) == findHead(last)){
			break;
		}
	}
	ans--;
	float a = ceil((people)/float(ans));
	long long ll = a;
	printf("%lld\n",ll);
	return 0;
}