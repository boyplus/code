#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1005,maxm = 1005;
int arr[maxn][maxm],sumRow[maxn],sumCol[maxm];
int main(){
	int n,m,a,b,q;
	scanf("%d %d",&n,&m);
	scanf("%d",&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&arr[i][j]);
			sumRow[i]+=arr[i][j];
		}
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			sumCol[i]+=arr[j][i];
		}
	}

	while(q--){
		scanf("%d %d",&a,&b);
		int ans = sumRow[a]+sumCol[b]-arr[a][b];
		printf("%d\n",ans);
	}
	return 0;
}