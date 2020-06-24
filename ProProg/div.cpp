#include <cstdio>
#include <cstring>
int n,arr[101],dp[50001];
int min(int a,int b){
	if(a < b){
		return a;
	}
	return b;
}
int rec(int now,int sum1,int sum2){
	if(now == 0){
		int diff = sum1 - sum2;
		if(diff < 0){
			diff = diff*-1;
		}
		return diff;
	}
	if(dp[sum1] !=0 ){
		return dp[sum1];
	}
	int a = rec(now-1,sum1+arr[now],sum2);
	int b = rec(now-1,sum1,sum2+arr[now]);
	return dp[sum1] = min(a,b);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int sum = 0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
		}
		int ans = rec(n,0,0);
		printf("%d\n",ans);
		memset(dp,0,sizeof(dp));
	}
	return 0;
}