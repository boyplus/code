#include <cstdio>
#include <limits.h>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long arr[200][200] = {0},qsum[200][200] = {0};
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%lld",&arr[i][j]);
				arr[i][j+n] = arr[i][j];
				arr[i+n][j] = arr[i][j];
				arr[i+n][j+n] = arr[i][j];
			}
		}
		///create qsum
		for(int i=1;i<=n*2;i++){
			for(int j=1;j<=n*2;j++){
				qsum[i][j] = qsum[i][j-1] + arr[i][j];
			}
		}
		/*printf("Array : ---------------\n");
		for(int i=1;i<=n*2;i++){
			for(int j=1;j<=n*2;j++){
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
		printf("Qsum : ---------------\n");
		for(int i=1;i<=n*2;i++){
			for(int j=1;j<=n*2;j++){
				printf("%d ",qsum[i][j]);
			}
			printf("\n");
		}*/
		long long Max = INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n*2;j++){
				long long allSum = 0,first = 1;
				for(int k=1;k<=n*2;k++){
					long long nowSize = j-i+1;
					long long nowSize2 = k - first +1;
					if(nowSize > n || nowSize2 > n){
						continue;
					}
					//printf("(%d,%d,%d) size = %d %d\n",i,j,k,nowSize,nowSize2);
					long long sumNow = qsum[k][j] - qsum[k][i-1];
					allSum = allSum + sumNow;
					if(allSum > Max){
						Max = allSum;
					}
					if(allSum < 0){
						first = k;
						allSum = 0;
					}
				}
			}
		}
		printf("%lld\n",Max);
	}
	return 0;
}