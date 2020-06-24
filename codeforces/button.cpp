#include <cstdio>
int main(){
	int n,sum=0,count = 1;
	scanf("%d",&n);
	sum = n+1;
	if(n == 1){
		sum--;
	}
	for(int i=n-2;i>=1;i--){
		sum = sum + (i+(count*i))+1;
		count++;
	}
	printf("%d\n",sum);
	return 0;
}