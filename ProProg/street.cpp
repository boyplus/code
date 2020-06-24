#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define ll long long
using namespace std;
ll Head[200001];
class graph{
public:
	ll u,v,w;
	graph(ll u,ll v,ll w){
		this->u = u;
		this->v = v;
		this->w = w;
	}
};
bool cmp(const graph& left,const graph& right){
	return left.w < right.w;
}
ll findHead(ll u){
	if(u == Head[u]){
		return u;
	}
	return Head[u] = findHead(Head[u]);
}
int main(){
	while(1){
		vector<graph> vec;
		long long n,m,tu,tv,td,sum = 0,nowSize = 1,index = 0,ans=0;
		scanf("%lld %lld",&n,&m);
		if(n == 0 && m == 0){
			return 0;
		}
		///clear
		memset(Head,0,sizeof(Head));
		for(int i=1;i<=n;i++){
			Head[i] = i;
		}
		for(int i=0;i<m;i++){
			scanf("%lld %lld %lld",&tu,&tv,&td);
			sum = sum+td;
			vec.push_back(graph(tu,tv,td));
		}
		sort(vec.begin(),vec.end(),cmp);
		while(nowSize < n && index < m){
			ll u = vec[index].u;
			ll v = vec[index].v;
			ll hu = findHead(u);
			ll hv = findHead(v);
			if(hu != hv){
				Head[hu] = Head[hv];
				ans = ans + vec[index].w;
				nowSize++;
			}
			index++;
		}
		printf("%lld\n",sum - ans);
	}
	return 0;
}