#include <cstdio>
long long arr[500000],sum[500000];
long long max(long long a,long long b){
	if(a>b){
		return a;
	}
	return b;
}
int main(){
	long long n,k,MAX = -1e18;
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	for(int i=1;i<k;i++){
		sum[i] = sum[i-1]+arr[i];
	}
	for(int i=k;i<=n;i++){
		sum[i] = sum[i-1]+arr[i]-arr[i-k];
	}
	long long temp = 0,num=0;
	for(int i=k;i<=n;i++){
		num = max(temp+arr[i],sum[i]);
		if(num > MAX){
			MAX = num;
		}
		temp = num;
	}
	printf("%lld\n",MAX);
	return 0;
}