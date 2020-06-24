#include <cstdio>
#include <algorithm>
using namespace std;
int x1[2000],x2[2000];
int main(){
	long long sum = 0;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x1[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&x2[i]);
	}
	sort(x1,x1+n);
	sort(x2,x2+n);
	for(int i=0;i<n;i++){
		long long diff = x1[i] - x2[i];
		if(diff < 0){
			diff*=-1;
		}
		sum+=diff;
	}
	printf("%lld\n",sum);
	return 0;
}