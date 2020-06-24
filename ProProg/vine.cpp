#include <cstdio>
using namespace std;
int arr[1000][1000];
int main(){
	while(1){
		int m,n,q,low,high;
		scanf("%d %d",&m,&n);
		if(m == 0 && n == 0){
			return 0;
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&arr[i][j]);
			}
		}
		scanf("%d",&q);
		while(q--){
			int Max = 0;
			scanf("%d %d",&low,&high);
			for(int i=1;i<=m;i++){
				///binary search Each Row
				int left = 1,right = n;
				bool can = false;
				int ans = 0,length = 0;
				while(left <= right){
					int mid = (left+right)/2;
					if(arr[i][mid] >= low){
						can = true;
						right = mid-1;
						ans = mid;
					}
					else{
						left = mid+1;
					}
				}
				if(can == false){
					continue;
				}
				if(arr[i][ans] > high || arr[i][ans] < low){
					continue;
				}
				int tempAns = ans;
				for(int j=i;j<=m && tempAns <= n;j++){
					if(arr[j][tempAns] <= high){
						length++;
					}
					else{
						break;
					}
					tempAns++;
				}
				if(length > Max){
					Max = length;
				}
			}
			printf("%d\n",Max);
		}
		printf("-\n");
	}
	return 0;
}