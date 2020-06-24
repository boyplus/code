#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
vector<ll> vec[60];

bool visited[60];
int main(){
	ll n,m,a,b;
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%lld %lld",&a,&b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	ll now = 0,index=0,ans=1;
	for(int i=1;i<=n;i++){
		if(visited[i] == false && vec[i].empty() == false){
			now = 0;
			queue<ll> q;
			q.push(i);
			visited[i] = true;
			while(!q.empty()){
				ll v = q.front();
				q.pop();
				if(now == 0){
					now = 1;
				}
				else{
					now*=2;
				}
				for(int j=0;j<vec[v].size();j++){
					if(visited[vec[v][j]] == false){
						visited[vec[v][j]] = true;
						q.push(vec[v][j]);
					}
				}
			}
			ans = ans * now;
		}
	}
	
	printf("%lld\n",ans);
	return 0;
}