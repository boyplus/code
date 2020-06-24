#include <cstdio>
int main(){
	long long f1=1,f2=1,now=1;
	int n;
	scanf("%d",&n);
	for(int i=2;i<n;i++){
		now = f1+f2;
		f1 = f2;
		f2 = now;
	}
	printf("%lld\n",now);
	return 0;
}