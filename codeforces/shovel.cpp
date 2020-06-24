#include <cstdio>
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=10;i++){
		if(n*i%10 == 0 || n*i%10 == k){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}