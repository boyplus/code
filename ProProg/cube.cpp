#include <cstdio>
long long n,dp[30000][30];
long long pow3(long long a){
	return a*a*a;
}
long long rec(long long num,long long last){
	if(dp[num][last] !=0){
		return dp[num][last];
	}
	if(num == 0){
		return 1;
	}
	long long sum = 0;
	for(int i=last;i<=22;i++){
		long long temp = pow3(i);
		if(temp <= num){
			sum = sum + rec(num - temp,i);
		}
		else{
			break;
		}
	}
	return dp[num][last] = sum;
}
int main(){
	while(scanf("%lld",&n) != EOF){
		long long ans = rec(n,1);
		printf("%lld\n",ans); 
	}
	return 0;
}