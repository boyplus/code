#include <cstdio>
int arr[100];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	if(n%2 == 0){
		printf("No\n");
	}
	else{
		if(arr[0]%2 == 0 || arr[n-1]%2 == 0){
			printf("No\n");
		}
		else{
			printf("Yes\n");
		}
	}
	return 0;
}