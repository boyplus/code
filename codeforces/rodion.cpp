#include <cstdio>
int main(){
	int n,t;
	scanf("%d %d",&n,&t);
	if(n==1 && t==10){
		printf("-1\n");
	}
	else{
		printf("%d",t);
		if(t==10){
			n--;
		}
		for(int i=1;i<n;i++){
			printf("0");
		}
		printf("\n");
	}
	return 0;
}