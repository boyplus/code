#include <cstdio>
int arr[100000];
int main(){
	int n,k,ans=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<n;i++){
		if(arr[i] - arr[i-1] <= k){
			ans++;
		}
		else{
			ans = 0;
		}
	}
	printf("%d\n",ans+1);
	return 0;
}