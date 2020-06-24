#include <cstdio>
int arr[4];
int main(){
	int min = 1e9;
	for(int i=0;i<4;i++){
		scanf("%d",&arr[i]);
		if(i!=1){
			if(arr[i] < min){
				min = arr[i];
			}
		}
	}
	int sum = min*256;
	arr[0]-=min;
	int num = arr[0];
	if(arr[1] < num){
		num = arr[1];
	}
	sum = sum +(32*num);
	printf("%d\n",sum);
	return 0;
}