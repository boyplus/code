#include <cstdio>
int mp[210][210],dp[210][210][2],m,n;
int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
int min(int a,int b){
	if(a<b)
		return a;
	return b;
}
int rec(int y,int x,int index){
	int a = -1,b = -1;
	if(y == m && x == 1){
		return dp[y][x][index] = mp[y][x];
	}
	if(dp[y][x-1][index]){
		a = dp[y][x-1][index];
	}
	else{
		if(x-1 >=1){
			a = dp[y][x-1][index] = rec(y,x-1,index);
		}
	}
	if(dp[y+1][x][index]){
		b = dp[y+1][x][index];
	}
	else{
		if(y+1 <= m){
			b = dp[y+1][x][index] = rec(y+1,x,index);
		}
	}
	if(index == 0){
		return dp[y][x][index] = mp[y][x] + max(a,b);
	}
	else{
		if(a == -1){
			return dp[y][x][index] = mp[y][x] + b;
		}
		else if(b == -1){
			return dp[y][x][index] = mp[y][x] + a;
		}
		if(a == -1 && b == -1){
			dp[y][x][index] = mp[y][x];
		}
		else if(a!=-1 && b!=-1){
			return dp[y][x][index] = mp[y][x] + min(a,b);
		}
	}
	return 0;
}
int main(){
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&mp[i][j]);
		}
	}
	int t1 = rec(1,n,0);
	int t2 = rec(1,n,1);
	printf("%d\n",t1-t2);
	return 0;
}