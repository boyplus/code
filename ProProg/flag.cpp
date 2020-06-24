#include <cstdio>
long long n,ans[100001],count=0;
bool use[10];
void rec(long long now){
	if(now > n){
		bool chk = false;
		for(int i=1;i<=n;i++){
			if((ans[i] == 1 && ans[i+1] == 2) || (ans[i] == 2 && ans[i+1] == 1)){
				chk = true;
				break;
			}
			if(ans[i] == 3 && ans[i+1] == 4 && ans[i+2] == 5){
				chk = true;
				break;
			}
		}
		if(chk == false){
			count++;
			for(int i=1;i<=n;i++){
				printf("%lld ",ans[i]);
			}
			printf("\n");
		}
	}
	else{
		for(int i=1;i<=5;i++){
			if(use[i] == false){
				use[i] = true;
				ans[now] = i;
				rec(now+1);
			}
			use[i] = false;
		}
	}
}
int main(){
	scanf("%lld",&n);
	rec(1);
	printf("count = %lld\n",count);
	return 0;
}