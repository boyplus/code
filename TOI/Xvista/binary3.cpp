#include <cstdio>
int arr[100000];
int main(){
	int n,q,want;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	while(q--){
		scanf("%d",&want);
		///binary serach
		int left = 0,right = n,index=-1;
		while(left<=right){
			int mid = (left+right)/2;
			if(arr[mid] == want){
				index = mid;
				break;
			}
			if(arr[mid] > want){
				right = mid-1;
			}
			else{
				left = mid+1;
			}
		}
		if(left >= n){
			left = n-1;
		}
		if(right >= n){
			right = n-1;
		}
		if(right == -1){
			printf("-1\n");
			continue;
		}
		int mid = (left+right)/2;
		while(arr[mid+1] == want){
			mid++;
		}
		printf("%d\n",mid);
	}
	return 0;
}