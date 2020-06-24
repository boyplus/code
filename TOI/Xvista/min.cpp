#include <cstdio>
#include <limits.h>
int arr[110][110];
int main(){
	int m,n,q,r1,c1,r2,c2;
	scanf("%d %d %d",&m,&n,&q);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	while(q--){
		scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
		if(r1 > r2 || c1 > c2){
			printf("INVALID\n");
			continue;
		}
		if(r2 > m){
			r2 = m;
		}
		if(c2 > n){
			c2 = n;
		}
		if(r1 > m || c1 > n || r2 > m || c2 > n){
			printf("OUTSIDE\n");
			continue;
		}
		int max = INT_MIN;
		for(int i=r1;i<=r2;i++){
			for(int j=c1;j<=c2;j++){
				if(arr[i][j] > max){
					max = arr[i][j];
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}