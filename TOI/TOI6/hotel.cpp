#include <cstdio>
int main(){
	int n;
	long long sum = 0;
	scanf("%d",&n);
	while(n>=15){
		n-=15;
		sum+=3000;
	}
	if(n==14 || n==13 || n==12 || n==11 || n==10 || n == 9)
		sum+=3000;
	if(n == 8)
		sum = sum+1500+800+500;
	if(n == 7)
		sum+=2300;
	if(n==6)
		sum+=2000;
	if(n==5 || n==4)
		sum+=1500;
	if(n == 3)
		sum+=1300;
	if(n==2)
		sum+=800;
	if(n==1)
		sum+=500;
	printf("%lld\n",sum);
	return 0;
}