#include <cstdio>
long long mem[40][40];
long long cnk(long long n,long long k){
	if(n==k || k==0){
		return 1;
	}
	long long num1;
	if(mem[n-1][k-1]){
		num1 = mem[n-1][k-1];
	}
	else{
		mem[n-1][k-1] = num1 = cnk(n-1,k-1);
	}
	long long num2;
	if(mem[n-1][k]){
		num2 = mem[n-1][k];
	}
	else{
		mem[n-1][k] = num2 = cnk(n-1,k);
	}
	return num1+num2;
}
int main(){
	long long n,k;
	scanf("%lld %lld",&n,&k);
	long long ans = cnk(n,k);
	printf("%lld\n",ans);
	return 0;
}