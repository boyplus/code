#include <cstdio>
long long power(long long x,long long y,long long n){
	if(y==0){
		return 1;
	}
	long long p = power(x,y/2,n);
	if(y%2){
		return (p*p*x)%n;
	}
	else{
		return (p*p)%n;
	}
}
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long x,y,n;
		scanf("%lld %lld %lld",&x,&y,&n);
		long long ans = power(x,y,n);
		printf("%lld\n",ans%n);
	}
	return 0;
}