#include <cstdio>
#include <limits.h>
long long n,m,coin[30],mem[11000],answer = INT_MAX;
long long rec(long long money){
	if(money == 0){
		return 1;
	}
	if(money < 0){
		return 0;
	}
	if(mem[money] !=0 ){
		return mem[money];
	}
	long long  Min = INT_MAX;
	for(int i=0;i<n;i++){
		long long  temp = INT_MAX;
		if(money-coin[i] >= 0){
			temp = rec(money - coin[i])+1;
		}
		if(temp < Min){
			Min = temp;
		}
	}
	return mem[money] = Min;
}
int main(){
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&coin[i]);
	}
	long long ans = rec(m);
	printf("%lld\n",ans-1);
	return 0;
}