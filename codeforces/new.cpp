#include <cstdio>
int main(){
	int n,k,count=0;
	scanf("%d %d",&n,&k);
	int last = 240-k;
	while(last - (5*count)>=0){
		last = last - (5*count);
		count++;
	}
	if(count-1 > n){
		count = n+1;
	}
	printf("%d\n",count-1);
	return 0;
}