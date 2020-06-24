#include <cstdio>
#include <math.h>
bool cc(long long num){
	bool chk = true;
	long long count=0,now=2,ans=1;
	while(num != 1){
		count = 0;
		while(num % now == 0 && num != 0){
			num = num / now;
			count++;
			if(count > 3){
				chk = false;
				break;
			}
		}
		ans = ans * (count+1);
		if(ans > 3 || chk == false){
			chk = false;
			break;
		}
		now++;
	}
	if(chk == true && ans == 3){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	long long num = 3;
	for(long long i = 3;i<=100;i++){
		if(cc(i*i)){
			printf("%lld\n",i);
		}
	}
	
	return 0;
}