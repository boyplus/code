#include <cstdio>
bool wolf[100][100];
int m,n;
long long mem[100][100];
long long Trav(int y,int x){
	if(wolf[y][x]){
		return 0;
	}
	if(y > m || x>n){
		return 0;
	}
	if(y==m && x==n){
		return 1;
	}
	if(mem[y][x]){
		return mem[y][x];
	}
	return mem[y][x] = Trav(y+1,x)+Trav(y,x+1);
}
int main(){
	int k,x,y;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<k;i++){
		scanf("%d %d",&x,&y);
		wolf[y][x] = true;
	}
	long long ans = Trav(1,1);
	printf("%lld\n",ans);
	return 0;
}