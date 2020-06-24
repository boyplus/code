#include <cstdio>
#include <cstring>
using namespace std;
long long dp[2000001],num[2000001];
long long mod = 1e9+7;
long long rec(int n){
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return dp[1] = 1;
	}
	long long a=0,b=0;
	if(dp[n-1]!=0){
		a = dp[n-1];
	}
	else{
		dp[n-1] = a = rec(n-1);
	}
	if(dp[n-2]!=0){
		b = dp[n-2];
	}
	else{
		dp[n-2] = b = rec(n-2);
	}
	return dp[n] = (dp[n-1]+dp[n-2]+num[n])%mod;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k,a,b;
		scanf("%d %d",&n,&k);
		for(int i=0;i<k;i++){
			scanf("%d %d",&a,&b);
			num[a] = b;
		}
		long long ans = rec(n);
		printf("%lld\n",ans%mod);
		memset(dp,0,sizeof(dp));
		memset(num,0,sizeof(num));
	}
	return 0;
}
/*
5
3 0
5 1
4 1
8 2
7 2
8 3
9 2
7 2
8 3
9 2
7 2
8 3
*/