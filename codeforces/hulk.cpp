#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		if(i%2){
			printf("I hate that ");
		}
		else{
			printf("I love that ");
		}
	}
	if(n%2){
		printf("I hate it");
	}
	else{
		printf("I love it");
	}
	printf("\n");
	return 0;
}