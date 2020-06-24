#include <cstdio>
int main(){
	int num;
	while(1){
		scanf("%d",&num);
		int temp = num;
		if(num == 0){
			return 0;
		}
		int now = 2,count = 0;
		while(num > 1){
			bool chk = false;
			while(num%now == 0){
				num = num /now;
				if(chk == false){
					count++;
				}
				chk = true;
			}
			now++;
		}
		printf("%d : %d\n",temp,count);
	}
	return 0;
}