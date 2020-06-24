#include <cstdio>
int main(){
	int n,num,sum=0,count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		sum+=num;
		if(sum < 0 && num == -1){
			sum = 0;
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}