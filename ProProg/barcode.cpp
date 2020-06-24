#include <cstdio>
#include <cstring>
long long dp[60][60][60],n,m,k;
long long min(long long a,long long b){
	if(a < b){
		return a;
	}
	return b;
}
long long rec(long long i,long long j,long long a){
	if(j > i){
		return 0;
	}
	if((i == j) && a>0){
		return 0;
	}
	if((i == j) && a==0){
		return 1;
	}
	if(dp[i][j][a] !=-1 ){
		return dp[i][j][a];
	}
	if(j > 1){
		return dp[i][j][a] = rec(i-1,j-1,a);
	}
	else if(j == 1){
		long long lim = min(i-1,m),ret = 0;
		for(int x=1;x<=lim;++x){
			ret += rec(i-1,x,a-1);
		}
		dp[i][j][a] = ret;
	}
	return dp[i][j][a];
}
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%lld %lld %lld",&n,&m,&k);
	long long ans = 0;
	for(int z=1;z<=m;++z){
		ans = ans + (rec(n,z,k));
	}
	printf("%lld\n",ans);
	return 0;
}