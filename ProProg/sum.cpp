#include <cstdio>
#include <limits.h>
#include <algorithm>
#include <cstring>
using namespace std;
bool chk[10000000];
int arr[20000];
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		int Min = INT_MAX,want,ans1=0,ans2=0;
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
			chk[arr[i]] = true;
		}
		scanf("%d",&want);
		sort(arr,arr+n);
		for(int i=0;i<n;i++){
			int diff = want - arr[i];
			if(diff >= 0){
				if(chk[diff] == true){
					int temp = arr[i] - diff;
					if(temp < 0){
						temp = temp*-1;
					}
					if(temp < Min){
						ans1 = arr[i];
						ans2 = diff;
						Min = temp;
					}
				}
			}
		}
		if(ans1 > ans2){
			int temp = ans1;
			ans1 = ans2;
			ans2 = temp;
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",ans1,ans2);
		memset(chk,false,sizeof(chk));
	}
	return 0;
}