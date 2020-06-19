#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1005;
int arr[maxn];
int main(){
	int n,q,a,b;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		arr[i]+=arr[i-1];
	}
	while(q--){
		scanf("%d %d",&a,&b);
		int ans = arr[b] - arr[a-1];
		printf("%d\n",ans);
	}
    return 0;
}