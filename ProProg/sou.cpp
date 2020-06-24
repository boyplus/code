#include <cstdio>
int cost[600],nItem[30],store[30];
bool chk[30];
int rec(int now){

	return 0;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x,n,a,count=1;
		scanf("%d %d",&x,&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&nItem[i]);
			for(int j=1;j<=nItem[i];j++){
				scanf("%d",&cost[count]);
				store[count] = i;
				count++;
			}
		}
		for(int i=1;i<=count;i++){
			printf("%d ",cost[i]);
		}
		int ans = rec(count);
	}

	return 0;
}