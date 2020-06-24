#include <cstdio>
long long arr[20000],n,mem[20000];
long long max(long long a,long long b){
	if(a>b){
		return a;
	}
	return b;
}
long long rec(long long now){
	if(now >= n){
		return 0;
	}
	long long num1 = 0,num2 = 0;
	if(mem[now]!=0){
		num1 = mem[now];
	}
	else{
		num1 = arr[now] + rec(now+2);
	}
	if(mem[now+1]!=0){
		num2 = mem[now+1];
	}
	else{
		num2 = rec(now+1);
	}
	return mem[now] = max(num1,num2);
}
int main(){
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i]);
	}
	long long ans = rec(0);
	printf("%lld\n",ans);
	return 0;
}