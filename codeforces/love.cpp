#include <cstdio>
#include <limits.h>
int arr[1000];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int min = INT_MAX,max = INT_MIN,count=0;
	min = arr[0];
	max = arr[0];
	for(int i=1;i<n;i++){
		if(arr[i] < min){
			min = arr[i];
			count++;
		}
		if(arr[i] > max){
			max = arr[i];
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}