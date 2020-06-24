#include <cstdio>
#include <math.h>
int main(){
	long long prime = 2;
	int n,count=1;
	scanf("%d",&n);
	if(n>=100000){
		prime = 1299709;
		count = 100000;
	}
	if(n>=150000){
		prime = 2015177;
		count = 150000;
	}
	if(n>=200000){
		prime = 2750159;
		count = 200000;
	}
	if(n>=250000){
		prime = 3497861;
		count = 250000;
	}
	if(n>=300000){
		prime = 4256233;
		count = 300000;
	}
	if(n>=350000){
		prime = 5023307;
		count = 350000;
	}
	if(n>=370000){
		prime = 5332519;
		count = 370000;
	}
	if(n>=400000){
		prime = 5800079;
		count = 400000;
	}
	if(n>=430000){
		prime = 6268289;
		count = 430000;
	}
	if(n>=450000){
		prime = 6581963;
		count = 450000;
	}
	if(n>=470000){
		prime = 6895393;
		count = 470000;
	}
	if(n>=480000){
		prime = 7052113;
		count = 480000;
	}
	if(n>=490000){
		prime = 7210759;
		count = 490000;
	}
	while(count <= n){
		bool chk = true;
		float temp = sqrt(prime);
		for(int i=2;i<=temp;++i){
			if(prime %i==0){
				chk = false;
				break;
			}
		}
		if(chk){
			++count;
		}
		if(count <= n){
			++prime;
		}
	}
	printf("%lld\n",prime);
	return 0;
}