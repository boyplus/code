#include <cstdio>
int num[1010][1010],dp[1010][1010],mem[1010][1010];
int Max(int a,int b){
	if(a>b)
		return a;
	return b;
}
long long find(int row,int col){
	if(mem[row][col]){
		return mem[row][col];
	}
	if(row == 1){
		return 1;
	}
	int want = dp[row][col] - num[row][col];
	if(row%2 == 0){
		int a=0,b=0;
		if(dp[row-1][col] == want){
			a = find(row-1,col);
		}
		if(dp[row-1][col+1] == want){
			b = find(row-1,col+1);
		}
		return mem[row][col] = a+b;
	}
	else{
		int a=0,b=0;
		if(dp[row-1][col-1] == want){
			a = find(row-1,col-1);
		}
		if(dp[row-1][col] == want){
			b = find(row-1,col);
		}
		return mem[row][col] = a+b; 
	}
	return 0;
}
int main(){
	int m,n,max=0;
	long long count=0;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&num[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2){
				dp[i][j] = num[i][j]+ Max(dp[i-1][j-1],dp[i-1][j]);
			}
			else{
				dp[i][j] = num[i][j]+Max(dp[i-1][j],dp[i-1][j+1]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dp[m][i] > max){
			max = dp[m][i];
		}
	}
	for(int i=1;i<=n;i++){
		if(dp[m][i] == max){
			count+=find(m,i);
		}
	}
	printf("%d %lld\n",max,count);
	return 0;
}