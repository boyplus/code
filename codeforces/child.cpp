#include <cstdio>
#include <vector>
using namespace std;
vector<>
int main(){
	int n,m,a,b;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&cost[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	return 0;
}