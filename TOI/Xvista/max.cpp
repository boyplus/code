#include <cstdio>
#include <limits.h>
int main(){
	bool chk = false;
	int n,num,sum=0,max = INT_MIN,max2 = INT_MIN;;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		if(num>=0){
			chk = true;
		}
		if(num > max2){
			max2 = num;
		}
		sum+=num;
		if(sum < 0){
			sum = 0;
		}
		if(sum > max){
			max = sum;
		}
	}
	if(chk == false){
		printf("%d\n",max2);
	}
	else{
		printf("%d\n",max);
	}
	return 0;
}