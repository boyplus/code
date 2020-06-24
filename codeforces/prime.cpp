#include <cstdio>
#include <math.h>
bool cc(int num){
	if(num == 0 || num == 1){
		return false;
	}
	float temp = sqrt(num);
	for(int i=2;i<=temp;i++){
		if(num % i == 0){
			return false;
		}
	}
	return true;
}
int main(){
	int count=0;
	//printf("arr[1000000] = {");
	for(int i=1;i<=1000000;i++){
		if(cc(i)){
			count++;
			//printf("%d,",i);
		}
	}
	printf("%d\n",count);
	return 0;
}