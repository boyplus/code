#include <cstdio>
int main(){
	long long a,b,count=0;
	scanf("%lld %lld",&a,&b);
	while(a<=b){
		a*=3;
		b*=2;
		count++;
	}
	printf("%lld\n",count);
	return 0;
}