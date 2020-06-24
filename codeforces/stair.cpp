#include <cstdio>
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	if(n < m ){
		printf("-1\n");
		return 0;
	}
	int start = (n+1)/2;
	while(1){
		if(start%m == 0){
			printf("%d\n",start);
			return 0;
		}
		start++;
	}
	printf("-1\n");
	return 0;
}