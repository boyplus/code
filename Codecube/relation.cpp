#include <cstdio>
long long dp[2000001];
long long mod = 1e9+7;
int main(){
	///first calculate
	dp[1] = 1;
	for(int i=2;i<=2000000;i++){
		dp[i] = (dp[i-1]+dp[i-2])%mod;
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k,a,b;
		scanf("%d %d",&n,&k);
		long long ans = dp[n];
		for(int i=0;i<k;i++){
			scanf("%d %d",&a,&b);
			ans = (ans+((dp[n-a+1])*b)%mod)%mod;
		}
		printf("%lld\n",ans%mod);
	}
	return 0;
}