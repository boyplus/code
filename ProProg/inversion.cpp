#include <cstdio>
long long ans = 0;
void mergeSort(int*,int,int);
void merge(int,int,int,int);
int main(){
	while(1){
		ans = 0;
		int arr[500001] = {0},n;
		scanf("%d",&n);
		if(n == 0){
			return 0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
		}
		mergeSort(arr,1,n);
		printf("%lld\n",ans);
	}
	return 0;
}
void merge(int *arr,int left,int mid,int right){
	int t[500001];
	int i = left,j = mid+1;
	for(int k=left;k<=right;k++){
		if(i > mid){
			t[k] = arr[j++];
			continue;
		}
		if(j > right){
			t[k] = arr[i++];
			continue;
		}
		if(arr[i] <= arr[j]){
			t[k] = arr[i++];
		}
		else{
			t[k] = arr[j++];
			ans = ans + (mid-i+1);
		}
	}
	for(int k=left;k<=right;k++){
		arr[k] = t[k];
	}
}
void mergeSort(int *arr,int left,int right){
	if(left >= right){
		return;
	}
	int mid = (left+right)/2;
	mergeSort(arr,left,mid);
	mergeSort(arr,mid+1,right);
	merge(arr,left,mid,right);
}
