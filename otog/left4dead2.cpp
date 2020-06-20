#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100005;
long long arr[maxn];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i]);
	}
	long long left = 0,right = 2e18;
	long long ans = right;
	while(left<=right){
		long long mid = (left+right)/2;
		long long sum = 0;
		for(int i=0;i<n;i++){
			sum+=(mid/arr[i]);
			if(sum >= m){
				break;
			}
		}
		if(sum >= m){
			ans = mid;
			right = mid-1;
		} else{
			left = mid+1;
		}
	}
	printf("%lld\n",ans);
    return 0;
}