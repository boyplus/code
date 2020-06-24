#include <cstdio>
long long dp[50][50][50];
int main(){
	int n,m,ak;
	scanf("%d %d %d",&n,&m,&ak);
	dp[1][1][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<=ak;k++){
				dp[i+1][j+1][k] += dp[i][j][k];
				dp[i+1][1][k+1] += dp[i][j][k];
			}
		}
	}
	long long ans = 0;
	for(int i=1;i<=m;i++){
		ans+=dp[n][i][ak];
	}
	printf("%lld\n",ans);
	return 0;
}