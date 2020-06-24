#include <cstdio>
#include <algorithm>
using namespace std;
long long num[1000000];
int main(){
	long long n,m;
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&num[i]);
	}
	long long left = 1,right = 1000000000005,ans=1000000000005;
	while(left <= right){
		long long mid = (left+right)/2;
		///find sum
		long long sum = 0;
		for(int i=0;i<n;++i){
			sum = sum + (mid/num[i]);
			if(sum >= m){
				break;
			}
		}
		if(sum >= m){
			ans = mid;
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}