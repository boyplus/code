#include <cstdio>
int main(){
	int count=0;
	for(int i=1;i<=200;i++){
		if(i%4==0 && i%6!=0){
			printf("%d\n",i);
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}