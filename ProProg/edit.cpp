#include <cstdio>
#include <string.h>
int min(int a,int b,int c){
	int Min = a;
	if(b < Min){
		Min = b;
	}
	if(c < Min){
		Min = c;
	}
	return Min;
}
int dp[100][100];
int main(){
	char A[100] = "",B[100] = "";
	scanf("%s %s",A,B);
	int l1 = strlen(A);
	int l2 = strlen(B);
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
			dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1);
		}
	}
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	return 0;
}