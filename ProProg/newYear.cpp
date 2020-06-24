#include <cstdio>
int arr[10000000];
int main(){
	int n,t,now=1;
	scanf("%d %d",&n,&t);
	for(int i=1;i<n;i++){
		scanf("%d",&arr[i]);
	}
	while(now != t){
		now = now + arr[now];
		if(now > t){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}