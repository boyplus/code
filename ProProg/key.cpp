#include <cstdio>
#include <string.h>
#include <cstring>
int length,l1,l2;
bool dp[3000][3000],mem[3000][3000];
char s1[3000],s2[3000],str[3000];
bool rec(int i,int j,int now){
	if(mem[i][j]){
		return dp[i][j];
	}
	if(now >= length){
		return true;
	}
	if(str[now] == 'A'){
		if(i < l1 && j < l2){
			if(s1[i] == 'A' && s2[j] == 'B'){
				mem[i][j] = true;
				return dp[i][j] = rec(i+1,j,now+1);
			}
			else if(s1[i] == 'B' && s2[j] == 'A'){
				mem[i][j] = true;
				return dp[i][j] = rec(i,j+1,now+1);
			}
			else if(s1[i] == 'A' && s2[j] == 'A'){
				mem[i][j] = true; 
				return dp[i][j] = (rec(i+1,j,now+1) || rec(i,j+1,now+1));
			}
			else{
				mem[i][j] = true;
				return dp[i][j] = false;
			}
		}
		else if(i >= l1 && j < l2){
			if(s2[j] == 'A'){
				mem[i][j] = true;
				return dp[i][j] = rec(i,j+1,now+1);
			}
			else{
				mem[i][j] = true;
				return dp[i][j] = false;
			}
		}
		else if(i < l1 && j >= l2){
			if(s1[i] == 'A'){
				mem[i][j] = true;
				return dp[i][j] = rec(i+1,j,now+1);
			}
			else{
				mem[i][j] = true;
				return dp[i][j] = false;
			}
		}
	}
	else{
		if(i < l1 && j < l2){
			if(s1[i] == 'B' && s2[j] == 'A'){
				mem[i][j] = true;
				return dp[i][j] = rec(i+1,j,now+1);
			}
			else if(s1[i] == 'A' && s2[j] == 'B'){
				mem[i][j] = true;
				return dp[i][j] = rec(i,j+1,now+1);
			}
			else if(s1[i] == 'B' && s2[j] == 'B'){
				mem[i][j] = true;
				return dp[i][j] = (rec(i+1,j,now+1) || rec(i,j+1,now+1));
			}
			else{
				mem[i][j] = true;
				return dp[i][j] = false;
			}
		}
		else if(i>=l1 && j < l2){
			if(s2[j] == 'B'){
				mem[i][j] = true;
				return dp[i][j] = rec(i,j+1,now+1);
			}
			else{
				mem[i][j] = true;
				return dp[i][j] = false;
			}
		}
		else if(i<l1 && j>=l2){
			if(s1[i] == 'B'){
				mem[i][j] = true;
				return dp[i][j] = rec(i+1,j,now+1);
			}
			else{
				mem[i][j] = true;
				return dp[i][j] = false;
			}
		}
		
	}
	mem[i][j] = true;
	return dp[i][j] = false;
}
int main(){
	scanf("%s %s",s1,s2);
	l1 = strlen(s1);
	l2 = strlen(s2);
	length = l1+l2;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		bool ans = rec(0,0,0);
		if(ans){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
		for(int i=0;i<=length;i++){
			memset(dp[i],false,sizeof(dp[i]));
			memset(mem[i],false,sizeof(mem[i]));
		}
	}
	return 0;
}