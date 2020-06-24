#include <cstdio>
int main(){
	int n,x,count=0;
	scanf("%d %d",&n,&x);
	for(int i=1;i<=n;i++){
		float temp = (float)x/i;
		if(temp == (int)temp && temp <= n){
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}