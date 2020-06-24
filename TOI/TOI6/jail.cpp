#include <cstdio>
int id[1000010];
int main(){
	int n,m,now=1;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		id[i] = i;
	}
	int size = n;
	while(size--){
		int count=0;
		while(count < m){
			if(id[now] != -1){
				count++;
			}
			now++;
			if(now > n){
				now = 1;
			}
		}
		now--;
		if(now == 0){
			now = n;
		}
		printf("%d ",id[now]);
		id[now] = -1;
	}
	return 0;
}