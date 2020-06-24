#include <cstdio>
#include <cstring>
using namespace std;
int arr[2001],n;
int dp[2001][2001];
bool chk[2001][2001];
int Fmin(int,int,int);
int rec(int index,int sum){
	if(sum == 0 || index <= 0){
		return sum;
	}
	else if(sum < 0){
		return 1e9;
	}
	if(chk[index][sum]){
		return dp[index][sum];
	}
	for(int i=index;i>0;i--){
		return dp[index][sum] = Fmin(rec(index,sum-arr[i]),rec(index-1,sum-arr[i]),rec(index-1,sum));
		chk[index][sum] = true;
	}
	return 1e9;
	
}
int Fmin(int a,int b,int c){
	int Min = 1e9;
	if(a >=0 && a < Min)
		Min = a;
	if(b>=0 && b < Min)
		Min = b;
	if(c>=0 && c<Min)
		Min = c;
	return Min;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int k;
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
			memset(chk[i],false,sizeof(chk[i]));
			memset(dp[i],0,sizeof(dp[i]));
		}
		int ans = rec(n,k);
		printf("%d\n",k - ans);
	}
	return 0;
}