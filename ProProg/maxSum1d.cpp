#include <cstdio>
int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(n == 0){
			return 0;
		}
		bool chk = false;
		int Max = 0,num,sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&num);
			sum = sum+num;
			if(sum > Max){
				Max = sum;
			}
			if(sum < 0){
				sum = 0;
			}
		}
		if(Max > 0){
			printf("The maximum winning streak is %d.\n",Max);
		}
		else{
			printf("Losing streak.\n");
		}
	}
	return 0;
}