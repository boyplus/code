#include <cstdio>
int num[1001][1001];
int main(){
	int m,n,k,max=-1;
	scanf("%d %d %d",&m,&n,&k);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&num[i][j]);
			num[i][j]+=num[i][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			num[j][i]+=num[j-1][i];
		}
	}
	for(int i=k;i<=m;i++){
		for(int j=k;j<=n;j++){
			int temp = num[i][j] - num[i][j-k] - num[i-k][j] + num[i-k][j-k];
			if(temp > max){
				max = temp;
			}
		}
	}
	printf("%d\n",max);
	return 0;
}