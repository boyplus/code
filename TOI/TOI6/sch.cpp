#include <cstdio>
int s[500000],e[500000];
int dp[500010],mem[500050];
bool chk[500010];
int main(){
	int n,k,m,w,maxT=0;
	scanf("%d %d %d",&n,&k,&m);
	for(int i=0;i<n;++i){
		scanf("%d %d",&s[i],&e[i]);
		mem[s[i]] = e[i];
		if(e[i] > maxT){
			maxT = e[i];
		}
	}
	//quick sum
	for(int i=0;i<n;++i){
		++dp[s[i]];
		--dp[e[i]+1];
	}
	for(int i=1;i<=maxT;++i){
		if(dp[i-1]+dp[i] <= k){
			dp[i] = dp[i-1]+dp[i];
		}
		else{
			chk[i] = true;
			dp[i] = dp[i-1];
			dp[mem[i]+1]++;
		}
	}
	while(m--){
		scanf("%d",&w);
		int num = s[w-1];
		if(!chk[num]){
			printf("Y ");
		}
		else{
			printf("N ");
		}
	}
	printf("\n");
	return 0;
}