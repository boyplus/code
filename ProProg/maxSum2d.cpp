#include <cstdio>
#include <limits.h>
int arr[200][200],qsum[200][200];
int main(){
	int n,Max = INT_MIN;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&arr[i][j]);
			///calculate qsum Row
			qsum[i][j] = qsum[i][j-1] + arr[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sumNow = 0;
			for(int k=1;k<=n;k++){	
				int sumRow = qsum[k][j] - qsum[k][i-1];
				sumNow = sumNow + sumRow;
				if(sumNow > Max){
					Max = sumNow;
				}
				if(sumNow < 0){
					sumNow = 0;
				}
			}
		}
	}
	printf("%d\n",Max);
	return 0;
}