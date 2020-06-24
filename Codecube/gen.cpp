#include <cstdio>
int factor(int num){
	int ans = 1,count=0,now=2;
	while(num != 1){
		while(num%now == 0 && num!=0){
			num/=now;
			count++;
		}
		ans = ans *(count+1);
		count=0;
		now++;
	}
	return ans;
}
int main(){
	printf("arr[100001] = {");
	for(int i=1;i<=100000;i++){
		printf("%d,",factor(i));
	}
	return 0;
}