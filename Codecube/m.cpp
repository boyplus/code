#include <cstdio>
#include <cstring>
#include <math.h>
using namespace std;
int dp[33][100008];
int arr[1001],n,k;
int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
int rec(int now,int sum){
	if(now == 0){
		return sum%k;
	}
	int a = 0,b=0;
	int temp = sqrt(now)-1,newSum = (sum+arr[now])%k;
	if(dp[temp][newSum] != 0){
		a = dp[temp][newSum];
	}
	else{
		dp[temp][newSum] = a = rec(now-1,newSum);
	}
	int sumMod = sum%k;
	if(dp[temp][sumMod] != 0){
		b = dp[temp][sumMod];
	}
	else{
		dp[temp][sumMod] = b = rec(now-1,sumMod);
	}
	return max(a,b);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
		}
		int ans = rec(n,0);
		printf("Case #%d: %d\n",tt,ans);
		memset(dp,0,sizeof(dp));
	}
	return 0;
}