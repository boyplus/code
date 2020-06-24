#include <cstdio>
long long arr[2000],last,dp[1000][1000];
long long max(long long a,long long b){
	if(a > b){
		return a;
	}
	return b;
}
long long rec(long long left,long long right,long long round){
	if(dp[left][right] !=0){
		return dp[left][right];
	}
	if(left > right || round >= last){
		return 0;
	}
	else{
		///player 1
		if(round%2 == 0){
			long long a = arr[left] + rec(left+1,right,round+1);
			long long b = arr[right] + rec(left,right-1,round+1);
			return dp[left][right] = max(a,b);
		}
		else{
			long long a = rec(left+1,right,round+1);
			long long b = rec(left,right-1,round+1);
			return dp[left][right] = max(a,b);
		}
	}
}
int main(){
	long long n;
	scanf("%lld",&n);
	for(int i=1;i<=n*2;i++){
		scanf("%lld",&arr[i]);
	}
	last = n*2;
	long long ans = rec(1,last,0);
	printf("%lld\n",ans);
	return 0;
}