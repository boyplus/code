#include <cstdio>
#include <string.h>
char A[600],B[600];
int dp[600][600];
int max(int a,int b,int c){
	int Max = a;
	if(b > Max)
		Max = b;
	if(c > Max)
		Max = c;
	return Max;
}
int main(){
	scanf("%s %s",A,B);
	int l1 = strlen(A);
	int l2 = strlen(B);
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
			dp[i][j] = max(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]+(A[i-1] == B[j-1]));
		}
	}
	printf("%d\n",dp[l1][l2]);
	return 0;
}