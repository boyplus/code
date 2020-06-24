#include <cstdio>
#include <algorithm>
using namespace std;
long long arr[200001],qsum[200001];
int main(){
	long long n,x,ans=0,k=0;
	scanf("%lld %lld",&n,&x);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
		qsum[i] = qsum[i-1]+arr[i];
	}
	for(long long i=1;i<=n;i++){
		long long sumNow = qsum[i] + i*(i*(i+1)/2);
		if(sumNow <= x){
			k = i;
			ans = sumNow;
		}
		else{
			break;
		}
	}
	printf("%lld %lld\n",k,ans);
	return 0;
}