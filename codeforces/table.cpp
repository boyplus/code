#include <cstdio>
int arr[11][11];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		arr[i][1] = 1;
		arr[1][i] = 1;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			arr[i][j] = arr[i-1][j] + arr[i][j-1];
		}
	}
	printf("%d\n",arr[n][n]);
	return 0;
}