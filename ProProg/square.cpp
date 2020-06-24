#include <cstdio>
using namespace std;
long long dp[20000];
long long min(long long a,long long b){
	if(a < b){
		return a;
	}
	return b;
}
long long rec(long long num){
	if(dp[num] != 0){
		return dp[num];
	}
	int Min = num;
	if(num <= 3){
		return num;
	}
	else{
		for(int i=1;i<=num;i++){
			int temp = i*i;
			if(temp > num){
				break;
			}
			Min = min(Min,1+rec(num - temp));
		}
	}
	return dp[num] = Min;
}
int main(){
	long long T,num;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&num);
		long long ans = rec(num);
		printf("%lld\n",ans);
	}
	return 0;
}